#include <iostream>							//istream  ostream
using namespace std;
class mynum
{
	int num;								//friend �� ����� �ȵ�.... �Ѵܰ������ ģ��. ģ���� ģ���� ��ģ���ƴ�

public :

	mynum(int n):num(n){}					//�ʱ�ȭ
	mynum operator +(const mynum &n)const;	//nynum &n�� ���� const�� n�� ������ϵ���...
											//�Լ��� ���� const�� m1,m2 ��..��ü�� ������ ���ϵ��� ������.
	void getnum();
	ostream& operator<<(ostream &os);		//ostream& 
	friend ostream& operator<<(ostream &os, const mynum &n);

};