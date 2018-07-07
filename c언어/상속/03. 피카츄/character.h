#include <iostream>
#include <windows.h>
#include <typeinfo>		//typeid 연산자..?
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
		cout<<" 피카추가 생성 "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" 피카추 밥 먹는 중... "<<endl;
			hp+=5;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" 피카추 자는 중... "<<endl;
		hp+=10;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" 피카츄 노는 중..."<<endl;
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
		cout<<" 피카츄 운동 하는 중..."<<endl;
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
		cout<<"백만 볼트"<<endl;
	}
};

class Ggobugi : public Character
{
public : 
	Ggobugi(){
		cout<<" 꼬부기가 생성 "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" 꼬부기 밥 먹는 중... "<<endl;
			hp+=5;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" 꼬부기 자는 중... "<<endl;
		hp+=10;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" 꼬부기 노는 중..."<<endl;
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
		cout<<" 꼬부기 운동 하는 중..."<<endl;
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
		cout<<"물 대포"<<endl;
	}
	
};

class Pairi : public Character
{
public : 
	Pairi(){
		cout<<" 파이리가 생성 "<<endl;
		maxhp=40;
		hp=maxhp;
		exp=0;
		level=1;
	}
	void eat(){
		if(hp<maxhp){
			cout<<" 파이리 밥 먹는 중... "<<endl;
			hp+=5;
			if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(500);
	}
	void sleep(){
		if(hp<maxhp){
		cout<<" 파이리 자는 중... "<<endl;
		hp+=10;
		if(hp>=maxhp) hp=maxhp;
		}
		else if(hp>=maxhp) cout<<"체력이 이미 가득차 있습니다"<<endl;
		Sleep(1500);
	}
	bool play(){
		cout<<" 파이리 노는 중..."<<endl;
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
		cout<<" 파이리 운동 하는 중..."<<endl;
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
		cout<<"파이야"<<endl;
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
			cout<<"무엇을 하시겠습니까"<<endl;
			cout<<"1. 밥 먹기"<<endl;
			cout<<"2. 자기"<<endl;
			cout<<"3. 놀기"<<endl;
			cout<<"4. 운동하기"<<endl;
			cout<<"5. 겜종료"<<endl;
			cout<<"6. 특기공격"<<endl; //다운 캐스팅 예제

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
					cout<<"으앙 주금"<<endl;
					exit(1);
				}
				break;
			case 4: flag=c->exc();
				if(!flag){
				system("cls");
				c->printinfo();
				cout<<"으앙 주금"<<endl;
				exit(1);
				}
				break;

			case 5: cout<<"겜종료"<<endl;
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
			default : cout<<"다른 거 하자..."<<endl;
				break;
			}

		}
	}
};
