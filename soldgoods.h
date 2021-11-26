#pragma once
#include"Goods.h"
#include"drink.h"
#include"deli.h"
#include"snack.h"
class soldgoods :public drink,public deli,public snack
{
protected:
	//记录卖出时间
	string time; 
	//记录销售员姓名
	string saleman;
	friend class GoodsManage_Employee;
	friend class GoodsManage_Administrator;
	friend class Supermarket;
public:
	soldgoods(string ti,string sa,string i, string n, string t, int r, double p, double s);
	soldgoods()
	{

	}

};