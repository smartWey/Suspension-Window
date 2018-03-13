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
	//Qt::FramelessWindowHint 无边框  
	//Qt::WindowStaysOnTopHint 窗口在最顶端，不会拖到任务栏下面  
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint | Qt::Tool);
	//设置透明
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
		QMessageBox::about(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("没有动态图文件"));
		return;
	}
	int iDeskHeight = QApplication::desktop()->height() / 15;
	int iDeskWidth = QApplication::desktop()->width() / 10 * 9;

	setGeometry(iDeskWidth, iDeskHeight, iWidth, iHeight);
	QMovie *pm = new QMovie(QString::fromLocal8Bit(strPath.c_str()) + "\\" + qstrPath);//加载jif图片
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
	_pActionMinimize = _pMenu->addAction(QString::fromLocal8Bit("隐藏悬浮窗"));
	_pActionClose = _pMenu->addAction(QString::fromLocal8Bit("退出"));
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
	//记录下鼠标相对于窗口的位置  
	//event->globalPos()鼠标按下时，鼠标相对于整个屏幕位置  
	//pos() this->pos()鼠标按下时，窗口相对于整个屏幕位置  
	mMovePosition = event->globalPos() - pos();
	QMainWindow::mousePressEvent(event);
}

void SuspensionWindow::mouseMoveEvent(QMouseEvent *event)
{
	//(event->buttons() && Qt::LeftButton)按下是左键  
	//鼠标移动事件需要移动窗口，窗口移动到哪里呢？就是要获取鼠标移动中，窗口在整个屏幕的坐标，然后move到这个坐标，怎么获取坐标？  
	//通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标  
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
	_trayIcon->setToolTip(QString::fromLocal8Bit("悬浮窗"));
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
		showMessage("单击");
		break;
	case QSystemTrayIcon::DoubleClick:
		showMessage("双击");
		break;
	default:
		break;
	}
}

void MainWindowIcon::createActions()
{
	_minimizeAction = new QAction(QString::fromLocal8Bit("最小化 (&I)"), this);
	//_maximizeAction = new QAction(QString::fromLocal8Bit("最大化 (&X)"), this);
	_restoreAction = new QAction(QString::fromLocal8Bit("还原 (&R)"), this);
	_quitAction = new QAction(QString::fromLocal8Bit("退出 (&Q)"), this);
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
