
#include <iostream>
#include "gtest/gtest.h"

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
	string strTime = logger.GetLocalTime();
	EXPECT_NE("", logger.Log(strTime, "Info", "test_GenerateLogger"));
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}