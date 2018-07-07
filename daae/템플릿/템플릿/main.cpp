#include <iostream>
using namespace std;
template <typename X> X generic_abs(X a)    //X generic_abs(X a) 하면 리턴 ret //void generic_abs(X a)하면 리턴 필요없음
{
	X ret;
	ret = a<0? -a:a;
	cout << " processing abs" <<ret<<endl;
	return ret;
}
int main(int argc,char *argv[])
{
	int x1=10;
	float x2=-10.1f;
	double x3=-2.3;

	generic_abs(x1);
	generic_abs(x2);
	generic_abs(x3);
return 0;
}