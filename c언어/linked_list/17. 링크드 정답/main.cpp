#include <iostream>
#include "linked.h"
using namespace std;
void main()
{
	struct node *cmp;
	Linked l;
	while(1)
	{
	
	int input=0;
	cout<<"1:추가"<<endl;
	cout<<"2:검색"<<endl;
	cin>>input;

	switch(input)
	{
	case 1:
		l.addnode();
		break;
	case 2:
		cmp=l.search("aaa");
		cout<<cmp;
		break;
	case 3:
		l.print();
		break;
	default : break;
	}
	}
}
