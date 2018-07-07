#include <iostream>
using namespace std;
void main()
{

	//bool은 true false 만 안댱...0과 1

//	bool math=85; ->가
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

//결과 값은 같다..bool은 메모리아낌
	
	


	cout<<" 수 = "<<bgrade1<<endl;
	cout<<" 우 = "<<bgrade2<<endl;
	cout<<" 미 = "<<bgrade3<<endl;
	cout<<" 양 = "<<bgrade4<<endl;
	cout<<" 가 = "<<bgrade5<<endl;
}


