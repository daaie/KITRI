#include <time.h>
#include <iostream>

using namespace std;

void main()
{
	time_t timer;
	tm *pt;

	time(&timer);
	pt=localtime(&timer);

	cout<<pt->tm_year +1900<<"��" <<pt->tm_mon +1 <<"��";
	cout<<pt->tm_hour <<"��"<<pt->tm_min<<"��"<<pt->tm_sec<<"��";
}
