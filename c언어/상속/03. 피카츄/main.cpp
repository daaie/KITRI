#include <iostream>
#include "character.h"
using namespace std;

void main()
{
	int input=0;
	Character *p=NULL;
	Game go; 

	cout<<"캐릭터를 선택하세요"<<endl;
	cout<<"1. 피카츄"<<endl;
	cout<<"2. 꼬부기"<<endl;
	cout<<"3. 파이리"<<endl<<endl;

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