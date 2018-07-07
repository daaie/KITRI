#include <iostream>
#include <string.h>
#include "linked.h"
using namespace std;

Linked::Linked()
{
	head=NULL;
	tail=NULL;        
}
Linked::~Linked()         //�޸� ����
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
	bmp=new struct node;//���� �޸� �Ҵ�.
						//bmp�� ���ÿ� �ִ�. �ּҸ� ���� ������.not heap
						//heap���� �ּ� �Ҵ� ������ �̰� bmp(����)�� �尨 
						//�Լ��� ���� �Ҵ�� ������ �Լ��� ������ ��ȯ�ǰ� �������� ���ư�.

	puts("�߰��� �̸��� �Է��ϼ��� ");
	scanf("%s",bmp->name);
	puts("��ȭ��ȣ �Է� : ");
	scanf("%s",bmp->tel);
	puts("�ּ� �Է� : ");
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
		cout<<"1. �̸� "<<endl;
		cout<<"2. ��ȭ��ȣ "<<endl;
		cout<<"3. �ּ� "<<endl;
		cout<<"-----------------------"<<endl;
		cout<<"� ������ �Է��Ҳ�? : ";
		scanf("%d",&check);
		if(check<4&&check>0) break;
	}
		switch (check)
		{
			case 1:
				puts("�̸��� �Է��ϼ��� ");
				scanf("%s",cname);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->name,cname)==0)
					{
						cout<<endl<<bmp->name<<"�� ����"<<endl;
						cout<<"��ȭ��ȣ : "<<bmp->tel<<endl;
						cout<<"�ּ� : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"���� �̸��ε���..."<<endl;
							break;
						}
						bmp=bmp->next;

					}
				}
				break;

			case 2:
				puts("��ȭ��ȣ�� �Է��ϼ��� ");
				scanf("%s",ctel);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->tel,ctel)==0)
					{
						cout<<endl<<bmp->name<<"�� ����"<<endl;
						cout<<"��ȭ��ȣ : "<<bmp->tel<<endl;
						cout<<"�ּ� : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"���� ��ȭ��ȣ�ε���..."<<endl;
							break;
						}
						bmp=bmp->next;

					}
				}
				break;

			case 3:
				puts("�ּҸ� �Է��ϼ��� ");
				scanf("%s",caddress);

				bmp=head;

				while(1)
				{
					if(strcmp(bmp->address,caddress)==0)
					{
						cout<<endl<<bmp->name<<"�� ����"<<endl;
						cout<<"��ȭ��ȣ : "<<bmp->tel<<endl;
						cout<<"�ּ� : "<<bmp->address<<endl;
						bmp2=bmp;
						break;
					}
					else
					{
						if(bmp->next==NULL)
						{
							cout<<endl<<"���� �ּ��ε���..."<<endl;
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
	cout<<"1. �̸� "<<endl;
	cout<<"2. ��ȭ��ȣ "<<endl;
	cout<<"3. �ּ� "<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"�� �ٲܲ�?"<<endl;
	scanf("%d",&check);
	
	switch(check)
	{
	case 1: cout<<"�ٲ� �̸��� �Է��ϼ���";
		scanf("%s",bmp2->name);
		break;
	case 2: cout<<"�ٲ� ��ȭ��ȣ�� �Է��ϼ���";
		scanf("%s",bmp2->tel);
		break;
	case 3: cout<<"�ٲ� �ּҸ� �Է��ϼ���";
		scanf("%s",bmp2->address);
		break;
	default : break;
	}

}
void Linked::delnode()
{
	searchnode();

	if(head==bmp2)    //bmp2=����, bmp=temp
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
		cout<<i+1<<" : "<<"�̸� = "<<bmp->name<<endl;
		cout<<i+1<<" : "<<"��ȭ��ȣ = "<<bmp->tel<<endl;
		cout<<i+1<<" : "<<"�ּ� = "<<bmp->address<<endl;
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