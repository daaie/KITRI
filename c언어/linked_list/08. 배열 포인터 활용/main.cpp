#include <iostream> //링크드 보다 좋음...한꺼번에 많이 받아서 쪼개줌..데이터가 인접해있다.
using namespace std;
void main()
{
	int size=0;
	int i;
	int *p;

	cout<<"size :";
	scanf("%d",&size);

	p=(int*)malloc(sizeof(int)*size);

	for(i=0;i<size;i++)
	{
		p[i]=i+1;
		cout<<p[i];
	}
}
