#include <iostream>
using namespace std;
void main()
{
	short val,low,low2,low3,high,high2;
	cout<<"���� �Է��ϼ��� : ";
	cin>>val;
	cout.setf(ios::hex,ios::basefield);
	cout<<"�Է� �� (16����) : "<<val<<endl;
	
	high = val>>8;
	high2=(val&0xff00)>>8;

	low = val%(16*16);  //32��Ʈ�� 0x0000ffff
	low2= (high<<8)^val;
    low3= val&0x00ff; 

	cout<<"high : "<<high<<endl;
	cout<<"high2 : "<<high2<<endl;
	cout<<"low : "<<low<<endl;
	cout<<"low2 : "<<low2<<endl;
	cout<<"low3 : "<<low3<<endl;
}
