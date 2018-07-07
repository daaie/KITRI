#include <iostream>
#include <string.h>
#include "person.h"

using namespace std;

void main()
{
	char name[10];
	int age;

	Person p[5];
	Person temp;

	for (int i=0;i<5;i++)
	{
		cout<<i+1<<"번째 이름 입력 : ";
		cin>>name;
		cout<<i+1<<"번째 나이 입력 : ";
		cin>>age;
		
		p[i].setinfo(name,age);
	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=i;j<5;j++)
		{
			if(p[i]<p[j]==1)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}

	for (int i=0;i<5;i++) p[i].getinfo();

	
}