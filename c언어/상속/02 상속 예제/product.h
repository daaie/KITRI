#include <iostream>
using namespace std;

class product
{
public : 
	int point;
	int price;
};

class Tv:public product{
public :
	Tv(){
		price = 200;
		point =20;
	}
};

class Audio:public product{
public :
	Audio(){
		price = 200;
		point =20;
	}
};

class Computer :public product{
public :
	Computer()
	{
		price =300;
		point =30;

	}
};

class Buyer {

public :
	int money;
	int point;
	Buyer (){
		money=1000;
		point=0;
	}
	void buy(product *p)
	{
		if(money>=p->price){
			money-=p->price;
			point+=p->point;
			cout<<"money : "<<money<<"point : "<<point<<endl;
		}
		else {
			cout<<"money : "<<money<<"point : "<<point<<endl;
			cout<<"�ܾ� ���� " <<endl;
		}
	}




	//void buy(Tv tv){
	//	if(money>=tv.price)
	//	{
	//		money-=tv.price;
	//		point+=tv.point;
	//	}
	//	else 
	//	{
	//		cout<<"�ܾ� ���� " <<endl;
	//	}
	//}

	//	void buy(Audio audio){
	//	if(money>=audio.price)
	//	{
	//		money-=audio.price;
	//		point+=audio.point;
	//	}
	//	else 
	//	{
	//		cout<<"�ܾ� ���� " <<endl;
	//	}
	//}

	//		void buy(Computer computer){
	//	if(money>=computer.price)
	//	{
	//		money-=computer.price;
	//		point+=computer.point;
	//	}
	//	else 
	//	{
	//		cout<<"�ܾ� ���� " <<endl;			//�����ε�. ����� Ÿ�Կ� ���� �ٸ��� ����
	//	}						
	//}
};