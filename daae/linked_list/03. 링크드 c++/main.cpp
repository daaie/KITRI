#include <iostream>
#include "linked.h"

using namespace std;

void main()
{
	int flag=1,check=0;
	Linked link;			//���ÿ� ����. �Լ��� ����...�Լ��� ������ �޸� ��ȯ�Ѵ�.
	while(flag)
	{
		cout<<"-----------------------------"<<endl;
		cout<<" 1. �߰�"<<endl;
		cout<<" 2. �˻�"<<endl;
		cout<<" 3. ����"<<endl;
		cout<<" 4. ����"<<endl;
		cout<<" 5. ��ü ���"<<endl;
		cout<<" 6. ����"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<" ����!! "<<endl;

		scanf("%d",&check);

			switch (check)
			{
				case 1 : link.addnode();
					break;
				case 2 : link.searchnode();
					break;
				case 3 : link.changenode();
					break;
				case 4 : link.delnode();
					break;
				case 5 : link.printnode();
					break;
				case 6 : //link.ending();
					     flag=0; //exit(1);
					break;
				default : break;
			}
	}

}
