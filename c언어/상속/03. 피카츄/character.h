#include <iostream>
#include <windows.h>
#include <typeinfo>		//typeid ������..?
using namespace std;
class Character 
{
protected :
	int level;
	int hp;
	int maxhp;
	int exp;
	int state;
	bool live;
public :
	virtual void eat()=0;		//hp+
	virtual void sleep()=0;		//hp+
	virtual bool play()=0;		//hp- exp+
	virtual bool exc()=0;		//hp- exp+
	virtual void levelup()=0;	

	void printinfo(){
		system("cls");
		cout<<"hp : "<<hp<<endl;
		cout<<"exp : "<<exp<<endl;
		cout<<"level : "<<level<<endl<<endl;
	}
};

class Picachu : public Character
{
public : 
	Picachu(){
		cout<<" ��ī�߰� ���� "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" ��ī�� �� �Դ� ��... "<<endl;
			hp+=5;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" ��ī�� �ڴ� ��... "<<endl;
		hp+=10;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" ��ī�� ��� ��..."<<endl;
		hp-=5;
		exp+=10;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(500);
		if(hp<=0) return false;
		else return true;
	}
	bool exc(){
		cout<<" ��ī�� � �ϴ� ��..."<<endl;
		hp-=10;
		exp+=20;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(1500);
		if(hp<=0) return false;
		else return true;
	}
	void levelup(){
		if(exp>=100) {
			level++;
			exp=exp-100;
			maxhp+=10;
			hp=maxhp;
		}

	}
	void elec(){
		cout<<"�鸸 ��Ʈ"<<endl;
	}
};

class Ggobugi : public Character
{
public : 
	Ggobugi(){
		cout<<" ���αⰡ ���� "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" ���α� �� �Դ� ��... "<<endl;
			hp+=5;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" ���α� �ڴ� ��... "<<endl;
		hp+=10;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" ���α� ��� ��..."<<endl;
		hp-=5;
		exp+=10;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(500);
		if(hp<=0) return false;
		else return true;
	}
	bool exc(){
		cout<<" ���α� � �ϴ� ��..."<<endl;
		hp-=10;
		exp+=20;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(1500);
		if(hp<=0) return false;
		else return true;
	}
	void levelup(){
		if(exp>=100) {
			level++;
			exp=exp-100;
			maxhp+=10;
			hp=maxhp;
		}

	}
	void water(){
		cout<<"�� ����"<<endl;
	}
	
};

class Pairi : public Character
{
public : 
	Pairi(){
		cout<<" ���̸��� ���� "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" ���̸� �� �Դ� ��... "<<endl;
			hp+=5;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" ���̸� �ڴ� ��... "<<endl;
		hp+=10;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"ü���� �̹� ������ �ֽ��ϴ�"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" ���̸� ��� ��..."<<endl;
		hp-=5;
		exp+=10;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(500);
		if(hp<=0) return false;
		else return true;
	}
	bool exc(){
		cout<<" ���̸� � �ϴ� ��..."<<endl;
		hp-=10;
		exp+=20;
		if(exp>=100)
		{
			levelup();
		}
		Sleep(1500);
		if(hp<=0) return false;
		else return true;
	}
	void levelup(){
		if(exp>=100) {
			level++;
			exp=exp-100;
			maxhp++;
			hp=maxhp;
		}

	}
	void fire(){
		cout<<"���̾�"<<endl;
	}
};
class Game
{
	int input;
	int flag;
public :
	Game()
	{
		input=0;
		flag=1;
	}
	void game(Character *c)
	{
		while(flag)
		{
			c->printinfo();
			cout<<"������ �Ͻðڽ��ϱ�"<<endl;
			cout<<"1. �� �Ա�"<<endl;
			cout<<"2. �ڱ�"<<endl;
			cout<<"3. ���"<<endl;
			cout<<"4. ��ϱ�"<<endl;
			cout<<"5. ������"<<endl;
			cout<<"6. Ư�����"<<endl; //�ٿ� ĳ���� ����

			cin>>input;

			switch(input)
			{
			case 1: c->eat();
				break;
			case 2: c->sleep();
				break;
			case 3: flag=c->play();
				if(!flag){
					system("cls");
					c->printinfo();
					cout<<"���� �ֱ�"<<endl;
					exit(1);
				}
				break;
			case 4: flag=c->exc();
				if(!flag){
				system("cls");
				c->printinfo();
				cout<<"���� �ֱ�"<<endl;
				exit(1);
				}
				break;

			case 5: cout<<"������"<<endl;
				flag=false;
				break;
			case 6 : if(typeid(class Picachu)==typeid(*c))
					 {
						 ((Picachu *)c)->elec();
						 system("pause");
					 }
					 else if(typeid(class Ggobugi)==typeid(*c))
					 {
						 ((Ggobugi *)c)->water();
						 system("pause");
					 }
					 else if(typeid(class Picachu)==typeid(*c))
					 {
						 ((Pairi *)c)->fire();
						 system("pause");
					 }
					 break;	 
			default : cout<<"�ٸ� �� ����..."<<endl;
				break;
			}

		}
	}
};
