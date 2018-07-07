#include <iostream>
using namespace std;
int add(int a, int a2)
{
cout<<"int a,a2 called";
return a+a2;
}

double add(double a, int a2)
{
cout<<"double int a,a2 called";
return a+a2;
}

double add(double a, double a2)
{
cout<<"double double a,a2 called";
return a+a2;
}

void main()
{

	cout<<" "<<add(1,1)<<endl;
	cout<<" "<<add(1.1,1)<<endl;
	cout<<" "<<add(1.1,1.1)<<endl;
}
