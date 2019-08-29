/******************************************************************
	作者：神秘藏宝室
	店铺：ILoveMCU.taobao.com
	最终解释权归原作者所有，鄙视其他店铺不劳而获的抄袭行为！
******************************************************************/
#ifndef __MAIN_H__
#define __MAIN_H__

#include <reg52.h>



//函数或者变量声明
extern void Delay_ms(unsigned int n);

extern void printGpsBuffer();
extern void parseGpsBuffer();
extern void errorLog(int num);


#endif