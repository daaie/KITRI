#include <iostream>
#include "character.h"
using namespace std;

void main()
{
	int input=0;
	Character *p=NULL;
	Game go; 

	cout<<"ĳ���͸� �����ϼ���"<<endl;
	cout<<"1. ��ī��"<<endl;
	cout<<"2. ���α�"<<endl;
	cout<<"3. ���̸�"<<endl<<endl;

	cin>>input;

	switch (input)
	{
		case 1 : 
			p= new Picachu;
			break;
		case 2 :
			p=new Ggobugi;
			break;
		case 3 : 
			p=new Pairi;
			break;
		default :			
			p= new Picachu;
			break;
	}
	go.game(p);
	delete p;
}