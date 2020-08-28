#ifndef MANAGELOG_INCLUDE
#define MANAGELOG_INCLUDE
#include <iostream>
#include <string>
#include "string "
#include <queue>
using namespace std;
class ManageLog
{
public:
	char* path = "C:\\1.txt";
	/*************************************************************
		* 概述:    创建log文件
		* 函数名:   CreateLog
		* 属:	    public
		* 返回值:   string
		* 参数列表： 	       参数类型    string      		描述
		*
		* 版本历史
		*1.0 2020/08/     黄宇翔实现功能
		*************************************************************/
	std::string CreateLog();
	/*************************************************************
		* 概述:     清除日志
		* 函数名:   ClearLog
		* 属:		public
		* 返回值:
		* 参数列表： 	       参数类型           		描述
		*
		* 版本历史
		*1.0 2020/08/     黄宇翔实现功能
		*************************************************************/
	std::string ClearLog();
	/*************************************************************
		* 概述:     判断文件夹下后缀为txt文件的个数
		* 函数名:   FileCount
		* 属:		public
		* 返回值:   文件个数
		* 参数列表： 	       参数类型   int        		描述
		*
		* 版本历史
		*1.0 2020/08/     黄宇翔实现功能
		*************************************************************/
	std::string FileCount();


	/*************************************************************
	* 概述:     将队列CompleteDeque中的日志内容存进日志文件中
	* 函数名:   DequeToFile
	* 属性:     public
	* 返回值:   int
	* 参数列表： 	       参数类型           取值范围描述
	* CompleteDeque        deque<string>    时间、等级、日志内容整合在一起的队列
	* 版本历史
	*1.0  2020/08/28     将队列CompleteDeque中的日志内容存进日志文件中
	*************************************************************/
	int DequeToFile(deque<string> CompleteDeque);
	std::string ClearLogFile();
	std::string FileList();
	void DefaultPrint(deque<deque<string>> dDSLogger);


	/*************************************************************
	* 概述:     获取log配置文件。默认配置文件的路径为 "../log/logconfig.xml"
	* 函数名:   GetLoggerConfig
	* 属:		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	*
	* 版本历史
	*1.0 2020/08/28     孙港富实现功能
	*************************************************************/
	bool GetLoggerConfig();
};


#endif