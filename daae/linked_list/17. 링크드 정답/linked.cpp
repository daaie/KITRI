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


std::ostream& operator<<(ostream &os, struct node *s)
{
	if (s==NULL) cout<<"없다"<<endl;
	else
	{
	os<<"이름"<<s->name<<endl;
	os<<"전화번호"<<s->tel<<endl;
	os<<"주소"<<s->address<<endl;
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
	return NULL;	//찾았나 못찾았나 구분...
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