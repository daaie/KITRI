#include <iostream>
using namespace std;
void main()
{

	//bool�� true false �� �Ȉ�...0�� 1

//	bool math=85; ->��
	int math=85;

	bool bgrade1 = math>=90;
	bool bgrade2 = math>=80&&math<90;
	bool bgrade3 = math>=70&&math<80;
	bool bgrade4 = math>=60&&math<70;
	bool bgrade5 = math<60;

	int cgrade1 = math>=90;
	int cgrade2 = math>=80&&math<90;
	int cgrade3 = math>=70&&math<80;
	int cgrade4 = math>=60&&math<70;
	int cgrade5 = math<60;

//��� ���� ����..bool�� �޸𸮾Ƴ�
	
	


	cout<<" �� = "<<bgrade1<<endl;
	cout<<" �� = "<<bgrade2<<endl;
	cout<<" �� = "<<bgrade3<<endl;
	cout<<" �� = "<<bgrade4<<endl;
	cout<<" �� = "<<bgrade5<<endl;
}


