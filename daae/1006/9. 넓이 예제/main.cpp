#include <iostream>
using namespace std;
void main()
{
	int width,height;
	cout<<"���̸� �Է��ϼ��� : ";
	cin>>width;
	cout<<"���̸� �Է��ϼ��� : ";
	cin>>height;
	bool check = width==height;
	cout<<"���簢�� ���� : "<<check<<endl;
	cout<<"���� : "<<width*height;
}
