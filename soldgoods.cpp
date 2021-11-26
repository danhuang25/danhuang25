#include"soldgoods.h"
soldgoods::soldgoods(string ti, string sa, string i, string n, string t, int r, double p, double s)
{
	barcode = i;
	name = n;
	repertory = r;
	purchase_price = p;
	sale_price = s;
	type = t;
	time = ti;
	saleman = sa;
}
