#include <iostream>
#include <string>
using namespace std;
void main()
{
	char char1[20];
	char charr2[20]="jaguar";
	std::string str1;
	string str2="pantherasdfasdfhaksjhdfkjafkjashdflkdf";

	cout<<"����̰� ���� �� �� �Է� : ";
	cin>>char1;
	cout<<"����̰� �� �ٸ� ���� �� �� : ";
	cin >>str1;
	cout<<"�Ʒ� ������ ��� ����̰� " <<endl;
	cout<<char1<<" "<<charr2<<" "
		<<str1<<" "<<str2<<endl;

//	strcpy(str2,"12345689");

	for(int i=0;i<100;i++)
	{
		str2="0123456789"+str2;
	}


	cout<<"string : "<<sizeof(string)<<endl;
	cout<<"charr2 : "<<sizeof(charr2)<<" str2 : "<<sizeof(str2)<<endl;
	cout<<charr2<<"���� 3��° ����"<<charr2[2]<<endl;
	cout<<str2<<"���� 3��° ��¥"<<str2[2]<<endl;
}

