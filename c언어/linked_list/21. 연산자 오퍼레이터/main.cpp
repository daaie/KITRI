#include <iostream>
#include "person.h"
using namespace std;

void main()
{
	char imsiName[10];
	int imsiAge;

	cout<<"�̸��� �Է� ";
	cin>>imsiName;
	cout<<"���̸� �Է� ";
	cin>>imsiAge;

	Person p1;
	Person p2(imsiName, imsiAge);
	Person p3=p1;  //Person p3(p1); ����.. (�ʱ�ȭ)
	
	//���� �����ڰ� ������ p3�� p1�� �ּҸ� �����ϰԵ�.

	cout<<"1��° �л� "<<p1<<endl;
	cout<<"2��° �л� "<<p2<<endl;
	cout<<"3��° �л� "<<p3<<endl;

	p3.setName("!!!!!!!!!!!!");
	cout<<endl;
	cout<<"1��° �л� "<<p1<<endl;
	cout<<"2��° �л� "<<p2<<endl; 
	cout<<"3��° �л� "<<p3<<endl;   //���� ������ ���п� p1�� ������ ���ش�.

	p2=p3;
	p3.setName("@@@@@@@@@@@@@");
	cout<<endl;
	cout<<"1��° �л� "<<p1<<endl;
	cout<<"2��° �л� "<<p2<<endl;
	cout<<"3��° �л� "<<p3<<endl;

}
	