#include <time.h>
#include <iostream>

using namespace std;

void main()
{
	time_t timer;
	tm *pt;

	time(&timer);
	pt=localtime(&timer);

	cout<<pt->tm_year +1900<<"년" <<pt->tm_mon +1 <<"월";
	cout<<pt->tm_hour <<"시"<<pt->tm_min<<"분"<<pt->tm_sec<<"초";
}
