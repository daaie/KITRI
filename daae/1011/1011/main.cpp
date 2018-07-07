//inline - define과 비슷한 속도?
//함수는 호출과 복귀에 시간이 오래 걸림.. 그래서 inline씀
//define > inline > 함수
#include <iostream>
using namespace std;
inline int inc(int x)
{
	return x+1;
}
int main(int argc, char* argv[])
{
	int i;
	cout<<"숫자 : ";
	cin>>i;
	cout<<inc(i)<<endl;
	return 0;
}
