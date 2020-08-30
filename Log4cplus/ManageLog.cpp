#ifndef MANAGELOG_STL
#define MANAGELOG_STL
#include <iostream>
#include <fstream>
#include <deque> 
#include <io.h>
#include <string>
#include <vector>
#include <cstdio>
#include <windows.h>
#include <list>
#include <time.h>
#include <algorithm> 
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "../include/Tinyxml/tinyxml.h"
#include "ManageLog.h"
#include "utils.h"
#include "loggermessage.h"
using namespace std;

Utils utils;

LoggerConfig loggerConfig;

/*************************************************************
	* 概述:     在文件夹里创建文件
	* 函数名:   CreateLog
	* 属:		public
	* 返回值:   str1
	* 参数列表： 	       参数类型   string          		描述
	*
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*1.1 2020/08/29	  孙港富对该功能进行了完善
	*************************************************************/
std::string ManageLog::CreateLogFile(string strFilePath) {
	string strFileName = utils.GetLocalSystemTime() + ".txt";

	vector<string> vsFilePath = utils.Split(strFileName, " ");
	vector<string> vsFileNameDate = utils.Split(vsFilePath[0], "-");
	vector<string> vsFileNameTime = utils.Split(vsFilePath[1], ":");
	string strFullFilePath = strFilePath + "/" +
		 vsFileNameDate[0]+ vsFileNameDate[1] + vsFileNameDate[2] +
		vsFileNameTime[0] + vsFileNameTime[1] + vsFileNameTime[2] + vsFileNameTime[3];
	string strOperationMessage;
	ofstream fout(strFullFilePath);

	if (fout) {                       // 如果创建成功
		cout << "****************" << endl;
		cout << "****************" << endl;
		fout.close();                   // 执行完操作后关闭文件句柄
		strOperationMessage = strFullFilePath;
	}
	else
	{
		fout.close();
		strOperationMessage = "fail";
	}
	return strOperationMessage;
};

/*************************************************************
* 概述:     删除Logger文件，保证Logger文件数量的上限为指定数量
* 函数名:   ClearLogFile
* 属:		public
* 返回值:   void
* 参数列表:
* vector<string> vsFileName : 目标文件下的所有文件	       
* 版本历史
* 1.0 		2020/08/29     孙港富实现功能
*************************************************************/
void ManageLog::ClearLogFile(vector<string> vsFileName,int nFileNum)
{
	vector<string> vsSortedFilePath = utils.SortVectorString(vsFileName);
	for (int nIndex = vsSortedFilePath.size();nIndex > nFileNum;nIndex--)
	{
		string strFirstPath = vsSortedFilePath[vsSortedFilePath.size()-nIndex];
		char *p = (char*)strFirstPath.c_str();
		remove(p);
	}
}



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
void ManageLog::DefaultPrint2Console(deque<string> dDSLogger) {
	for (int nIndex = 0; nIndex < dDSLogger.size(); nIndex++)
	{
		cout << dDSLogger[nIndex] << endl;
	}

};


/*************************************************************
* 概述:     获取log配置文件。默认配置文件的路径为 "../config/logconfig.xml"
* 函数名:   GetLoggerConfig
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
LoggerConfig ManageLog::GetLoggerConfig()
{
	map<string, string> m_MLoggerConfig;
	int nLogFileNum;
	string strLogFileSize;
	TiXmlDocument tXmlDoc("../config/logconfig.xml");
	if (!tXmlDoc.LoadFile())
	{
		return loggerConfig;
	}
	else
	{
		TiXmlElement* pRootElement = tXmlDoc.RootElement();
		if (pRootElement->FirstChildElement())
		{
			TiXmlElement* pLogElement = pRootElement->FirstChildElement();
			const char* pcLogElementName = pLogElement->Value();
			const char* pcLogElementValue = pLogElement->GetText();
			m_MLoggerConfig.insert(make_pair(pcLogElementName, pcLogElementValue));
			while (pLogElement)
			{
				const char* pcLogElementName = pLogElement->Value();
				const char* pcLogElementValue = pLogElement->GetText();
				m_MLoggerConfig.insert(make_pair(pcLogElementName, pcLogElementValue));
				pLogElement = pLogElement->NextSiblingElement();
			}
		}
		Utils utils;
		loggerConfig.SetLoggerFilePath(utils.SearchValueInMap(m_MLoggerConfig, "FilePath"));
		loggerConfig.SetLoggerFileSize(utils.SearchValueInMap(m_MLoggerConfig, "FileSize"));
		loggerConfig.SetLoggerNum(atoi(utils.SearchValueInMap(m_MLoggerConfig, "FileNum").c_str()));

		string strOutput2File = utils.SearchValueInMap(m_MLoggerConfig, "Write2File");
		bool bOutput2File;
		istringstream(strOutput2File) >> boolalpha >> bOutput2File;
		loggerConfig.SetOutput2LoggerFile(bOutput2File);
		string strOutput2Console = utils.SearchValueInMap(m_MLoggerConfig, "Write2Console");
		bool bWrite2Console;
		istringstream(strOutput2Console) >> boolalpha >> bWrite2Console;
		loggerConfig.SetOutput2Console(bWrite2Console);
	
		return loggerConfig;
	}
}

/*************************************************************
* 概述:     查找Log文件并将完整路径进行返回
* 函数名:	FindLogFile
* 属:		public
* 返回值:   vector<string> vsFileGroup
* 参数列表： 	       参数类型           		描述
* strFilePath 	       string					想要查找的文件夹路径
* 版本历史
* 1.0 2020/08/29     孙港富实现功能
*************************************************************/
vector<string> ManageLog::FindLogFile(string strFilePath)
{
	vector<string> vsFileGroup; //用来存储目标文件
	string strFullFilePath = strFilePath + "/*.txt";
	const char* to_search = strFullFilePath.c_str();
	long handle;    //用于查找的句柄
	struct _finddata_t fileinfo;    //文件信息的结构体
	handle = _findfirst(to_search, &fileinfo);    //第一次查找
	if (handle != -1) {
		vsFileGroup.push_back(strFilePath + "/" + fileinfo.name);
		while (!_findnext(handle, &fileinfo)) {    //循环查找其它符合的文件，直到找不到其它的为止
			vsFileGroup.push_back(strFilePath + "/" + fileinfo.name);
		}
	}
	_findclose(handle);
	return vsFileGroup;
}


/*************************************************************
* 概述:     将数据缓存区的logger日志写到log文件中
* 函数名:   Write2LogFile
* 属:		public
* 返回值:   void
* 参数列表:
* string strLoggerMessage     将要写入到logger文件中的内容
* 版本历史
* 1.0 		2020/08/29     孙港富实现功能
*************************************************************/
void ManageLog::Write2LogFile(string strFilePath,deque<string> dsLoggerMessage)
{
	ofstream ofsWriteToLFile;
	ofsWriteToLFile.open(strFilePath, ios::app);
	if (!ofsWriteToLFile) //检查文件是否正常打开//不是用于检查文件是否存在
	{
		cout << strFilePath << "无法打开！" << endl;
		abort(); //打开失败，结束程序
	}
	else
	{
		for (int nIndex = 0; nIndex < dsLoggerMessage.size(); nIndex++)
		{
			ofsWriteToLFile << dsLoggerMessage[nIndex] << endl;
		}
		cout << "写入成功" << endl;
		ofsWriteToLFile.close();
	}
}

/*************************************************************
* 概述:     对目标文件组中的文件进行排序，因为Log文件的名字以其
*		创建日期命名，所以可以根据文件名来对文件组进行排序此处期
*		望通过调用c++ 的time.h库来获得文件的创建时间并已得到实现，
*		但是只能获取到第一个文件的信息，需要对此此处的代码进行修
*       改实现对一个容器内所有的文件获取其创建时间
* 函数名:   SortFileByName
* 属:		public
* 返回值:   void
* 参数列表:
* vector<string> vsFileGroup 	 期望排序的目标文件组
* 版本历史
* 1.0 		2020/08/29     孙港富实现功能
*************************************************************/
vector<string> ManageLog::SortFileByName(vector<string> vsFileGroup)
{

	map<string, string> mssFileMapGroup; // 存文件的路径与创建时间
	vector<string> vsFileTimeGroup;	// 存放文件的创建时间

		/*
	for (int nFileGroupIndex = 0; nFileGroupIndex < vsFileGroup.size(); nFileGroupIndex++)
	{


		string stringsss = vsFileGroup[nFileGroupIndex];
		struct stat strusFileBuf;
		const char* strFileName = stringsss.c_str(); // 获取文件的路径并转换为char数组
		int nFileStateResult = stat(strFileName, &strusFileBuf);
		if (!nFileStateResult)
		{
			stringstream ssTimet2StringStream;
			ssTimet2StringStream << time_t(&strusFileBuf.st_ctime);
			string strFileCreateTime;
			strFileCreateTime = ssTimet2StringStream.str();
			mssFileMapGroup.insert(make_pair(strFileCreateTime, vsFileGroup[nFileGroupIndex]));
			vsFileTimeGroup.push_back(strFileCreateTime);
			cout << "**************" << strFileCreateTime << endl;
		}
	}
	*/
	vector<string> vsSortedFileTimeGroup = utils.SortVectorString(vsFileGroup); //已经经过排序的文件时间组
	/*
	vector<string> vsSortedFileGroup;
	for (int nIndex = 0; nIndex < vsSortedFileTimeGroup.size(); nIndex++)
	{
		string strFilePath = utils.SearchValueInMap(mssFileMapGroup, vsSortedFileTimeGroup[nIndex]);
		vsSortedFileGroup.push_back(strFilePath);
	}
	cout << "vss" << vsSortedFileTimeGroup.size() << endl;
	*/
	return vsSortedFileTimeGroup;
}

#endif