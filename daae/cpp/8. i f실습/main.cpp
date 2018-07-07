#include <iostream>
using namespace std;
void main()
{
	int time,age;
	cout<<"현재 시간과 나이를 입력하세요 (시간 , 나이)";
	cin>>time>>age;

	if (time>17)
	{
		cout<<"요금은 10,000원 입니다"<<endl;
	}
	else
	{
		if(age<=1 2||age>=65)
		{
			cout<<"요금은 25,000원 입니다"<<endl;
		}
		else 
		{
			cout<<"요금은 34,000원 입니다"<<endl;
		}
	}
}