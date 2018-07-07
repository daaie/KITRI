#include <iostream>
#include "product.h"
using namespace std;

void main()
{
	Buyer b;

	Tv tv;
	Audio audio;
	Computer computer;

	b.buy(&tv);
	b.buy(&audio);
	b.buy(&computer);
	b.buy(&tv);
	b.buy(&computer);
	b.buy(&audio);
	b.buy(&tv);
}
