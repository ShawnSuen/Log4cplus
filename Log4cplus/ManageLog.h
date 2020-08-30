#ifndef MANAGELOG_INCLUDE
#define MANAGELOG_INCLUDE
#include <iostream>
#include <string>
#include <queue>

#include "loggermessage.h"

using namespace std;
class ManageLog
{
public:
	/*************************************************************
	* 概述:    创建log文件
	* 函数名:   CreateLog
	* 属:	    public
	* 返回值:   string
	* 参数列表： 	       参数类型    string      		描述
	*
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*1.1 2020/08/29	  孙港富对该功能进行了完善
	*************************************************************/
	string CreateLogFile(string strFilePath);

	/*************************************************************
	* 概述:     清除日志
	* 函数名:   ClearLogFile
	* 属:		public
	* 返回值:
	* 参数列表： 	       参数类型           		描述
	*
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*************************************************************/
	void ClearLogFile(vector<string> vsFileName,int nFileNum);

	/*************************************************************
	* 概述:     默认输出方式(输出到控制台)
	* 函数名:   DefaultPrint
	* 属:		public
	* 返回值:   void
	* 参数列表:
	* deque<string>  dDSLogger 	 目标输出的Logger队列
	* 版本历史
	* 1.0 		2020/08/29     孙港富实现功能
	*************************************************************/
	void DefaultPrint2Console(deque<string> dDSLogger);


	/*************************************************************
	* 概述:     获取log配置文件。默认配置文件的路径为 "../log/logconfig.xml"
	* 函数名:   GetLoggerConfig
	* 属:		public
	* 返回值:   LoggerConfig loggerConfig	返回LoggerConfig 对象
	* 参数列表： 	       参数类型           		描述
	*
	* 版本历史
	*1.0 2020/08/28     孙港富实现功能
	*************************************************************/
	LoggerConfig GetLoggerConfig();

	/*************************************************************
	* 概述:     查找Log文件并将完整路径进行返回
	* 函数名:	FindLogFile
	* 属:		public
	* 返回值:   vector<string> vsFilePath
	* 参数列表： 	       参数类型           		描述
	* strFilePath 	       string					想要查找的文件夹路径
	* 版本历史
	* 1.0 2020/08/29     孙港富实现功能
	*************************************************************/
	vector<string> FindLogFile(string strFilePath);

	vector<string> SortFileByName(vector<string> vsFileGroup);

	/*************************************************************
	* 概述:     将缓存区的logger数据写到logger文件中
	* 函数名:   Write2LogFile
	* 属:		public
	* 返回值:   void
	* 参数列表:
	* string strFilePath 	       
	* 版本历史
	* 1.0 		2020/08/30     孙港富实现功能
	*************************************************************/
	void Write2LogFile(string strFilePath,deque<string> dsLoggerMessage);
};


#endif