#include <iostream>
#include <conio.h> //getch�� ���
#include <windows.h>
//**************************************
//Ű�� ����
//**************************************
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
int pos_x=20,pos_y=10;  // Ŀ�� ��ġ �ʱ�ȭ 
int dol=1;				// ����� �� �ʱ�ȭ : ���� 2 ���� 1
int all_dol[30][30]={0};


/*******************************************/
//Ŀ���� ��ġ ����
/*******************************************/
void position_xy(int x,int y)
{
	COORD pos ={x,y};        //COORD�� Ŭ����..pos�� ���� �ִ� �̸�..
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

/*******************************************/
//�� ����Ʈ
/*******************************************/

void position_dol()      
{
	if(dol==1)	cout<<"��";   //��
	else cout<<"��";		  //��
}
/*******************************************/
//�� ������ ����
/*******************************************/
void savedol()
{
	if(all_dol[pos_y][pos_x/2]==0)
	{
		if(dol==1)
		{
			all_dol[pos_y][pos_x/2]=1;
			dol=2;
		}
		else if (dol==2)
		{
			all_dol[pos_y][pos_x/2]=2;
			dol=1;
		}
	}
}
void print_dol()
{
	for (i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			if(all_dol[i][j]==1) 
			{
			 position_xy(j*2,i);
		     cout<<"��";
			}
			else if(all_dol[i][j]==2)
			{
			 position_xy(j*2,i);
		     cout<<"��";
			}
		}
	}
}
//***************************************************
//Ŀ�� �ܻ� �����
//***************************************************

void del_dol()
{
	for (i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			if(all_dol[i][j]!=0) 
			{
				if(j*2==0&&i==0) {position_xy(j*2,i); cout<<"��";}
				else if(j*2>0&&j*2<20&&i==0) {position_xy(j*2,i); cout<<"��";}
				else if(j*2==20&&i==0) {position_xy(j*2,i); cout<<"��";}
				else if(j*2==0&&i>0&&i<20) {position_xy(j*2,i); cout<<"��";}
				else if(j*2>0&&j*2<20&&i>0&&i<20) {position_xy(j*2,i); cout<<"��";}
				else if(j*2==40&&i>0&&i<20){position_xy(j*2,i); cout<<"��";}
				else if(j*2==0&&i==20){position_xy(j*2,i); cout<<"��";}
				else if(j*2>0&&j*2<20&&i==20){position_xy(j*2,i); cout<<"��";}
				else if(j*2==20&&i==20){position_xy(j*2,i); cout<<"��";}
			}
		}
}
}
		


int winCheck()
{
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(all_dol[i][j]!=0)
			{
				if(all_dol[i][j]==all_dol[i][j+1]&&
				   all_dol[i][j]==all_dol[i][j+2]&&
				   all_dol[i][j]==all_dol[i][j+3]&&
				   all_dol[i][j]==all_dol[i][j+4])
				{
					return 1;
				}

				else if(i<17&&
						all_dol[i][j]==all_dol[i+1][j]&&
						all_dol[i][j]==all_dol[i+2][j]&&
						all_dol[i][j]==all_dol[i+3][j]&&
						all_dol[i][j]==all_dol[i+4][j])
				{
					return 1;
				}

				else if(i<17&&j<17&&
						all_dol[i][j]==all_dol[i+1][j+1]&&
						all_dol[i][j]==all_dol[i+2][j+2]&&
						all_dol[i][j]==all_dol[i+3][j+3]&&
						all_dol[i][j]==all_dol[i+4][j+4])
				{
					return 1;
				}
				else if (j>=4&&
						all_dol[i][j]==all_dol[i+1][j-1]&&
						all_dol[i][j]==all_dol[i+2][j-2]&&
						all_dol[i][j]==all_dol[i+3][j-3]&&
						all_dol[i][j]==all_dol[i+4][j-4])
				{
					return 1;
				}

			}
		}

		
	}
	
}




/*******************************************/
//������ �迭
/*******************************************/
void pan()               
{
	int n=21;
	char* pan[21][21];   //string pan[][]�̶� ����..
	for(i=0;i<n;i++)
	{
		if (i==0) 
		{
			pan[i][0]="��";
			for (j=1;j<n;j++)
			{
				pan[i][j]="��";
			}
			pan[i][n-1]="��";
		}
		else if(i!=0&&i!=n-1)
		{
			pan[i][0]="��";
			for (j=1;j<n;j++)
			{
				pan[i][j]="��";
			}
			pan[i][n-1]="��";
		}
		else if(i==n-1)
		{
			pan[i][0]="��";
			for (j=1;j<n;j++)
			{
				
				pan[i][j]="��";
			}
			pan[i][n-1]="��";
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
	

	cout<<"========================================================================="<<endl;
	cout<<"���� : <-�·� , -> ���, ������, ��Ʒ��� [Enter] : �ٵϳ���, q : ���� "<<endl;
	cout<<"========================================================================="<<endl;
	//3���̴ϱ� ��״� y�� 3��...
}

void game()
{
	pan();
	position_xy(pos_x,pos_y);
//	position_dol();

	while(1)
	{
		input=getch();
		del_dol();
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
			case key_enter : savedol();
							 break;
		
			case key_q :
			case key_Q :{
							pos_x=20;
							pos_y=10;  
							dol=1;		
							for(i=0;i<30;i++)
							{
								for (j=0;j<30;j++)
								all_dol[i][j]=0;
							}

							system("cls");
							return;
						} break;
		}

		print_dol();
		if(winCheck()==1)
		{
			while(1)
			{
				if(all_dol[i][j]==1) 
				{
					position_xy(20,5);
					cout<<"�浹 ��!!! "<<endl;
				}
				else
				{
					position_xy(20,5);
					cout<<"�鵹 ��!!! "<<endl;
				}
				cout<<"�ٽ� �����Ϸ��� enter, ó������ ���ư����� q"<<endl;
				input=getch();
				if(input==key_enter) 
				{
					system("cls");
					pan();
					pos_x=20;
					pos_y=10;  
					dol=1;		
					for(i=0;i<30;i++)
					{
						for (j=0;j<30;j++)
						all_dol[i][j]=0;
					}
					position_xy(pos_x,pos_y);
				//	position_dol();
					break;
				}
				else if(input==key_q) 
				{
					system("cls");
					pos_x=20;
					pos_y=10;  
					dol=1;		
					for(i=0;i<30;i++)
					{
						for (j=0;j<30;j++)
						all_dol[i][j]=0;
					}
					return;
				}
			}

		}
		position_xy(pos_x,pos_y);
//		position_dol();

		



	}
}


void main()
{
	while(1)
	{
		cout<<"============================================================================="<<endl;
		cout<<"                                �������"<<endl;
		cout<<"============================================================================="<<endl<<endl;
		cout<<"                   ������ �����Ϸ��� EnterŰ�� ��������"<<endl;
		

		input=getch();
	//	printf ("%d\n",input);
	//	cout<<input<<endl;    


		if(input==key_enter)
		{				
			system("cls");		//���� Ŀ�ǵ� â�� ����..
			game();
				
		}

	}
}

