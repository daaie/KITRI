#include <iostream>
#include "readMap.h"

using namespace std;

char imap[20][20];

struct stage sta[50];

void read::read_map(int &maxStage)
{
	int stage_num=1;
	FILE *rfp;

	rfp=fopen("c:\\users\\KITRI\\desktop\\map.txt","r");

	while(!feof(rfp))
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				//sta[stage_num].cpyMap[i][j]=(char)malloc(sizeof(char));
				fscanf(rfp, "%c", &sta[stage_num].cpyMap[i][j]);
				if(sta[stage_num].cpyMap[i][j]=='\n') break;
			}
			if(sta[stage_num].cpyMap[i][0]==';')
			{
				if(stage_num<9)
				{
					stage_num=sta[stage_num].cpyMap[i][2]-48;
					break;
				}
				else if(stage_num>=9)
				{
					stage_num=(sta[stage_num].cpyMap[i][2]-48)*10+(sta[stage_num].cpyMap[i][3]-48);
					break;
				}
				break;
			}
		}
		maxStage++;
	}
	fclose(rfp);

}