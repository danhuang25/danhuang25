#pragma once
#include<iostream>
#include<string>
using namespace std;
class Goods
{
protected:
	string barcode;//������
	string name;//��Ʒ��
	string type;//��Ʒ����

	int repertory;//���
	double purchase_price;//������
	double sale_price;//���ۼ�

	//��¼����
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
	//չʾ��Ʒ��Ϣ(�ۻ��˽���)
	void show1();
	//չʾ��Ʒ��Ϣ������Ա���棩
	void show2();
};