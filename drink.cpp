#include"drink.h"
drink::drink(string i, string n, string t, int r, double p, double s) :Goods(i, n, t, r, p, s)
{
}

drink::drink(string i, string n, string t, int r, double p, double s, double m) : Goods(i, n, t, r, p, s)
{
	money = m;
}
