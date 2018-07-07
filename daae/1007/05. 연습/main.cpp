#include <iostream>
#include <conio.h>		//getch용 헤더
#include <windows.h>
#define key_left 75
#define key_right 77
#define key_up 72
#define key_down 80
#define key_enter 13
#define key_q 113
#define key_Q 81
using namespace std;
int i,j,k;
int input;
int pos_x=20,pos_y=10;  // 커서 위치 초기화 
int dol=1;				// 오목알 색 초기화 : 흰은 2 흑은 1
char* pan[21][21]={0}; 

/*******************************************/
//커서의 위치 설정
/*******************************************/
void position_xy(int x,int y)
{
	COORD pos ={x,y};        //COORD는 클래스..pos는 내가 주는 이름..
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

/*******************************************/
//돌 프린트
/*******************************************/

void position_dol()      
{
	if(dol==1)	cout<<"○";
	else cout<<"●";
}
int winCheck()
{
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(pan[i][j]=="●"||pan[i][j]=="○")
			{
				if(pan[i][j]==pan[i][j+1]&&
				   pan[i][j]==pan[i][j+2]&&
				   pan[i][j]==pan[i][j+3]&&
				   pan[i][j]==pan[i][j+4])
				{
					position_xy(20,10);
					if(pan[i][j]=="●") cout<<"백돌 승!!! "<<endl;
					else if(pan[i][j]=="○") cout<<"흑돌 승!!! "<<endl;
					return 1;
				}

				else if(i<17&&
						pan[i][j]==pan[i+1][j]&&
						pan[i][j]==pan[i+2][j]&&
						pan[i][j]==pan[i+3][j]&&
						pan[i][j]==pan[i+4][j])
				{
					position_xy(20,10);
					if(pan[i][j]=="●") cout<<"백돌 승!!! "<<endl;
					else if(pan[i][j]=="○") cout<<"흑돌 승!!! "<<endl;
					return 1;
				}

				else if(i<17&&j<17&&
						pan[i][j]==pan[i+1][j+1]&&
						pan[i][j]==pan[i+2][j+2]&&
						pan[i][j]==pan[i+3][j+3]&&
						pan[i][j]==pan[i+4][j+4])
				{
					position_xy(20,10);
					if(pan[i][j]=="●") cout<<"백돌 승!!! "<<endl;
					else if(pan[i][j]=="○") cout<<"흑돌 승!!! "<<endl;
					return 1;
				}
				else if (j>=4&&
						pan[i][j]==pan[i+1][j-1]&&
						pan[i][j]==pan[i+2][j-2]&&
						pan[i][j]==pan[i+3][j-3]&&
						pan[i][j]==pan[i+4][j-4])
				{
					position_xy(20,10);
					if(pan[i][j]=="●") cout<<"백돌 승!!! "<<endl;
					else if(pan[i][j]=="○") cout<<"흑돌 승!!! "<<endl;
					return 1;
				}

			}
		}

	}
	return 0;
}	

void game()               
{
	while(1)
	{
	system("cls");

	int n=21;
//	char* pan[21][21];   //string pan[][]이랑 같음..
	for(i=0;i<n;i++)
	{
		if (i==0) 
		{
			pan[i][0]="┌";
			for (j=1;j<n;j++)
			{
				pan[i][j]="┬";
			}
			pan[i][n-1]="┐";
		}
		else if(i!=0&&i!=n-1)
		{
			pan[i][0]="├";
			for (j=1;j<n;j++)
			{
				pan[i][j]="┼";
			}
			pan[i][n-1]="┤";
		}
		else if(i==n-1)
		{
			pan[i][0]="└";
			for (j=1;j<n;j++)
			{
				
				pan[i][j]="┴";
			}
			pan[i][n-1]="┘";
		}
	}

	for(i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cout<<pan[i][j];
		}
			cout<<endl;
	}
	
	while(1)
	{
		position_xy(pos_x,pos_y);
		position_dol() ;
		input=getch();
		switch (input)
		{
			case key_left  : if(pos_x>0) pos_x-=2; 
							 break;
			case key_right : if(pos_x<40) pos_x+=2;
							 break;
			case key_up    : if(pos_y>0) pos_y-=1;
							 break;
			case key_down  : if(pos_y<20) pos_y+=1;
							 break;
		}
		if(input==key_q || input==key_Q)
		{
			system("cls");
			return;
		}

		else if(input==key_enter)
		{

			if(dol==1)
			pan[pos_y][pos_x/2]="○";
			else if(dol!=1)
			pan[pos_y][pos_x/2]="●";
		}

		system("cls");
		for(i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				cout<<pan[i][j];
			}
				cout<<endl;
		}

		if(dol==1) dol=2;
		else dol=1;

		if (winCheck()==1)
		{
			while(1)
			{
				cout<<"계속하려면 enter, 처음으로 돌아가려면 q"<<endl;
				input=getch();
				if(input==key_enter) 
				{
					pos_x=20; 
					pos_y=10;
					dol=1;
					system("cls");
					break;
				}
				else if(input==key_q||key_Q)
				{
					pos_x=20; 
					pos_y=10;
					dol=1;
					system("cls");
					return;
				}

			}
			break;
		}
	}
	}
}

void main()
{
	while(1)
	{
		cout<<"============================================================================="<<endl;
		cout<<"                                오목게임"<<endl;
		cout<<"============================================================================="<<endl<<endl;
		cout<<"                   게임을 시작하려면 Enter키를 누르세요"<<endl;
		

		input=getch();
	//	printf ("%d\n",input);
	//	cout<<input<<endl;    

		if(input==key_enter)
		{
			pos_x=20;
			pos_y=10;  
			dol=1;		
			for(i=0;i<30;i++)
			{
				for (j=0;j<30;j++)
				pan[i][j]=0;
			}

			system("cls");		//현재 커맨드 창을 지움..
			game();
				
		}

	}
}
	