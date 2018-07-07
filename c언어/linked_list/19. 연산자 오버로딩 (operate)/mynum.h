#include <iostream>							//istream  ostream
using namespace std;
class mynum
{
	int num;								//friend 는 상속이 안됨.... 한단계까지만 친구. 친구의 친구는 내친구아님

public :

	mynum(int n):num(n){}					//초기화
	mynum operator +(const mynum &n)const;	//nynum &n에 붙인 const는 n을 변경못하도록...
											//함수에 붙은 const는 m1,m2 즉..객체가 변하지 못하도록 막아줌.
	void getnum();
	ostream& operator<<(ostream &os);		//ostream& 
	friend ostream& operator<<(ostream &os, const mynum &n);

};