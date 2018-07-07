//굳이 구현 ㄴㄴ
#include <iostream>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl; 다 가능

namespace bestcomimpl
{
	void simplefunc()
	{
		cout<<"bestcom이 정의한 함수"<<endl;
	}
	void simplefunc2()
	{
		cout<<"bestcom두번째 함수입니다"<<endl;
	}

}
namespace progcomimpl
{
	void simplefunc(void)
	{
		cout<<"progcom이 정의한 함수"<<endl;
	}
}
void main()
{
	using namespace bestcomimpl;
//	using namespace progcomimpl;
	bestcomimpl::simplefunc();
	bestcomimpl::simplefunc2();
	progcomimpl::simplefunc();
	simplefunc();
	simplefunc2();
}
