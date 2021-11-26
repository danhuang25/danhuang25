#pragma once
#include"GoodsManage_Employee.h"
#include"LogAdministrator.h"
#include"Sortnum.h"
#include"LogUser.h"
#include"Sortmoney.h"
class GoodsManage_Administrator :public GoodsManage_Employee
{
protected:
    int delinum, snacknum, drinknum;
    deli* delis;
    drink* drinks;
    snack* snacks;
    LogUser* logusers;//记录员工的数组
    int usernum;

public:
    GoodsManage_Administrator();
    ~GoodsManage_Administrator();

//*********************************文件操作
   //将员工数组保存至文件
    void savestaff();
    //获取Usrs 个数
    int getusernum();

//***********************************功能
     //显示账单
    void showBills();  
                                 
     //增加员工功能
    void addUser();                                        

    //展示员工的功能
    void showstaff(LogUser* my);
   
    //删除员工功能
    void delestaff();

    //账本
    void  account();

    //输入条码修改商品信息功能
    void modify();

    //增加商品功能
    void addgoods();

    //输入条码查询商品信息功能
    void showByIndex();

    //输出全部商品信息功能
    void showall();

    //删除商品信息功能
    void delegood();
    
    //对员工销售额进行排序
    void staffs();

    //比较时间大小,a<=b;
    bool comparetime(string a, string b);
    //*********************界面
    //总界面
    virtual void showMenu( LogUser* log);

    //查看商品界面（输入1的界面）
    void showgoods();

    //管理员界面(输入的界面)
    void showstaffs(LogUser* my);


};