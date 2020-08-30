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

	/*************************************************************
	* 概述:     读取Logger配置文件，并将读取到的信息封装到对象内
	* 函数名:   ReadLoggerManager
	* 属:		public
	* 返回值:   LoggerConfig m_LoggerConfig
	* 参数列表:
	*
	* 版本历史
	* 1.0 		2020/08/30     孙港富实现功能
	*************************************************************/
	LoggerConfig ReadLoggerManager();

	/*************************************************************
	* 概述:     将logger日志写入到logger文件
	* 函数名:   WriteLogger2File
	* 属:		public
	* 返回值:   void
	* 参数列表:
	* deque<string> dsLoggerMessage: 写入控制台的目标队列
	* 版本历史
	* 1.0 		2020/08/30     孙港富实现功能
	*************************************************************/
	void WriteLogger2File(deque<string> dsLoggerMessage);

	/*************************************************************
	* 概述:     将logger日志输出到控制台的线程
	* 函数名:   WriteLogger2Console
	* 属:		public
	* 返回值:   void
	* 参数列表:
	* deque<string> dsLoggerMessage: 写入控制台的目标队列
	* 版本历史
	* 1.0 		2020/08/31     孙港富实现功能
	*************************************************************/
	void WriteLogger2Console(deque<string> dsLoggerMessage);

	/*************************************************************
	* 概述:     清理log文件，保持log文件数量在期望的数量
	* 函数名:   ClearLogFile
	* 属:		public
	* 返回值:   void
	* 参数列表:
	*
	* 版本历史
	* 1.0 		2020/08/31     孙港富实现功能
	*************************************************************/
	void ClearLogFile();

};

#endif



