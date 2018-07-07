#include <iostream>
using namespace std;
int sub(int n1, int n2)
{
	return n1-n2;
}
float sub(float n1, float n2)
{
	return n1-n2;
}

void main()
{
	cout<<"int sub "<<sub(2,1)<<endl;
	cout<<"float sub "<<sub(2.2f,1.1f)<<endl;
}
	
