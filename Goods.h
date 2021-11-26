#pragma once
#include<iostream>
#include<string>
using namespace std;
class Goods
{
protected:
	string barcode;//条形码
	string name;//商品名
	string type;//商品类型

	int repertory;//库存
	double purchase_price;//进货价
	double sale_price;//销售价

	//记录利润
	double money;
	friend class GoodsManage_Employee;         
	friend class GoodsManage_Administrator;
	friend class Supermarket;
	template<typename t>
	friend void sortnum(t*& a, int& size);
	template<typename t>
	friend void sortmoney(t*& a, int& size);
public:
	Goods(string i, string n, string t, int r, double p, double s);
	virtual ~Goods()
	{

	}
	Goods()
	{

	}
	//展示商品信息(售货人界面)
	void show1();
	//展示商品信息（管理员界面）
	void show2();
};