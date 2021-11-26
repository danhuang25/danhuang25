#pragma once
#include<iostream>
#include<string>
using namespace std;
class LogUser                               //普通员工类
{
protected:

    string name;                            //员工姓名
    string userId;                          //员工唯一ID(账号)
    string userPassword;                    //登录密码
    string userLevel;                       //权限(管理员、售货员)
    double money;                           //销售额 

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
