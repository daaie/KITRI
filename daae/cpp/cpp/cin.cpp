#include <iostream>
/*
void main()
{
	int val1;
	std::cout<<"첫 번째 숫자 입력";
	std::cin>>val1;

	int val2;												//도중에 변수선언 가능.
	std::cout<<"두 번째 숫자 입력";
	std::cin>>val2;

	int result=val1+val2;
	std::cout<<"덧셈결과="<<result<<std::endl;
}
*/
//----------------------------------------------------------------
/*
void main()
{
	int val1,val2;
	int result=0;

	std::cout<<"변수 두개를 입력 : ";
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
	std::cout<<"두 수 사이 정수의 합 : "<<result<<std::endl;
}
*/
//---------------------------------------------------------------------------
/*
using namespace std;       //이거 쓰면 std::안써두댐 ..전역
void main()
{

	char name[100];
	char lang[100];

	cout<<"이름은?";
	cin>>name;
	cout<<"좋아하는 언어는 ?";
	cin>>lang;

	cout<<"내 이름은 "<<name<<"입니다\n";
	cout<<"제일 좋아하는 언어는 "<<lang<<"입니다"<<endl;

}

*///----------------------------------------------------------------------------
using namespace std;
void main()
{
	int carrots;
	carrots=25;

	cout<<"당근의 개수는 ";
	cout<<carrots;
	cout<<" 개입니다";
	cout<<endl;
	--carrots;
	cout<<"아삭아삭 이제 당근은 "<<carrots<<"개 이다"<<endl;
}

