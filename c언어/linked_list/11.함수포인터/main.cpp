s//void f1();
//void (*p)int=f1; �Լ� ������....

#include <iostream>
using namespace std;

void f1(char *str){
	cout<<"f1 : "<<str;
}
void f2(char *str){
	cout<<"f2 : "<<str;
}
void f3(char *str){
	cout<<"f3 : "<<str;
}
void f4(char *str){
	cout<<"f4 : "<<str;
}

void main()
{
	int check;
	void (*p[4])(char *) = {f1,f2,f3,f4};		//�Լ��� �̸��� �Լ��� �ּҰ�...�Լ� ������ Ÿ���� �Լ��� Ÿ�Կ� �������..
//	p("aaa\n");									//������� �Լ��� ���?...

	cout<<"���� �Է� : (0~3) "<<endl;		
	cin>>check;

	switch(check)								//if���� ����ġ�� ����..�̺�Ʈ�� ��û���� �� look up table (=�Լ� �������� �迭)�� ������
	{
	case 0 : p[0]("aaa");						//�ñ׳�..���μ������� ���.. 
		break;
	case 1 : p[1]("bbb"); 
		break;
	case 2 : p[2]("ccc"); 
		break;
	case 3 : p[3]("ddd"); 
		break;
	default :break;
	}



//	cout<<endl;
//	f1("111");
}