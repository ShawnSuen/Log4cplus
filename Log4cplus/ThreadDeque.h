#ifndef THREADDEQUE_INCLUDE
#define THREADDEQUE_INCLUDE
/*********************************************************************
 *
 *  ��      ��:    ThreadDeque.h   interface for the XXX class.
 *
 *  ��Ȩ����:      Shanghai Baosight Software WYS.
 *
 *  ������	     ���ö��̵߳Ļ����������������ʵ�ֶԶ��н��ж��̵߳�ͬ���ͻ��������
 *               ���д洢������ΪLog��Ҫ��ӡ������      
 *
 *
 *  �汾��ʷ
 *      1.0        2020-8-27    XXXXXX      ������������
 *
*********************************************************************/
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>


#include <condition_variable>
using namespace std;
class ThreadDeque
{
public:
	
/*************************************************************
* ����:      ��Log��Ҫ��ӡ������push������
* ������:   LoggerPushThread()
* ����:     public
* ����ֵ:   void
* �����б� 	       ��������           ȡֵ��Χ����
* strPush              string           log��־push�����е�����
* �汾��ʷ
*1.0  2020/08/27     ��Log��Ҫ��ӡ������push������
*************************************************************/
	void LoggerPushThread(deque<string> dsLogger);




/*************************************************************
	* ����:     ��Log��Ҫ��ӡ������pop������
	* ������:   LoggerPopThread()
	* ����:     public
	* ����ֵ:   string
	* �����б� 	       ��������           ȡֵ��Χ����
	* strNumDeque         deque<string>      ����log��־���ݵĶ���
	* �汾��ʷ
	*1.0  2020/08/27     ��Log��Ҫ��ӡ������pop������
*************************************************************/
	/*string  NumPopThread();*/
	void  LoggerPopThread();

	deque<deque<string>> GetDeque();

};

#endif



