# Log4cplus
This is a log system developed by the c++.

**日志库需求实现**

1. 设计实现日志库对应的类

   Log类：获取数据方法（日志本地的时间，调用log方法文件名，调用log方法的行号，内容）

   线程类：生产者和消费者模式；多生产者函数进队列，消费者函数取队列。

   数据类：日志生成时间，日志级别，日志行号，日志内容；

   管理类：生成log方法，写入文件的方法，删除过时log文件的方法，判断文件的大小，小于限定值继续在文件写日志，如果大于限定值则新建文件写日志。

2. 实现日志库的功能，

   日志级别：Debug、Info、Error、Warn

   日志生成：判断文件的大小，小于限定值继续在文件写日志，如果大于限定值则新建文件写日志

   日志格式：Log line format: yymmdd hh:mm:ss.uuuuuu [IWEF]threadid file:line] msg
   Example:2020/08/05 19:10:58.370108|INFO|14868|antisway.cpp:24|***********Version: v1.0.0************

   日志异步写入：

   其他功能：支持自定义日志文件路径，支持日志是否输出到标准输出，支持日志是否写入日志文件
   # 接口
   `InitLogger` 读取logger配置文件。
   `DEBUG` 生成一条DEBUG日志。
   `INFO` 生成一条INFO日志。
   `WARNING` 生成一条WARNING日志。
   `ERROR` 生成一条ERROR日志。
   `CloseLogger` 生成多条消费者线程，分别为将缓存区logger数据写入到日志文件中，将缓存区logger数据写到控制台，在logger文件超过数量上限时，对文件进行按照时间顺序删除。
