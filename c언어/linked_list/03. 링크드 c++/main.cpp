#include <iostream>
#include "linked.h"

using namespace std;

void main()
{
	int flag=1,check=0;
	Linked link;			//스택에 저장. 함수도 스택...함수가 끝나면 메모리 반환한다.
	while(flag)
	{
		cout<<"-----------------------------"<<endl;
		cout<<" 1. 추가"<<endl;
		cout<<" 2. 검색"<<endl;
		cout<<" 3. 수정"<<endl;
		cout<<" 4. 삭제"<<endl;
		cout<<" 5. 전체 출력"<<endl;
		cout<<" 6. 종료"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<" 선택!! "<<endl;

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
