#ifndef TEST_STL
#define TEST_STL

#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <gtest/gtest.h>
#include <string>





#include <fstream> // c++ �ļ�IOͷbai
#pragma comment(lib,"gtestd.lib")

#include"../ManageLog.h"
#include "../logger.h"
#include "../ManageLog.h"
#include "../ThreadDeque.h"
#include "../loggermessage.h"

/*
//���Ի�ȡlogger�����ʱ��
TEST(test_LoggerMessage, test_GetTime)
{
	Logger::loggerMessage.SetTime("2020-08-27");
	EXPECT_EQ("2020-08-27", loggerMessage.GetTime());
}

//���Ի�ȡlogger����ĵȼ�
TEST(test_LoggerMessage, test_GetLoggerRank)
{
	loggerMessage.SetLoggerRank("Info");
	EXPECT_EQ("Info", loggerMessage.GetLoggerRank());
}
*/
//���Ի�ȡlogger����ʵ�������ļ�
/*
TEST(test_LoggerMessage, test_GetFileWithLogger)
{
	LoggerMessage loggerMessage;
	loggerMessage.SetFileWithLogger("..\\log\\log.txt");
	EXPECT_EQ("..\\log\\log.txt", loggerMessage.GetFileWithLogger());
}
*/
/*
//���Ի�ȡlogger����ʵ����������
TEST(test_LoggerMessage, test_GetLineWithLogger)
{
	loggerMessage.SetLineWithLogger(20);
	EXPECT_EQ(20, loggerMessage.GetLineWithLogger());
}

TEST(test_LoggerMessage, test_GetLoggerContent)
{
	loggerMessage.SetLoggerCotent("test content");
	EXPECT_EQ("test content", loggerMessage.GetLoggerContent());
}
*/

//
/*
Logger logger;
TEST(test_LoggerMessage, test_GetLoggerContent)
{
	EXPECT_EQ("success", logger.Log("Info", "test"));
}
*/
Logger logger;
int main(int argc,char* argv[])
{

	//�̲߳���
	//ThreadDeque threaddeque;
	//std::thread thread1(&ThreadDeque::NumPushThread, threaddeque,"wangyognsheng");
	//std::thread thread2(&ThreadDeque::NumPushThread, threaddeque, "123");
	//std::thread thread3(&ThreadDeque::NumPopThread, threaddeque);
	//thread1.join();
	//thread2.join();
	//thread3.join();
	
	//ջ�����������ݴ洢��logtest.txt�в���

	//��ʼ��ջstrDataDeque
	//std::deque<string> strDataDeque;  //����һ������
	//std::mutex mu;     //����һ����
	//std::condition_variable cond;//����һ����������
	//	int count = 3;
	//	while (count > 0)
	//	{
	//		string strCount = to_string(count);
	//		std::unique_lock<std::mutex> locker(mu); //����
	//		strDataDeque.push_front(strCount);//3����ѭ��push������
	//		cout << "push�����е�����" << strCount << endl;
	//		locker.unlock();//�ͷ���

	//		cond.notify_one();  // Notify one waiting thread, if there is one.
	//		std::this_thread::sleep_for(std::chrono::seconds(1));
	//		count--;
	//	}
	//	cout << "strDataDeque������" << strDataDeque.size() << endl;
	//    ManageLog ManageLogTest;
	//    ManageLogTest.DequeToFile(strDataDeque);

	logger.Init();
	logger.DEBUG("This is a DEBUG message!");
	logger.INFO("This is a INFO message!");
	logger.WARNING("This is a WARNING message!");	
	logger.ERROR("This is a ERROR messsage!");
	logger.close();
	char* pMessage = "test";

	testing::InitGoogleTest(&argc, argv);
	system("pause");
	return RUN_ALL_TESTS();
}

#endif
