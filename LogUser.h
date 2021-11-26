#pragma once
#include<iostream>
#include<string>
using namespace std;
class LogUser                               //��ͨԱ����
{
protected:

    string name;                            //Ա������
    string userId;                          //Ա��ΨһID(�˺�)
    string userPassword;                    //��¼����
    string userLevel;                       //Ȩ��(����Ա���ۻ�Ա)
    double money;                           //���۶� 

    friend class GoodsManage_Employee;
    friend class GoodsManage_Administrator;
    friend class Supermarket;
    template<typename t>
    friend void sortnum(t*& a, int& size);
    template<typename t>
    friend void sortmoney(t*& a, int& size);
public:
    LogUser(string n, string ui, string up, string ul);
    friend ostream& operator<<(ostream& out, LogUser& obj);
    friend istream& operator>>(istream& in, LogUser& obj);
    LogUser()
    {

    }

};
