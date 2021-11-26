#include"deli.h"
deli::deli(string i, string n, string t,int r, double p, double s):Goods(i,  n, t ,r,  p,  s)
{
}

deli::deli(string i, string n, string t, int r, double p, double s, double m) : Goods(i, n, t, r, p, s)
{
	money = m;
}
