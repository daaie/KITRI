#include <iostream>
using namespace std;
void main()
{
	int a=10;
	int b=20;

	int &c=a;            //������ ���������ڷ� ���۷��� ������ ������ ���� 
						 //���� �������ȵ� int &c; &c=a;���ɴ� �ȴ�
						//������ �Ԥ��� �Ű����� ���� �� ���� ��

	cout<<"a : "<<a<<endl;
	cout<<"b : "<<b<<endl;

	c=50;
	cout<<"c : "<<c<<endl;
	cout<<"a : "<<a<<endl;
	cout<<"b : "<<b<<endl;

}
