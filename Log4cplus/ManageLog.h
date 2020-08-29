#ifndef MANAGELOG_INCLUDE
#define MANAGELOG_INCLUDE
#include <iostream>
#include <string>
#include <queue>
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
	std::string CreateLogFile(string strFilePath);
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
	std::string ClearLogFile(vector<string> vsFileName);


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

	void Write2LogFile();
};


#endif