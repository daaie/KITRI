#include <iostream>
/*
void main()
{
	int val1;
	std::cout<<"ù ��° ���� �Է�";
	std::cin>>val1;

	int val2;												//���߿� �������� ����.
	std::cout<<"�� ��° ���� �Է�";
	std::cin>>val2;

	int result=val1+val2;
	std::cout<<"�������="<<result<<std::endl;
}
*/
//----------------------------------------------------------------
/*
void main()
{
	int val1,val2;
	int result=0;

	std::cout<<"���� �ΰ��� �Է� : ";
	std::cin>>val1>>val2;

	if (val1<val2)
	{
		for (int i=val1+1;i<val2;i++)
			result+=i;
	}
	else
	{
		for(int i=val2+1;i<val1;i++)
			result+=i;
	}
	std::cout<<"�� �� ���� ������ �� : "<<result<<std::endl;
}
*/
//---------------------------------------------------------------------------
/*
using namespace std;       //�̰� ���� std::�Ƚ�δ� ..����
void main()
{

	char name[100];
	char lang[100];

	cout<<"�̸���?";
	cin>>name;
	cout<<"�����ϴ� ���� ?";
	cin>>lang;

	cout<<"�� �̸��� "<<name<<"�Դϴ�\n";
	cout<<"���� �����ϴ� ���� "<<lang<<"�Դϴ�"<<endl;

}

*///----------------------------------------------------------------------------
using namespace std;
void main()
{
	int carrots;
	carrots=25;

	cout<<"����� ������ ";
	cout<<carrots;
	cout<<" ���Դϴ�";
	cout<<endl;
	--carrots;
	cout<<"�ƻ�ƻ� ���� ����� "<<carrots<<"�� �̴�"<<endl;
}

