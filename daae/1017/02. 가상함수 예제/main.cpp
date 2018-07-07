#include <iostream>
using namespace std;

class monster
{
public :
	virtual void shout()
	{
		cout<<"¸ó½ºÅÍ µîÀå!"<<endl;
	}
	virtual void out()
	{
		cout<<"¸ó½ºÅÍ Ãâ·ÂÀÌÁö·Õ"<<endl;
	}
};

class vampire : public monster
{
public : 
	void shout()
	{
		cout<<"¹ìÆÄÀÌ¾î µîÀå! ÇÇ°¡ ÇÊ¿äÇØ...."<<endl;
	}
	void out()
	{
		cout<<"¹ìÆÄÀÌ¾î Ãâ·ÂÀÌÁö·Õ"<<endl;
	}
};

class wolf : public monster
{
public :
	void shout()
	{
		cout<<"¸Û¸Û¸Û"<<endl;
	}
};

class boss_wolf : public wolf
{
public : 
	void shout()
	{
		cout<<"´Á´ëÀÎ°£ ´ëÀåÀÌ´ç!!!!"<<endl;
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

	monster *mon5 = new boss_wolf;   //ÀÚ½ÄÀÇ ÀÚ½Ä±îÁö ½ÇÇàµÊ ´ú´ú
	mon5->shout();

	monster *vam2= new vampire;
	vam2->shout();
	vam2->out();

}

