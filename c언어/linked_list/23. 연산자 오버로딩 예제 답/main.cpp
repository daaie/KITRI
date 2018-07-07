#include <iostream>
#include "person.h"
using namespace std;
void sort(Person *arr, int size)
{
	Person tmp;
	int i,j;
	for (i=0;i<size-1;i++){
		for(j=0;j<size-1;j++){
			if(arr[j]>arr[j+1]){
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}

}

int main()
{
	int i;
	Person p[5]={Person("aaa",96),Person("bbb",93),
	Person("eee",85),Person("ddd",73),Person("ccc",52)};


	for(i=0;i<5;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<"----------Á¤·Ä ÈÄ ----------"<<endl;

	sort(p,5);
	for(i=0;i<5;i++)
	{
		cout<<p[i]<<endl;
	}
	return 0;
}