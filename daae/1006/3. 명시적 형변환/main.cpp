#include <iostream>
using namespace std;
void main()
{
	int salt =30;
	int water =40;
	float concentration=0;
	float real_concentration=0;

	concentration = (30/40)*100; //30/40에서 이미 0임

	cout<<"weight percent = "<<concentration<<"%"<<endl;
	
	concentration = float (30)/float (40) *100; //(float) 30 /(float) 40 *100 이랑 같움

	cout<<"real weight percent = "<<concentration<<"%"<<endl;
}