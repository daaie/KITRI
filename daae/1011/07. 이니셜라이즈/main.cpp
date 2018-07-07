#include <iostream>
using namespace std;
class fruitseller
{
private : const int Apple_pri;
		  int numofApple;
public : fruitseller(int price, int num) :Apple_pri(price), numofApple(num)  //const라서 바꿀 수 없고, 선언에서 초기화도 안됨..
																			//이니셜라이저하면 초기화됨
																			//상속받았을 때 부모의 프라이빗이라 접근 안될때도 초기화됨..우왕	
		 {
		 }
		 void out()
		 {
			 cout<<"Apple 가격 "<<Apple_pri<<endl;
		 }
};
void main()
{
	fruitseller fruit(1000,3);
	fruit.out();
}
