#include <iostream>
#include <stdlib.h>
using namespace std;
struct Test{
	double data;
	struct Test *next;
};

void main()
{
	struct Test *head=NULL, *tail, *bmp;
	int flag=1;
	while (flag)
	{
		bmp=(struct Test*)malloc(sizeof(struct Test));
		puts("숫자는 : ");
		scanf ("%lf", &bmp->data);

		if (head ==NULL){
			head=bmp;
		}

		else{
			tail->next=bmp;
		}

		tail=bmp;
		tail->next=NULL;
		puts("stop=>0");
		scanf("%d",&flag);
	}

	bmp=head;

	while(bmp!=NULL)
	{	
		cout<<bmp->data;
		bmp=bmp->next;
	}

	while(head!=NULL)
	{
		bmp=head;
		head=head->next;
		cout<<"메모리 해제"<<bmp->data<<endl;
		free(bmp);
	}
	cout<<head;
}