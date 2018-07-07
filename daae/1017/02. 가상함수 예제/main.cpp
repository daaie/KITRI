#include <iostream>
using namespace std;

class monster
{
public :
	virtual void shout()
	{
		cout<<"���� ����!"<<endl;
	}
	virtual void out()
	{
		cout<<"���� ���������"<<endl;
	}
};

class vampire : public monster
{
public : 
	void shout()
	{
		cout<<"�����̾� ����! �ǰ� �ʿ���...."<<endl;
	}
	void out()
	{
		cout<<"�����̾� ���������"<<endl;
	}
};

class wolf : public monster
{
public :
	void shout()
	{
		cout<<"�۸۸�"<<endl;
	}
};

class boss_wolf : public wolf
{
public : 
	void shout()
	{
		cout<<"�����ΰ� �����̴�!!!!"<<endl;
	}
};

void main()
{
	monster mon1;
	mon1.shout();

	vampire vam1;
	vam1.shout();

	monster *mon2 = new monster;
	mon2-> shout();
    delete mon2;

	monster *mon3 = new vampire;
	mon3-> shout();

	wolf wol1;
	monster *mon4 = new wolf;
	mon4->shout();
	delete mon4;

	monster *mon5 = new boss_wolf;   //�ڽ��� �ڽı��� ����� ����
	mon5->shout();

	monster *vam2= new vampire;
	vam2->shout();
	vam2->out();

}

