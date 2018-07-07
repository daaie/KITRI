extern int hNum;
extern int pos_x,pos_y;

class draw 
{
public :
	void show_map(int &stage_num);
	void stage_acc(int stage_num, int count);
	void read_ending();
	void textcolor(int color_number);
};
