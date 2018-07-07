#include <iostream>
#define zero 0
void main()
{
	using namespace std;
	short dohee = SHRT_MAX;
	unsigned short insuk = dohee;
	cout <<"도희 계좌에는 "<<dohee<<"원 들어있고 ";
	cout <<"인숙 계좌에는 "<<insuk<<"원 들어있다."<<endl;
	cout <<"각 계좌에 1원씩 입금"<<endl<<"이제";
	dohee++;
	insuk++;
	cout<<"도희 잔고는 "<<dohee<<"원이 되었고";
	cout<<"인숙 잔고는 "<<insuk<<"원이 되었다"<<endl;
	cout<<"이럴수가 도희가 나몰래 대출을 했남"<<endl;
	dohee=zero;
	insuk=zero;
	cout<<"도희 계좌에는"<<dohee<<"원이 들어있고 ";
	cout<<"인숙 계좌에는"<<insuk<<"원이 들어있다 "<<endl;
	cout<<"각각의 계좌에서 1원씩 인출한다"<<endl<<"이제";
	dohee--;
	insuk--;
	cout<<"도희 계좌에는"<<dohee<<"원이 되었고 ";
	cout<<"인숙 계좌에는"<<insuk<<"원이 되었다"<<endl;
	cout<<"이럴수가 인숙이가 복권에 당첨되었나"<<endl;
}

