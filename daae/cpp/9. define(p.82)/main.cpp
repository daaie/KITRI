#include <iostream>
#define zero 0
void main()
{
	using namespace std;
	short dohee = SHRT_MAX;
	unsigned short insuk = dohee;
	cout <<"���� ���¿��� "<<dohee<<"�� ����ְ� ";
	cout <<"�μ� ���¿��� "<<insuk<<"�� ����ִ�."<<endl;
	cout <<"�� ���¿� 1���� �Ա�"<<endl<<"����";
	dohee++;
	insuk++;
	cout<<"���� �ܰ�� "<<dohee<<"���� �Ǿ���";
	cout<<"�μ� �ܰ�� "<<insuk<<"���� �Ǿ���"<<endl;
	cout<<"�̷����� ���� ������ ������ �߳�"<<endl;
	dohee=zero;
	insuk=zero;
	cout<<"���� ���¿���"<<dohee<<"���� ����ְ� ";
	cout<<"�μ� ���¿���"<<insuk<<"���� ����ִ� "<<endl;
	cout<<"������ ���¿��� 1���� �����Ѵ�"<<endl<<"����";
	dohee--;
	insuk--;
	cout<<"���� ���¿���"<<dohee<<"���� �Ǿ��� ";
	cout<<"�μ� ���¿���"<<insuk<<"���� �Ǿ���"<<endl;
	cout<<"�̷����� �μ��̰� ���ǿ� ��÷�Ǿ���"<<endl;
}

