#include <iostream>
using namespace std;
//����ü �ȿ��� 1�κ�!
struct student
{
	int id;
	float grade;
	int gender;
};

void main()
{
	struct student student;

	cout<<"�й��� �Է��ϼ���\n";
	cin>>student.id;

	cout<<"������ �Է��ϼ���\n";
	cin>>student.grade;

	cout<<"gender? (���� 1 ���� 2)\n";
	cin>>student.gender;

	cout<<"\n\n";
	cout<<"id : "<<student.id<<endl;

	cout.setf(ios::showpoint);		//�Ҽ���ǥ�����ְڴ�.
	cout.precision(2);				//2�ڸ� ǥ�� ...cout�̶�� ����ü?
	cout<<"������ : "<<(float)student.grade<<endl;

	cout<<"������ : "<<(student.gender==1?"����":"����")<<endl;
	cout<<"�Դϴ�"<<endl;
	
}