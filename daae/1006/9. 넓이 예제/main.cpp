#include <iostream>
using namespace std;
void main()
{
	int width,height;
	cout<<"길이를 입력하세요 : ";
	cin>>width;
	cout<<"높이를 입력하세요 : ";
	cin>>height;
	bool check = width==height;
	cout<<"정사각형 여부 : "<<check<<endl;
	cout<<"넓이 : "<<width*height;
}
