#include <iostream>
using namespace std;

void main()
{
	unsigned int x=0x11;  //17юс

	unsigned int r1=x<<3;
	unsigned int r2=r1>>3;

	cout.setf(ios::showbase);
	cout<<hex<<x<<"<<3="<<r1<<endl;
	cout<<r1<<">>3="<<r2<<endl;

}

