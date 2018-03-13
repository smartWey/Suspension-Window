#ifndef STATISTICSTHREAD_H
#define STATISTICSTHREAD_H

#include <QThread>

class StatisticsThread : public QThread
{
	Q_OBJECT

public:
	StatisticsThread(QObject *parent);
	~StatisticsThread();

	void run();
	std::string GetKeyName(int NumKey);
	bool JudgeShift();
	int getSpaceCount();
	int getEnterCount();

signals:
	void statisticeCount(int count);

private:
	int _iSpaceCount;
	int _iEnterCount;
	
};

#endif // STATISTICSTHREAD_H
