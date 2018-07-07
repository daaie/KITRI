#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "readMap.h"
#include "control.h"

#define KEY_left 75
#define KEY_right 77
#define KEY_up 72
#define KEY_down 80
#define KEY_q 113
#define KEY_Q 81
#define KEY_enter 13
#define KEY_n 110    

using namespace std;

gameControl control;
read readMap;

void main()
{
	int stage_num=1;
	int maxStage=0;
	readMap.read_map(maxStage);	
	while(1)
	{
		control.start_map(stage_num);
		input=getch();
		while(input!=KEY_Q||input!=KEY_q)
		{
			if(input==KEY_enter||input==KEY_n)
			{
				memcpy(imap, sta[stage_num].cpyMap,sizeof(sta[stage_num].cpyMap));
				system("cls");
				hNum=0;
				control.show_map(stage_num);
				control.game(stage_num);
				if(stage_num>=maxStage) break;
			}
			else break;
		}
		if(stage_num>=maxStage)
		{
		system("cls");
		control.read_ending();
		system("pause");
		}
	}


	//free(sta[50].cpyMap);     //해줄 필요 없음...알아서 푸는듯? ㅎㅎ
}
