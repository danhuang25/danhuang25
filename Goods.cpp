#include"Goods.h"

Goods::Goods(string i, string n, string t,int r, double p, double s)
{
	barcode = i;
	name = n;  
	repertory = r;
	purchase_price = p;
	sale_price = s;
	type = t;
}

void Goods::show1()
{
	cout << barcode << "\t" << name << "\t\t" <<type<<"\t\t"<<
		repertory << "\t" << sale_price << "\t" << endl;
}
void Goods::show2()
{
	cout << barcode << "\t" << name << "\t\t" << type << "\t\t" <<
		repertory << "\t" << purchase_price << "\t" << sale_price << "\t" << endl;
}
