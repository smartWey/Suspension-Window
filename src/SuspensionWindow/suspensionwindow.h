#ifndef SUSPENSIONWINDOW_H
#define SUSPENSIONWINDOW_H

#include "ui_suspensionwindow.h"
#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include "StatisticsThread.h"

class SuspensionWindow : public QMainWindow
{
	Q_OBJECT

public:
	SuspensionWindow(QWidget *parent = 0);
	~SuspensionWindow();

signals:
	void rightClicked();

public slots:
	void onExitActionClicked();
	void onHideActionClicked();
	void showMenu();
	void showStatisticsCount(int count);

private:
	bool        mMoveing;
	QPoint      mMovePosition;
	QMenu*		_pMenu;
	QAction*	_pActionClose;
	QAction*	_pActionMinimize;
	StatisticsThread* _pStatisticsThread;
	QLabel* _pLabel;

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

private:
	Ui::SuspensionWindowClass ui;
};

class MainWindowIcon :public SuspensionWindow
{
	Q_OBJECT
public:
	MainWindowIcon();
	~MainWindowIcon();

private:
	void showMessage(char *msg);
	void createActions();

public slots:
	void onQuit();

private:
	QSystemTrayIcon* _trayIcon;
	char* _chmsg;
	QAction* _minimizeAction;
	QAction* _maximizeAction;
	QAction* _restoreAction;
	QAction* _quitAction;
	QMenu* _trayIconMenu;

	private slots:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void MaxRestore();
	void Minsize();
};

#endif // SUSPENSIONWINDOW_H
