//배열 기반은 뒤에서 다 떙겨 줘야하니까 성능이 떨어짐..
//링크드리스트...어려워.....ㅎ.......
#include <iostream>
#include <string.h>
using namespace std;

class Product 
{
	int num;
	static int cnt;
	int price;
	int volume;
	char name[10];
public :
	Product(char *n,int p, int v)
	{
		num=++cnt;
		strcpy_s(name,n);
		price=p;
		volume=v;
	}
	int getnum()
	{
		return num;
	}
	friend ostream& operator<<(ostream &os, const Product &p) 
	{
		os<<"num : "<<p.num<<endl;
		os<<"price : "<<p.price<<endl;
		os<<"name : "<<p.name<<endl;
		os<<"volume : "<<p.volume<<endl;
		return os;
	}
};

int Product::cnt=0;

class Warehouse
{
	int cnt;

public:
	Warehouse()
	{
		cnt = 0;
	}

	~Warehouse()
	{
		for (int i = 0; i < cnt; i++)
		{
			delete products[i];
		}
	}


//	static Product *products[100];
	Product *products[100];
	void addProduct();
	void searchProduct(int n);
	bool editProduct(int n);
	bool delProduct(int n);
	void printProduct();
	bool getProduct(int n);
	bool putproduct(int n);

};
//Product Warehouse::*products[100];

void Warehouse::addProduct()
{
	int v=0,p=0;
	char n[10];
	int flag = 1;

	while(flag)
	{
		cout<<"제품 이름?"<<endl;
		cin>>n;
		cout<<"가격?"<<endl;
		cin>>p;
		cout<<"수량?"<<endl;
		cin>>v;

		products[cnt] = new Product(n, p, v);
		cnt++;

		cout << "그만 하려면 0";
		cin >> flag;
		cout << endl;
	}
}

void Warehouse::printProduct()
{
	for(int i=0;i<cnt;i++)
	cout << *(products[i]);
}

void Warehouse::searchProduct(int n)
{
	for (int i = 0; i < cnt; i++)
	{
		if (products[i]->getnum() == n)
		{
			cout << *(products[i]);	
		}
		else cout << "없졍";
	}
	
}