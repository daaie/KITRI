#include <iostream> //��ũ�� ���� ����...�Ѳ����� ���� �޾Ƽ� �ɰ���..�����Ͱ� �������ִ�.
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
