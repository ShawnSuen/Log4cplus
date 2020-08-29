#ifndef THREADDEQUE_INCLUDE
#define THREADDEQUE_INCLUDE

#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

#include "loggermessage.h"
#include "ManageLog.h"
using namespace std;
class ThreadManager
{
	ManageLog manageLog;
	LoggerConfig g_loggerConfig;
public:

	LoggerConfig ReadLoggerManager();
	void WriteLogger2File(deque<string> dsLoggerMessage);
	void WriteLogger2Console(deque<string> dsLoggerMessage);
	void ClearLogFile();

};

#endif



