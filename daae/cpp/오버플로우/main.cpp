#include <iostream>
using namespace std;;
void main()
{
	short a=0;

	cout<<"size of short is"<<sizeof(short)<<"bytes"<<endl;
	a=32767;

	cout<<a<<endl;

	a=32768;				//�����÷ο�
	cout<<a<<endl;

	a=-32768;               //����� 0�� �����ϴϱ� ����� ���� ���� �ƴ�...
	cout<<a<<endl;

	a=-32769;				//����÷ο�
	cout<<a<<endl;
}
// ����콺�� �찰��.....