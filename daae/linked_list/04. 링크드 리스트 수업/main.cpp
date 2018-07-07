#include <iostream>
using namespace std;

int add(int c, ...)
{
	int i, sum=0;

	for (i=1;i<=c;i++)
	{
		sum+=*(&c+i); //sum+=(&c)[i]
	}
	return sum;
}

void main()
{
	printf("%d\n",add(3,1,2,3));
	printf("%d\n",add(5,1,2,3,4,5));
}