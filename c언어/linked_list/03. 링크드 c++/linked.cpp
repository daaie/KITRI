#include <iostream>
#include <string.h>
#include "linked.h"
using namespace std;

Linked::Linked()
{
	head=NULL;
	tail=NULL;        
}
Linked::~Linked()         //메모리 해제
{
	while (head!=NULL)
	{
		bmp=head;
		head=head->next;
		delete bmp;
	}
}


void Linked::addnode()
{
	//struct node *bmp = new struct node;
	bmp=new struct node;//동적 메모리 할당.
						//bmp는 스택에 있다. 주소를 가진 변수임.not heap
						//heap에서 주소 할당 받으면 이게 bmp(스택)에 드감 
						//함수를 위해 할당된 스택은 함수가 끝나면 반환되고 메인으로 돌아감.

	puts("추가할 이름을 입력하세요 ");
	scanf("%s",bmp->name);
	puts("전화번호 입력 : ");
	scanf("%s",bmp->tel);
	puts("주소 입력 : ");
	scanf("%s",bmp->address);

	if(head==NULL) 
	{
		head=bmp;
	}
	else
	{
		tail->next=bmp;
	}
	tail=bmp;
	tail->next=NULL;
}

void Linked::searchnode()
{
	char cname[10]={0};
	char ctel[20]={0};
	char caddress[40]={0};
	int check=1;
	
	while(1)
	{
		cout<<"-----------------------"<<endl;
		cout<<"1. 이름 "<<endl;
		cout<<"2. 전화번호 "<<endl;
		cout<<"3. 주소 "<<endl;
		cout<<"-----------------------"<<endl;
		cout<<"어떤 정보를 입력할꺼? : ";
		scanf("%d",&check);
		if(check<4&&check>0) break;
	}
		switch (check)
		{
			case 1:
				puts("이름을 입력하세요 ");
				scanf("%s",cname);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->name,cname)==0)
					{
						cout<<endl<<bmp->name<<"의 정보"<<endl;
						cout<<"전화번호 : "<<bmp->tel<<endl;
						cout<<"주소 : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"없는 이름인데요..."<<endl;
							break;
						}
						bmp=bmp->next;

					}
				}
				break;

			case 2:
				puts("전화번호를 입력하세요 ");
				scanf("%s",ctel);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->tel,ctel)==0)
					{
						cout<<endl<<bmp->name<<"의 정보"<<endl;
						cout<<"전화번호 : "<<bmp->tel<<endl;
						cout<<"주소 : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"없는 전화번호인데요..."<<endl;
							break;
						}
						bmp=bmp->next;

					}
				}
				break;

			case 3:
				puts("주소를 입력하세요 ");
				scanf("%s",caddress);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->address,caddress)==0)
					{
						cout<<endl<<bmp->name<<"의 정보"<<endl;
						cout<<"전화번호 : "<<bmp->tel<<endl;
						cout<<"주소 : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"없는 주소인데요..."<<endl;
							break;
						}
						bmp=bmp->next;

					}
				}
				break;

			default : break;
		}
	
	
}
void Linked::changenode()
{
	searchnode();

	int check=0;
	cout<<"-----------------------"<<endl;
	cout<<"1. 이름 "<<endl;
	cout<<"2. 전화번호 "<<endl;
	cout<<"3. 주소 "<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"뭘 바꿀꺼?"<<endl;
	scanf("%d",&check);
	
	switch(check)
	{
	case 1: cout<<"바꿀 이름을 입력하세요";
		scanf("%s",bmp2->name);
		break;
	case 2: cout<<"바꿀 전화번호를 입력하세요";
		scanf("%s",bmp2->tel);
		break;
	case 3: cout<<"바꿀 주소를 입력하세요";
		scanf("%s",bmp2->address);
		break;
	default : break;
	}

}
void Linked::delnode()
{
	searchnode();

	if(head==bmp2)    //bmp2=현재, bmp=temp
	{
		bmp=head->next;
		free(head);
		head=bmp;
	}
	else
	{
		bmp=head;
		while(1)
		{
			if(bmp->next==tail && bmp->next==bmp2)
			{	
				tail=bmp;
				tail->next=NULL;
				free(bmp2);
				break;
			}
			else if(bmp->next==bmp2)
			{
				bmp->next=bmp2->next;
				free(bmp2);
				break;
			}
			else 
			{
				bmp=bmp->next;
			}
		}
	}
}
void Linked::printnode()
{
	int i=0;
	bmp=head;
	while(bmp!=NULL)
	{
		cout<<i+1<<" : "<<"이름 = "<<bmp->name<<endl;
		cout<<i+1<<" : "<<"전화번호 = "<<bmp->tel<<endl;
		cout<<i+1<<" : "<<"주소 = "<<bmp->address<<endl;
		i++;
		bmp=bmp->next;
	}
}


void Linked::ending()
{
	while(head!=NULL)
	{
		bmp=head;
		head=head->next;
		free(bmp);
	}
}