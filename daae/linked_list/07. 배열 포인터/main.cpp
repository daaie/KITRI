#include <iostream>
using namespace std;
//void main()
//{
//	int a[3]={0};
//	cout<<a<<endl;	//�迭 ù ����� �ּ�
//	cout<<&a<<endl;	//��ü �迭�� �ּ�
//	cout<<a+1<<endl;//�ι�° ����� �ּ�
//	cout<<&a+1<<endl;//������ �ּ�...�迭 ��ü�� ���� 
//}

void main()
{
	int a[3][2]={{10,11},{20,21},{30,31}};
	cout<<(*a)[0]<<endl;
	cout<<(*a)[1]<<endl;
	cout<<(*a)[2]<<endl;
	cout<<(*a)[3]<<endl;
	cout<<a[0][0]<<endl;
	cout<<a[0][1]<<endl;
	cout<<a[0][2]<<endl;
	cout<<a[0][3]<<endl;
	cout<<a<<endl;		//ù�ּ�
	cout<<a+1<<endl;	//a[0]�� ��°�� �Ѿ� ������ �ּ�
	cout<<&a+1<<endl;   //a[1]�� �Ѿ �ű��� �ּ�
	cout<<a[0]+1<<endl;	//a[0][1]�ּ�
}
//�޸𸮴� ������ ū �׸� a[0]�ȿ� a[3]�� ����..