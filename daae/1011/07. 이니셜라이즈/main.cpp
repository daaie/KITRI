#include <iostream>
using namespace std;
class fruitseller
{
private : const int Apple_pri;
		  int numofApple;
public : fruitseller(int price, int num) :Apple_pri(price), numofApple(num)  //const�� �ٲ� �� ����, ���𿡼� �ʱ�ȭ�� �ȵ�..
																			//�̴ϼȶ������ϸ� �ʱ�ȭ��
																			//��ӹ޾��� �� �θ��� �����̺��̶� ���� �ȵɶ��� �ʱ�ȭ��..���	
		 {
		 }
		 void out()
		 {
			 cout<<"Apple ���� "<<Apple_pri<<endl;
		 }
};
void main()
{
	fruitseller fruit(1000,3);
	fruit.out();
}
