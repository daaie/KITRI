#include <iostream>
using namespace std;

void main()
{
int *data, flag=1;
int i=0;
data=(int*)malloc(sizeof(int));
while(flag){
	puts("���ڸ� �Է�");
	int *data_imsi=data;
	data=(int*)malloc(sizeof(int)*(i+1));
	data=data_imsi;
	scanf("%d",&data[i]);
	i++;
	puts("���߷��� 0");
	scanf("%d",&flag);
}
	for(int j=0;j<i;j++)
	cout<<data[j];
}