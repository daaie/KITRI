#include <iostream>
#include <windows.h>
#include <conio.h>
#include "control.h"
#include "readMap.h"

#define KEY_left 75
#define KEY_right 77
#define KEY_up 72
#define KEY_down 80
#define KEY_q 113
#define KEY_Q 81
#define KEY_enter 13
#define KEY_n 110

using namespace std;
/*----------------------------*/
int input=0;
int hNum=0;
/*----------------------------*/

void gameControl::position_xy(int x,int y)
{
	COORD pos ={x*2,y};       
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void gameControl::start_map(int &stage_num)
{
	system("cls");
	position_xy(5,12);
	cout<<"스테이지를 고르세요 [1 - 30] : ";
	cin>>stage_num;
	position_xy(5,15);
	cout<<"게임을 시작하려면 엔터"<<endl;
	position_xy(5,16);
	cout<<"스테이지를 다시 고르려면 아무거나 누르세요"<<endl;
}

void gameControl::show_map(int &stage_num)
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

void gameControl::stage_acc(int stage_num, int count)
{
	position_xy(15,4);
	cout<<"stage : "<<stage_num<<endl;
	position_xy(15,5);
	cout<<"이동횟수 : "<<count<<endl;
	position_xy(2,12);
	cout<<"┎━━━━━━━━┒"<<endl;
	position_xy(2,13);
	cout<<"┃다시하기 : 엔터 ┃"<<endl;
	position_xy(2,14);
	cout<<"┃다음 단계 : n   ┃"<<endl;
	position_xy(2,15);
	cout<<"┃나가기 : q      ┃"<<endl;
	position_xy(2,16);
	cout<<"┗━━━━━━━━┚"<<endl;
}

void gameControl::textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}



void gameControl::control()
{
	switch(input)
	{
	case KEY_left : pos_x-=1;
		break;
	case KEY_right :pos_x+=1;
		break;
	case KEY_up :   pos_y-=1;
		break;
	case KEY_down : pos_y+=1;
		break;
	default : break;
	}
}

void gameControl::game(int &stage_num)
{

	while(1)
	{
		int cNum=0;
		int x,x2,y,y2;
		stage_acc(stage_num, count);
		x=pos_x;
		y=pos_y;
		position_xy(pos_x,pos_y);
		cout<<"♡";
		input=getch();
		if(input==KEY_left||
			input==KEY_right||
			input==KEY_up||
			input==KEY_down) count++;

		control();

		if(input==KEY_n)
		{
			stage_num++;
			count=0;
			return;
		}
		else if(input==KEY_Q || input==KEY_q || input==KEY_enter)
		{
			count=0;
			return;
		}

		if(imap[pos_y][pos_x]=='@') imap[pos_y][pos_x]=' ';	

		if(imap[y][x]=='.')
		{
			position_xy(x,y);
			cout<<"◎";
		}
		else if(imap[y][x]=='!')
		{
			position_xy(x,y);
			cout<<"◎";
		}
		else
		{
			position_xy(x,y);
			cout<<"  ";
		}



		if(imap[pos_y][pos_x]=='#')
		{
			pos_x=x;
			pos_y=y;
		}
		else if(imap[pos_y][pos_x]=='$')
		{
			x2=pos_x;
			y2=pos_y;
			control();
			if(imap[pos_y][pos_x]=='.')
			{
				imap[pos_y][pos_x]='!';
				imap[y2][x2]=' ';
				position_xy(pos_x,pos_y);
				cout<<"●";
				pos_y=y2;
				pos_x=x2;
			}
			else if(imap[pos_y][pos_x]==' ')
			{
				imap[pos_y][pos_x]='$';
				imap[y2][x2]=' ';
				position_xy(pos_x,pos_y);
				cout<<"●";
				pos_y=y2;
				pos_x=x2;
			}
			else if(imap[pos_y][pos_x]=='#' ||
				imap[pos_y][pos_x]=='$')
			{
				position_xy(x2,y2);
				cout<<"●";
				pos_y=y;
				pos_x=x;
			}
			else if(imap[pos_y][pos_x]=='!')
			{
				pos_y=y;
				pos_x=x;
			}
		}
		else if(imap[pos_y][pos_x]=='!')
		{
			x2=pos_x;
			y2=pos_y;
			control();
			if(imap[pos_y][pos_x]=='.')
			{
				imap[pos_y][pos_x]='!';
				imap[y2][x2]='.';
				position_xy(pos_x,pos_y);
				cout<<"●";
				position_xy(x2,y2);
				cout<<"◎";
				pos_y=y2;
				pos_x=x2;

			}
			else if(imap[pos_y][pos_x]==' ') 
			{
				imap[pos_y][pos_x]='$';
				imap[y2][x2]='.';
				position_xy(pos_x,pos_y);
				cout<<"●";
				pos_y=y2;
				pos_x=x2;
			}
			else if(imap[pos_y][pos_x]=='#' ||
				imap[pos_y][pos_x]=='$')
			{
				position_xy(x2,y2);
				cout<<"●";
				pos_y=y;
				pos_x=x;
			}
		}

		for(int j=0;j<15;j++)
		{
			for(int k=0;k<15;k++)
			{
				if(imap[j][k]=='!') cNum++;
			}
		}


		if(cNum==hNum) 
		{
			system("cls");
			stage_num++;
			count=0;
			position_xy(5,12);
			cout<<"congrat!"<<endl;
			position_xy(5,13);
			cout<<"계속하려면 엔터"<<endl;
			position_xy(5,14);
			cout<<"시작화면으로 가려면 아무키나 누르세요"<<endl;
			input=getch();
			return;
		}

	}
}

void gameControl::read_ending()
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
