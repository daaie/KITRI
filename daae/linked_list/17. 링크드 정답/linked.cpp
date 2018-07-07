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


std::ostream& operator<<(ostream &os, struct node *s)
{
	if (s==NULL) cout<<"����"<<endl;
	else
	{
	os<<"�̸�"<<s->name<<endl;
	os<<"��ȭ��ȣ"<<s->tel<<endl;
	os<<"�ּ�"<<s->address<<endl;
	}
	return os;
}

struct node * Linked::search(const char *name)
{
	bmp=head;
	while(bmp!=NULL)
	{
		if(strcmp(name,bmp->name)==0) return bmp;
		//if(!strcmp(name,bmp->name))
		else bmp=bmp->next;
	}
	return NULL;	//ã�ҳ� ��ã�ҳ� ����...
}

void Linked :: print()
{
	bmp=head;
	while(bmp!=NULL)
	{
		cout<<bmp<<endl;
		bmp=bmp->next;
	}
}