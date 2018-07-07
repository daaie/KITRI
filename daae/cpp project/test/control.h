extern int input;
extern int hNum;

class gameControl
{
	int count;
	int pos_x,pos_y;

public :

	gameControl()
	{
		count=0;
		pos_x=0;
		pos_y=0;
	}
	void textcolor(int color_number);
	void show_map(int &stage_num);
	void stage_acc(int stage_num, int count);
	void position_xy(int x,int y);
	void start_map(int &stage_num);
	void control();
	void game(int &stage_num);	
	void read_ending();

};
