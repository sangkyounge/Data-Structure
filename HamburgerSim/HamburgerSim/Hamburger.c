#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CirCularQueue.h"

#define CUS_COME_TERM 15


#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void)
{
	int makeProc = 0; //햄버거 제작 진행상황
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	//for문의 1회 회전은 1초의 시간 흐름

	for (int sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3) //결과를 3개로(0,1,2)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder += 1;
				break;

			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder += 1;
				break;

			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}
		if (makeProc <= 0 && !QIsEmpty(&que))
			makeProc = Dequeue(&que);
		
		makeProc--;
	}
	printf("시뮬레이션 결과");
	printf("치즈버거 %d\n", cheOrder);
	printf("불고기버거 %d\n", bulOrder);
	printf("더블버거 %d\n", dubOrder);
	printf("웨이팅 룸 크기 %d\n", QUE_LEN);
	return 0;

}