#include <iostream>
using namespace std;
//void main()
//{
//	int a[3]={0};
//	cout<<a<<endl;	//배열 첫 요소의 주소
//	cout<<&a<<endl;	//전체 배열의 주소
//	cout<<a+1<<endl;//두번째 요소의 주소
//	cout<<&a+1<<endl;//마지막 주소...배열 전체를 점프 
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
	cout<<a<<endl;		//첫주소
	cout<<a+1<<endl;	//a[0]를 통째로 넘어 간거의 주소
	cout<<&a+1<<endl;   //a[1]를 넘어간 거까지 주소
	cout<<a[0]+1<<endl;	//a[0][1]주소
}
//메모리는 선형임 큰 네모 a[0]안에 a[3]이 있음..