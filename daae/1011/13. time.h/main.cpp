#include <time.h>
#include <iostream>
#include <windows.h>
using namespace std;

void main()
{
	time_t start_time=0, end_time=0;
	start_time=clock();
	while(1)
	{
		end_time=clock();
		if((end_time-start_time)>=1000)
		{
			cout<<"1sec"<<endl;
			start_time=clock();
		}
	}
}