//���� ���� ����
#include <iostream>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl; �� ����

namespace bestcomimpl
{
	void simplefunc()
	{
		cout<<"bestcom�� ������ �Լ�"<<endl;
	}
	void simplefunc2()
	{
		cout<<"bestcom�ι�° �Լ��Դϴ�"<<endl;
	}

}
namespace progcomimpl
{
	void simplefunc(void)
	{
		cout<<"progcom�� ������ �Լ�"<<endl;
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
