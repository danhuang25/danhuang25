#pragma once
#include"Goods.h"
class drink : virtual public Goods
{
protected:

	static int num;// ��¼�����е���Ʒ����
	friend class GoodsManage_Employee;
	friend class GoodsManage_Administrator;
	friend class Supermarket;
	template<typename t>
	friend void sortnum(t*& a, int& size);
	template<typename t>
	friend void sortmoney(t*& a, int& size);
public:
	~drink()
	{

	}
	drink()
	{

	}
	drink(string i, string n, string t, int r, double p, double s, double m);
	drink(string i, string n, string t, int r, double p, double s);
};
