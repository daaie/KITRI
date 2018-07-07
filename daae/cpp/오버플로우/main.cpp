#include <iostream>
using namespace std;;
void main()
{
	short a=0;

	cout<<"size of short is"<<sizeof(short)<<"bytes"<<endl;
	a=32767;

	cout<<a<<endl;

	a=32768;				//오버플로우
	cout<<a<<endl;

	a=-32768;               //양수는 0을 포함하니까 양수랑 완전 반은 아님...
	cout<<a<<endl;

	a=-32769;				//언더플로우
	cout<<a<<endl;
}
// 뫼비우스의 띠같다.....