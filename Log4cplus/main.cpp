
#include <iostream>
#include "gtest/gtest.h"
#pragma warning(disable:4996)
#include "logger.h"
#pragma comment(lib,"gtestd.lib")
using namespace std;

Logger logger;

//���Ի�ȡ����ϵͳʱ���Ƿ�ɹ�
TEST(test_getTime, test_getLocalTime)
{
	EXPECT_NE("ERROR", logger.GetLocalTime());
}

//��������logger���
TEST(test_Logger, test_GernerateLogger)
{
	Info("test");
	string strTime = logger.GetLocalTime();
	logger.Log(strTime, "Info", "test_GenerateLogger");
	EXPECT_NE("", logger.Log(strTime, "Info", "test_GenerateLogger"));
}
//��ͻ

//���Բ����ļ�
TEST(test_Logger, test_FindLoggerFile)
{
	EXPECT_NE(0,logger.FindLogFile("..\\log\\*.txt").size());
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}