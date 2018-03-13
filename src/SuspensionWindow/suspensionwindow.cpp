#include "suspensionwindow.h"
#include <QtGui/QMouseEvent>
#include <QMovie>
#include <QSettings>
#include <QMessageBox>
#include <QDesktopWidget>
#include "GlobalFun.h"
SuspensionWindow* g_SuspensionWindow;
MainWindowIcon* g_MainWindowIcon;

SuspensionWindow::SuspensionWindow(QWidget *parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);
	g_SuspensionWindow = this;
	mMoveing = false;
	//Qt::FramelessWindowHint �ޱ߿�  
	//Qt::WindowStaysOnTopHint ��������ˣ������ϵ�����������  
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint | Qt::Tool);
	//����͸��
	setAttribute(Qt::WA_TranslucentBackground, true);
	std::string strPath = Sinfotek::getExeFloder();
	QSettings setting(QString::fromLocal8Bit(strPath.c_str()) + "\\config.ini", QSettings::IniFormat);
	int iHeight = setting.value("WINDOW/Height").toInt();
	int iWidth = setting.value("WINDOW/Width").toInt();
	if (iHeight == 0 || iWidth == 0)
	{
		iHeight = 100;
		iWidth = 100;
	}
	QString qstrPath = setting.value("WINDOW/FilePath").toString().toLocal8Bit();
	if (qstrPath == "")
	{
		QMessageBox::about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("û�ж�̬ͼ�ļ�"));
		return;
	}
	int iDeskHeight = QApplication::desktop()->height() / 15;
	int iDeskWidth = QApplication::desktop()->width() / 10 * 9;

	setGeometry(iDeskWidth, iDeskHeight, iWidth, iHeight);
	QMovie *pm = new QMovie(QString::fromLocal8Bit(strPath.c_str()) + "\\" + qstrPath);//����jifͼƬ
	ui.label->setMovie(pm);
	pm->start();

	_pLabel = new QLabel(ui.label);
	int iX = setting.value("Text/x").toInt();
	int iY = setting.value("Text/y").toInt();
	_pLabel->setGeometry(iX, iY, iWidth, 30);
	_pLabel->setAlignment(Qt::AlignHCenter);
	QString strRed = setting.value("Text/Red").toString();
	QString strGreen = setting.value("Text/Green").toString();
	QString strBlue = setting.value("Text/Blue").toString();
	int iSize = setting.value("Text/Size").toInt();
	QFont font;
	font.setStyleName("Bold");
	font.setPointSize(iSize);
	_pLabel->setFont(font);
	QString qstrSty = "color:rgb(";
	qstrSty += strRed;
	qstrSty += ", ";
	qstrSty += strGreen;
	qstrSty += ", ";
	qstrSty += strBlue;
	qstrSty += ")";
	_pLabel->setStyleSheet(qstrSty);
	//QHBoxLayout* hbox = new QHBoxLayout(ui.label);
	//hbox->addWidget(_pLabel);
	//ui.label->setLayout(hbox);
	
	_pMenu = new QMenu(this);
	_pActionMinimize = _pMenu->addAction(QString::fromLocal8Bit("����������"));
	_pActionClose = _pMenu->addAction(QString::fromLocal8Bit("�˳�"));
	connect(_pActionMinimize, SIGNAL(triggered(bool)), this, SLOT(onHideActionClicked()));
	connect(_pActionClose, SIGNAL(triggered()), this, SLOT(onExitActionClicked()));
	connect(this, SIGNAL(rightClicked()), this, SLOT(showMenu()));

	_pStatisticsThread = new StatisticsThread(this);
	connect(_pStatisticsThread, SIGNAL(statisticeCount(int)), this, SLOT(showStatisticsCount(int)));
	_pStatisticsThread->start();

}

SuspensionWindow::~SuspensionWindow()
{

}

void SuspensionWindow::mousePressEvent(QMouseEvent *event)
{
	mMoveing = true;
	//��¼���������ڴ��ڵ�λ��  
	//event->globalPos()��갴��ʱ����������������Ļλ��  
	//pos() this->pos()��갴��ʱ�����������������Ļλ��  
	mMovePosition = event->globalPos() - pos();
	QMainWindow::mousePressEvent(event);
}

void SuspensionWindow::mouseMoveEvent(QMouseEvent *event)
{
	//(event->buttons() && Qt::LeftButton)���������  
	//����ƶ��¼���Ҫ�ƶ����ڣ������ƶ��������أ�����Ҫ��ȡ����ƶ��У�������������Ļ�����꣬Ȼ��move��������꣬��ô��ȡ���ꣿ  
	//ͨ���¼�event->globalPos()֪��������꣬��������ȥ�������ڴ���λ�ã����Ǵ�����������Ļ������  
	if (mMoveing && (event->buttons() && Qt::LeftButton)
		&& (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - mMovePosition);
		mMovePosition = event->globalPos() - pos();
	}
	QMainWindow::mouseMoveEvent(event);
}

void SuspensionWindow::mouseReleaseEvent(QMouseEvent *event)
{
	mMoveing = false;
	if ((event->button() == Qt::RightButton))
	{
		emit rightClicked();
	}
}

void SuspensionWindow::showMenu()
{
	QCursor cur = this->cursor();
	_pMenu->exec(cur.pos());
}

void SuspensionWindow::onExitActionClicked()
{
	g_MainWindowIcon->onQuit();
}

void SuspensionWindow::onHideActionClicked()
{
	hide();
}

void SuspensionWindow::showStatisticsCount(int count)
{
	_pLabel->setText(QString::number(count));
}

MainWindowIcon::MainWindowIcon()
{
	g_MainWindowIcon = this;
	QIcon icon = QIcon(":/SuspensionWindow/ExeIco.ico");
	setWindowIcon(icon);
	_trayIcon = new QSystemTrayIcon(this);
	_trayIcon->setIcon(icon);
	_trayIcon->setToolTip(QString::fromLocal8Bit("������"));
	createActions();
	_trayIcon->show();
	connect(_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
	connect(_minimizeAction, SIGNAL(triggered()), this, SLOT(Minsize()));
	//connect(_maximizeAction, SIGNAL(triggered()), this, SLOT(MaxRestore()));
	connect(_restoreAction, SIGNAL(triggered()), this, SLOT(MaxRestore()));
	connect(_quitAction, SIGNAL(triggered()), this, SLOT(onQuit()));
}

MainWindowIcon::~MainWindowIcon()
{

}

void MainWindowIcon::showMessage(char *msg)
{
	g_SuspensionWindow->show();
}

void MainWindowIcon::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger:
		showMessage("����");
		break;
	case QSystemTrayIcon::DoubleClick:
		showMessage("˫��");
		break;
	default:
		break;
	}
}

void MainWindowIcon::createActions()
{
	_minimizeAction = new QAction(QString::fromLocal8Bit("��С�� (&I)"), this);
	//_maximizeAction = new QAction(QString::fromLocal8Bit("��� (&X)"), this);
	_restoreAction = new QAction(QString::fromLocal8Bit("��ԭ (&R)"), this);
	_quitAction = new QAction(QString::fromLocal8Bit("�˳� (&Q)"), this);
	_trayIconMenu = new QMenu(this);
	_trayIconMenu->addAction(_minimizeAction);
	//_trayIconMenu->addAction(_maximizeAction);
	_trayIconMenu->addAction(_restoreAction);
	_trayIconMenu->addAction(_quitAction);
	_trayIcon->setContextMenu(_trayIconMenu);
}

void MainWindowIcon::MaxRestore()
{
	g_SuspensionWindow->show();
}

void MainWindowIcon::Minsize()
{
	g_SuspensionWindow->hide();
}

void MainWindowIcon::onQuit()
{
	QApplication::quit();
}
