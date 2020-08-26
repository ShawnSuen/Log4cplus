
#include <iostream>
#include "gtest/gtest.h"

#include "logger.h"
#pragma comment(lib,"gtestd.lib")
using namespace std;

Logger logger;

//测试获取本地系统时间是否成功
TEST(test_getTime, test_getLocalTime)
{
	EXPECT_NE("ERROR", logger.getLocalTime());
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}