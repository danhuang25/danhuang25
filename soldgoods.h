#pragma once
#include"Goods.h"
#include"drink.h"
#include"deli.h"
#include"snack.h"
class soldgoods :public drink,public deli,public snack
{
protected:
	//��¼����ʱ��
	string time; 
	//��¼����Ա����
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