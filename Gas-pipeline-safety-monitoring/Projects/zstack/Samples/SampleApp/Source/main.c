/******************************************************************
	���ߣ����زر���
	���̣�ILoveMCU.taobao.com
	���ս���Ȩ��ԭ�������У������������̲��Ͷ���ĳ�Ϯ��Ϊ��
******************************************************************/
#include "main.h"
#include "uart.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�������


//****************************************************
//������
//****************************************************
void main()
{
	unsigned char i = 0;
	Uart_Init();
	Delay_ms(10);

	UartPrintf("Welcome to use!");
	UartPrintf("ILoveMCU.taobao.com");

	clrStruct();	//��ջ�������


	while(1)
	{
		parseGpsBuffer();
		printGpsBuffer();
	}
}


void errorLog(int num)
{
	
	while (1)
	{
	  	UartPrintf("ERROR");
		UartPrintASCII(num+0x30);
		UartPrintf("\r\n");
	}
}

void parseGpsBuffer()
{
	char *subString;
	char *subStringNext;
	char i = 0;
	if (Save_Data.isGetData)
	{
		Save_Data.isGetData = false;
		UartPrintf("**************\r\n");
		UartPrintf(Save_Data.GPS_Buffer);

		
		for (i = 0 ; i <= 6 ; i++)
		{
			if (i == 0)
			{
				if ((subString = strstr(Save_Data.GPS_Buffer, ",")) == NULL)
					errorLog(1);	//��������
			}
			else
			{
				subString++;
				if ((subStringNext = strstr(subString, ",")) != NULL)
				{
					char usefullBuffer[2]; 
					switch(i)
					{
						case 1:memcpy(Save_Data.UTCTime, subString, subStringNext - subString);break;	//��ȡUTCʱ��
						case 2:memcpy(usefullBuffer, subString, subStringNext - subString);break;	//��ȡUTCʱ��
						case 3:memcpy(Save_Data.latitude, subString, subStringNext - subString);break;	//��ȡγ����Ϣ
						case 4:memcpy(Save_Data.N_S, subString, subStringNext - subString);break;	//��ȡN/S
						case 5:memcpy(Save_Data.longitude, subString, subStringNext - subString);break;	//��ȡ������Ϣ
						case 6:memcpy(Save_Data.E_W, subString, subStringNext - subString);break;	//��ȡE/W

						default:break;
					}

					subString = subStringNext;
					Save_Data.isParseData = true;
					if(usefullBuffer[0] == 'A')
						Save_Data.isUsefull = true;
					else if(usefullBuffer[0] == 'V')
						Save_Data.isUsefull = false;

				}
				else
				{
					errorLog(2);	//��������
				}
			}


		}
	}
}

void printGpsBuffer()
{
	if (Save_Data.isParseData)
	{
		Save_Data.isParseData = false;
		
		UartPrintf("Save_Data.UTCTime = ");
		UartPrintf(Save_Data.UTCTime);
		UartPrintf("\r\n");

		if(Save_Data.isUsefull)
		{
			Save_Data.isUsefull = false;
			UartPrintf("Save_Data.latitude = ");
			UartPrintf(Save_Data.latitude);
			UartPrintf("\r\n");


			UartPrintf("Save_Data.N_S = ");
			UartPrintf(Save_Data.N_S);
			UartPrintf("\r\n");

			UartPrintf("Save_Data.longitude = ");
			UartPrintf(Save_Data.longitude);
			UartPrintf("\r\n");

			UartPrintf("Save_Data.E_W = ");
			UartPrintf(Save_Data.E_W);
			UartPrintf("\r\n");
		}
		else
		{
			UartPrintf("GPS DATA is not usefull!\r\n");
		}
		
	}
}

//****************************************************
//MS��ʱ����
//****************************************************
void Delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}