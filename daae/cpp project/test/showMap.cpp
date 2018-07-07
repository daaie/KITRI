#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include "readMap.h"
#include "control.h"
#include "showMap.h"
using namespace std;

/*---------------------------------*/
int hNum=0;
int pos_x=0, pos_y=0;
/*---------------------------------*/

gameControl go;

void draw::show_map(int &stage_num)
{
	for(int j=0;j<20;j++)
	{
		for(int k=0;k<20;k++)
		{
			if(imap[j][k]=='#') cout<<"▩";
			else if(imap[j][k]=='.') 
			{
				cout<<"◎";
				hNum++;
				//   cout<<"hnum= "<<hNum;
			}
			else if(imap[j][k]=='$') cout<<"●";
			else if(imap[j][k]=='@') 
			{
				pos_x=k;
				pos_y=j;
				cout<<"  ";
			}
			else if(imap[j][k]==' ') cout<<"  ";
			else if(imap[j][k]=='\n') cout<<"\n";
			else if(imap[j][k]=='!') 
			{
				cout<<"●";
				hNum++;
			}
			else break;
		}
	}

}

void draw::stage_acc(int stage_num, int count)
{
	go.position_xy(15,4);
	cout<<"stage : "<<stage_num<<endl;
	go.position_xy(15,5);
	cout<<"이동횟수 : "<<count<<endl;
	go.position_xy(2,12);
	cout<<"┎━━━━━━━━┒"<<endl;
	go.position_xy(2,13);
	cout<<"┃다시하기 : 엔터 ┃"<<endl;
	go.position_xy(2,14);
	cout<<"┃다음 단계 : n   ┃"<<endl;
	go.position_xy(2,15);
	cout<<"┃나가기 : q      ┃"<<endl;
	go.position_xy(2,16);
	cout<<"┗━━━━━━━━┚"<<endl;
}

void draw::textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}


void draw::read_ending()
{
	//FILE *rfp;
	//rfp=fopen("c:\\users\\KITRI\\desktop\\ending.txt","r");
	//int i=0;
	//while(!feof(rfp))
	//{

	//	for(int j=0;j<50;j++)
	//	{
	//		fscanf(rfp,"%c",&end[i][j]);
	//		cout<<end[i][j];
	//		if(end[i][j]=='\n') 
	//		{
	//			break;
	//		}
	//		if(i==19) {
	//			cout<<endl; 
	//			return;
	//		} 
	//	}
	//	i++;

	//}
	//fclose(rfp);
	cout<<endl;
	cout<<"      ■■■■■■■■■■■■"<<endl;
	cout<<"                ■          ■"<<endl;
	cout<<"                ■          ■"<<endl;
	cout<<"                ■          ■"<<endl;
	cout<<"   ■■■■■■■■■■■■■■■"<<endl;
	cout<<endl;
	cout<<"      ■■■■■■■■■■■■■"<<endl;
	cout<<"      ■"<<endl;
	cout<<"      ■"<<endl;
	cout<<"      ■■■■■■■■■■■■■"<<endl;
	cout<<"      ■"<<endl;
	cout<<"      ■"<<endl;
	cout<<"      ■■■■■■■■■■■■■"<<endl;
}
