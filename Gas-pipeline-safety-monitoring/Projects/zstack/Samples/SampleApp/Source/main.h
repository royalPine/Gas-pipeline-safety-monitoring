/******************************************************************
	���ߣ����زر���
	���̣�ILoveMCU.taobao.com
	���ս���Ȩ��ԭ�������У������������̲��Ͷ���ĳ�Ϯ��Ϊ��
******************************************************************/
#ifndef __MAIN_H__
#define __MAIN_H__

#include <reg52.h>



//�������߱�������
extern void Delay_ms(unsigned int n);

extern void printGpsBuffer();
extern void parseGpsBuffer();
extern void errorLog(int num);


#endif