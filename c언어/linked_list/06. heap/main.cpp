#include <iostream>
using namespace std;
void main()
{
	int *p=(int*) 104;
	int *q=(int*) 100;
	
	cout<<q-p<<endl;
	cout<<p-q<<endl; //포인터끼리 연산은 뺴기만 가능...양수 음수로 순서 판단
					 //비교 연산도 가능.. 정수랑도 가능...
					 //양수가 나오면 뒤에 꺼가 더 앞선 주소
}
