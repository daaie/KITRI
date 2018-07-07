#include <iostream>
#include <windows.h>
using namespace std;
void delay_1ms_count(int *time_cnt)
{
	Sleep(1);
	*(time_cnt)=*(time_cnt)+1;
}
void delay_1ms_count(int *time_cnt, int *time_cnt2)
{
	Sleep(1);
	*(time_cnt)=*(time_cnt)+1;
	*(time_cnt2)=*(time_cnt2)+1;
}

void main()
{
	int time=0;
	int time2=0;
	while (1)
	{
		delay_1ms_count(&time);
		delay_1ms_count(&time,&time2);
		if (time==1000)
		{
			cout<<"1초 출력"<<endl;
		}
		if (time==2000)
		{
			cout<<"2초 출력"<<endl;
			time=0;
		}
	}
}