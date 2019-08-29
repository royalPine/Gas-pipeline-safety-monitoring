/******************************************************************
	作者：神秘藏宝室
	店铺：ILoveMCU.taobao.com
	最终解释权归原作者所有，鄙视其他店铺不劳而获的抄袭行为！
******************************************************************/
#ifndef __GPS_H__
#define __GPS_H__

#include <reg52.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1

//定义数组长度
#define GPS_Buffer_Length 80
#define UTCTime_Length 11
#define latitude_Length 11
#define N_S_Length 2
#define longitude_Length 12
#define E_W_Length 2 

typedef struct SaveData 
{
	char GPS_Buffer[GPS_Buffer_Length];
	char isGetData;		//是否获取到GPS数据
	char isParseData;	//是否解析完成
	char UTCTime[UTCTime_Length];		//UTC时间
	char latitude[latitude_Length];		//纬度
	char N_S[N_S_Length];		//N/S
	char longitude[longitude_Length];		//经度
	char E_W[E_W_Length];		//E/W
	char isUsefull;		//定位信息是否有效
} xdata _SaveData;



//函数或者变量声明
extern void Uart_Init();
extern void UartPrintf(unsigned char *p);
extern void UartPrintASCII(unsigned char c);
extern void clrStruct();


#define gpsRxBufferLength  76
extern char idata gpsRxBuffer[gpsRxBufferLength];
extern unsigned char RX_Count;
extern _SaveData Save_Data;


#endif