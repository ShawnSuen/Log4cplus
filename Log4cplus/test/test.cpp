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
#include <thread>

#include <fstream> // c++ 文件IO头bai
#pragma comment(lib,"gtestd.lib")

#include "../logger.h"
#include "../ManageLog.h"
#include "../loggermessage.h"


/*
//测试获取logger对象的时间
TEST(test_LoggerMessage, test_GetTime)
{
	Logger::loggerMessage.SetTime("2020-08-27");
	EXPECT_EQ("2020-08-27", loggerMessage.GetTime());
}

//测试获取logger对象的等级
TEST(test_LoggerMessage, test_GetLoggerRank)
{
	loggerMessage.SetLoggerRank("Info");
	EXPECT_EQ("Info", loggerMessage.GetLoggerRank());
}
*/
//测试获取logger对象实例化的文件
/*
TEST(test_LoggerMessage, test_GetFileWithLogger)
{
	LoggerMessage loggerMessage;
	loggerMessage.SetFileWithLogger("..\\log\\log.txt");
	EXPECT_EQ("..\\log\\log.txt", loggerMessage.GetFileWithLogger());
}
*/
/*
//测试获取logger对象实例化的行数
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
//Logger logger;
//
//void testsss()
//{
//	logger.DEBUG("This is a DEBUG message!");
//}
//
//void testssss()
//{
//	logger.INFO("This is a INFO message!");
//}

//ManageLog manageLog;
/*
TEST(test_ManageLog, test_GetLogConfig)
{

	EXPECT_EQ(true, manageLog.GetLoggerConfig());
}

TEST(test_ManageLog, test_CreateFile)
{
	EXPECT_EQ("success", manageLog.CreateLogFile("../log"));
}
*/
Logger logger;
void test1(int i)
{
	for (int i = 0; i < 1000; i++)
	{
		logger.INFO("This is INFO test!");
	}
}
void test2(int i)
{
	for (int i = 0; i < 1000; i++)
	{
		logger.DEBUG("This is DEBUG test!");
	}
}
int main(int argc,char* argv[])
{
	logger.InitLogger();
	//线程测试
	//ThreadDeque threaddeque;
	//std::thread thread1(&ThreadDeque::NumPushThread, threaddeque,"wangyognsheng");
	//std::thread thread2(&ThreadDeque::NumPushThread, threaddeque, "123");
	//std::thread thread3(&ThreadDeque::NumPopThread, threaddeque);
	//thread1.join();
	//thread2.join();
	//thread3.join();
	
	//栈中完整的内容存储到logtest.txt中测试

	//初始化栈strDataDeque
	//std::deque<string> strDataDeque;  //定义一个队列
	//std::mutex mu;     //定义一个锁
	//std::condition_variable cond;//定义一个条件变量
	//	int count = 3;
	//	while (count > 0)
	//	{
	//		string strCount = to_string(count);
	//		std::unique_lock<std::mutex> locker(mu); //上锁
	//		strDataDeque.push_front(strCount);//3个数循环push进队列
	//		cout << "push进队列的数：" << strCount << endl;
	//		locker.unlock();//释放锁

	//		cond.notify_one();  // Notify one waiting thread, if there is one.
	//		std::this_thread::sleep_for(std::chrono::seconds(1));
	//		count--;
	//	}
	//	cout << "strDataDeque的数量" << strDataDeque.size() << endl;
	//    ManageLog ManageLogTest;
	//    ManageLogTest.DequeToFile(strDataDeque);
	/*

	logger.DEBUG("This is a DEBUG message!");
	logger.INFO("This is a INFO message!");
	logger.WARNING("This is a WARNING message!");	
	logger.ERROR("This is a ERROR messsage!");

	char* pMessage = "test";
	*/



		thread t(test1,0);
		t.join();

		thread t1(test1, 0);
		t1.join();

		thread t22(test2, 0);
		t22.join();
		thread t23(test2, 0);
		t23.join();
		thread t2(test1, 0);
		t2.join();

		thread t3(test1, 0);
		t3.join();

		thread t4(test1, 0);
		t4.join();

		thread t5(test1, 0);
		t5.join();

		thread t6(test1, 0);
		t6.join();

		thread t7(test1, 0);
		t7.join();

		thread t8(test1, 0);
		t8.join();

		thread t9(test1, 0);
		t9.join();

		thread t0(test1, 0);
		t0.join();

		thread t11(test2, 0);
		t11.join();


		thread t33(test2, 0);
		t33.join();
		thread t44(test2, 0);
		t44.join();

		thread t55(test2, 0);
		t55.join();

		thread t66(test2, 0);
		t66.join();

		thread t77(test2, 0);
		t77.join();
		thread t88(test2, 0);

		t88.join();
		thread t99(test2, 0);
		t99.join();


	//cout << logger.g_DSLoggerMessage.size() << endl;
	//manageLog.Write2LogFile(logger.g_DSLoggerMessage);
	//
	//manageLog.DefaultPrint2Console(logger.g_DSLoggerMessage);

	//vector<string> vs = manageLog.FindLogFile("../log");
	////manageLog.ClearLogFile();


	logger.InitLogger();
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	//logger.CloseLogger();
	logger.CloseLogger();
	return 0;
}

#endif
