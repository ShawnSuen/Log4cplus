#ifndef ManageLog_STL
#define ManageLog_STL
#include <iostream>
#include <fstream>
#include <deque> 
#include <io.h>
#include <string>
#include <vector>
#include <cstdio>
#include "windows.h"
#include <list>
#include <time.h>
#include <algorithm> 

#include "ManageLog.h"
using namespace std;
/*************************************************************
	* 概述:     在文件夹里创建txt文件
	* 函数名:   CreateLog
	* 属:		
	* 返回值:   str1  
	* 参数列表： 	       参数类型   string          		描述
	*  	       					
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*************************************************************/
std::string ManageLog :: CreateLog() {
	string  str1;
	           // 你要创建文件的路径
	ofstream fout( path );
	if ( fout ) {                       // 如果创建成功
		fout << "str1" << endl;         // 使用与cout同样的方式进行写入
		fout.close();                   // 执行完操作后关闭文件句柄}
	}
	return str1;
};
/*************************************************************
	* 概述:     清除日志文件
	* 函数名:   ClearLog
	* 属:		
	* 返回值:   string
	* 参数列表： 	       参数类型      string      		描述:清除所创建的文件
	*  	       					
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*************************************************************/
std::string ManageLog::ClearLog() {
	ofstream RemoveDirectory(path);
	
	return 0;
};


/*************************************************************
* 概述:     将队列CompleteDeque中的日志内容存进日志文件中
* 函数名:   DequeToFile
* 属性:     public
* 返回值:   int
* 参数列表： 	       参数类型           取值范围描述
* CompleteDeque        deque<string>    时间、等级、日志内容整合在一起的队列
* 版本历史
*1.0  2020/08/28     将队列CompleteDeque中的日志内容存进日志文件.txt中
*************************************************************/
int ManageLog::DequeToFile(deque<string> CompleteDeque)
{
	string strAllData;
	char* path = "..\\logtest.txt"; // 你要创建文件的路径
	ofstream fout(path);
	if (fout)
	{   // 如果创bai建成功	 
		while (!CompleteDeque.empty())
		{
			strAllData = CompleteDeque.back();
			fout << strAllData << endl; // 使用与cout同样的方du式进行写入
			CompleteDeque.pop_back();
			//fout.close(); // 执行完操zhi作后关闭文件句柄
			cout << "写入文件的内容"<<strAllData << endl;
		}
	}	
	return 1;
};



/*************************************************************
	* 概述:     获取文件夹下所有的文件名并将文件名压进队列
	* 函数名:   FileCount
	* 属:		
	* 返回值:   
	* 参数列表： 	       参数类型           		描述
	*  	       					
	* 版本历史
	*1.0 2020/08/     黄宇翔实现功能
	*************************************************************/

std::string ManageLog::ClearLogFile() {
	deque<string> dsFileName;
	cout << "********************" << dsFileName.empty() << endl;
	_finddata_t file;
	string strFirstPath ;
	long lf; string str2;
	//修改这里bai选择路径和要查找的文件类型
	if ((lf = _findfirst("..\\log\\*.txt", &file)) == -1l)
		cout << "文件没有找到!\n";
	else
	{
		do {
			str2 = file.name; dsFileName.push_back(str2);

		} while (_findnext(lf, &file) == 0);
		_findclose(lf);
		//调用排序算法
		FileList();
		while (dsFileName.size() > 2 )
		{
			strFirstPath ="..\\log\\"+ dsFileName.front();
			char pFirstPath[1024];
			strcpy(pFirstPath,strFirstPath.c_str());
			dsFileName.pop_back();
			remove(pFirstPath);
		}
	}return "ss0";
}

//获取指定文件的创建日期，对文件队列进行排序，返回队列，传入的参数：队列


	struct FileInfo
	{
		string     fileName;
		long long  time_write;

		static bool LessThan(FileInfo a, FileInfo b)
		{
			return a.time_write > b.time_write;
		}
	};


	//filePath为文件路径，suffix为后缀名
	char* substr(const char*str, unsigned start, unsigned end)
	{
		unsigned n = end - start;
		static char stbuf[512];
		//复制最后三个字符，即后缀
		strncpy(stbuf, str + start, n);
		//字串最后加上0
		stbuf[n] = 0;
		return stbuf;
	}


	//判断某文件后缀是否为指定格式
	bool decideSuffix(char* filePath, char* suffix)
	{
		char* fileExt;
		char *ptr, c = '.';
		//最后一个出现c的位置
		ptr = strrchr(filePath, c);
		//用指针相减 求得索引
		int pos = ptr - filePath;
		//获取后缀
		fileExt = substr(filePath, pos + 1, strlen(filePath));
		//判断后缀是否相同
		if (0 == strcmp(fileExt, suffix))
			return true;
		else
			return false;
	}


	void getFiles(string path, string suffix, unsigned int minFileByteSize, vector<FileInfo>& files)
	{
		//文件句柄
		long   hFile = 0;
		//文件信息
		struct _finddata_t fileinfo;
		//
		FileInfo tmpFileInfo;
		string p, tmp;
		p = p.assign(path).append("\\*");
		if ((hFile = _findfirst(p.c_str(), &fileinfo)) != -1)
		{
			do
			{
				//如果是目录,迭代之，在这里不想迭代
				if ((fileinfo.attrib &  _A_SUBDIR))
				{
					/*	if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							getFiles(p.assign(path).append("\\").append(fileinfo.name), files);*/
				}
				else//如果是文件
				{
					//判断文件后缀是否符合要求
					if (decideSuffix(fileinfo.name, (char*)suffix.c_str()))
					{
						if (fileinfo.size >= minFileByteSize)
						{
							tmp = tmp.assign(path).append("\\").append(fileinfo.name);
							tmpFileInfo.fileName = tmp;
							tmp = "";
							tmpFileInfo.time_write = fileinfo.time_write;
							files.push_back(tmpFileInfo);
						}
					}
				}
			} while (_findnext(hFile, &fileinfo) == 0);
			_findclose(hFile);
		}
	}

	string ManageLog::FileList() {
	{
		std::string directoryRootPath = "..\\log\\";
		time_t sttime;
		struct tm * tim;
		int sec = 0, min = 0, hour = 0, mday = 0, mon = 0, year = 0;
		time(&sttime);
		tim = localtime(&sttime);
		sec = tim->tm_sec;		   // second (0-61, allows for leap seconds)
		min = tim->tm_min;     // minute (0-59)
		hour = tim->tm_hour;   // hour (0-23)
		mday = tim->tm_mday;   // day of the month (1-31)
		mon = tim->tm_mon + 1; // month (0-11)
		year = tim->tm_year + 1900; // years since 1900
		char newDirectoryName[256] = { 0 };
		memset(newDirectoryName, 0, sizeof(newDirectoryName));
		sprintf(newDirectoryName, "%04d_%02d_%02d", year, mon, mday);

		//最终要查找的目录
		string finalDirectoryPath = directoryRootPath + std::string(newDirectoryName);
		string suffix = "osg";

		vector<FileInfo> filesVec;
		getFiles(finalDirectoryPath, suffix, 60, filesVec);
		//按time_write排序
		std::sort(filesVec.begin(), filesVec.end(), FileInfo::LessThan);
		char str[30];
		int size = filesVec.size();
		for (int i = 0; i < size; i++)
		{
			cout << filesVec[i].fileName.c_str() << endl;
		}

		getchar();

		return "ddd";
	}
	
}
	void ManageLog::DefaultPrint(deque<deque<string>> dDSLogger) {
		for (int i=0;i<dDSLogger.size();i++)
		{
			deque<string> dSLogger= dDSLogger.front();
			dDSLogger.pop_back();
			for (int p=0;p< dSLogger.size();p++)
			{
				cout << dSLogger.front();
				dSLogger.pop_back();
			}
		}
		
	};
#endif