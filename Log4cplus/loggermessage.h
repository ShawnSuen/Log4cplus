/*********************************************************************
 *
 *  文      件:    loggermessage.h
 *
 *  版权所有:      Shanghai Baosight Software Co., Ltd.
 *
 *  概述：	     本文件中声明了LoggerMessage对象，该对象中包括LoggerMessage的
 *			创建时间，等级，声明的文件以及其所在的行数，还有logger所包含的文本
 *			描述等属性。同时还声明了对应的get和set方法。
 *      file path:	     C:\Users\Shawn\Desktop\workspace\Log4cplus\Log4cplus
 *  
 *
 *  版本历史
 *      1.0        2020/08/27    孙港富      创建
 *
*********************************************************************/
#ifndef LOGGER_MESSAGE_INCLUDE
#define LOGGER_MESSAGE_INCLUDE

#include <string>
using namespace std;
class LoggerMessage
{
public:
	/*************************************************************
	* 概述:     设置logger对象的生成时间
	* 函数名:   SetTime
	* 属:		public 
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* strTime 			   string					传入字符串类型的时间，此时间是logger对象编译的时间
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void SetTime(string strTime);

	/*************************************************************
	* 概述:     设置logger对象的等级
	* 函数名:   SetLoggerRank
	* 属:		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* strLoggerRank 	   string					传入logger的等级，包括DEBUG,INFO,WARNING,ERROR    
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void SetLoggerRank(string strLoggerRank);
	
	/*************************************************************
	* 概述:     设置logger对象使用的文件名
	* 函数名:   SetFileWithLogger
	* 属:		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* strFileWithLogger	   string					logger对象使用的文件名
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void SetFileWithLogger(string strFileWithLogger);

	/*************************************************************
	* 概述:     设置logger对象所在的行数 
	* 函数名:   SetLineWithLogger
	* 属:		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* nLineWithLogger    int					传入logger对象所在的行数       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void SetLineWithLogger(int nLineWithLogger);

	/*************************************************************
	* 概述:     设置logger的文本内容
	* 函数名:   SetLoggerCotent
	* 属:		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* strLoggerCotent 	   string					传入logger的文本内容   
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void SetLoggerCotent(string strLoggerContent);

	/*************************************************************
	* 概述:     获取logger对象实例化的时间
	* 函数名:   GetTime
	* 属:		public
	* 返回值:   string m_StrTime: logger对象实例化的时间
	* 参数列表： 	       参数类型           		描述
	*  	       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	string GetTime();

	/*************************************************************
	* 概述:     获取logger对象的等级
	* 函数名:   GetLoggerRank
	* 属:		public
	* 返回值:   string m_StrLoggerRank: logger对象的等级
	* 参数列表： 	       参数类型           		描述
	*  	       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	string GetLoggerRank();

	/*************************************************************
	* 概述:     获取logger对象实例化的文件
	* 函数名:   GetFileWithLogger
	* 属:		public
	* 返回值:   string m_StrFileWithLogger: logger实例化的文件
	* 参数列表： 	       参数类型           		描述
	*  	       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	string GetFileWithLogger();

	/*************************************************************
	* 概述:     获取logger对象实例化的行数
	* 函数名:   GetLineWithLogger
	* 属:		public
	* 返回值:   int m_NLineWithLogger: logger实例化的行数
	* 参数列表： 	       参数类型           		描述
	*  	       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	int GetLineWithLogger();

	/*************************************************************
	* 概述:     获取logger的文本内容
	* 函数名:   GetLoggerContent
	* 属:		public
	* 返回值:   string m_StrLoggerContent: logger的文本内容
	* 参数列表： 	       参数类型           		描述
	*  	       
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	string GetLoggerContent();

private:
	string m_StrTime;
	string m_StrLoggerRank;
	string m_StrFileWithLogger;
	int m_NLineWithLogger;
	string m_StrLoggerContent;

};
#endif
