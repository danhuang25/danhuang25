#pragma once
#include"LogUser.h"
#include"deli.h"
#include"drink.h"
#include"Goods.h"
#include"snack.h"
#include"soldgoods.h"
#include<iomanip>
#include"fstream"
#include"GetSystemTime.h"
#include<stdio.h>

class GoodsManage_Employee            //商品管理类(售货员)
{
protected:
    int goodsnums;                      //记录商品数量  
    Goods** goods;                      //存储货物信息的数组指针              
    soldgoods* shopping_Cart;              //存储购物车信息的指针数组
    GoodsManage_Employee();
    ~GoodsManage_Employee();
public:
//*************************实现功能的函数


    //输入条码查询商品信息功能
    void showByIndex();

        //输出全部商品信息功能
    void showall();

    //出售功能加内部界面
    void sell(LogUser *log);

    //获取账单时间
    string GetSystemTime()
    {
        SYSTEMTIME m_time;
        GetLocalTime(&m_time);
        char szDateTime[100] = { 0 };
        sprintf_s(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,
            m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
        string time(szDateTime);
        return time;
    }
    //打印账单需要的以时间命名
    string GetSystemTime1()
    {
        SYSTEMTIME m_time;
        GetLocalTime(&m_time);
        char szDateTime[100] = { 0 };
        sprintf_s(szDateTime, "%02d-%02d-%02d %02d-%02d-%02d", m_time.wYear, m_time.wMonth,
            m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
        string time(szDateTime);
        return time;
    }



//*******************文件操作的函数
 
    //更新数组至文件
    void save();

    //更新售卖货物至文件
    void billsave(int num);

    //获得文件商品数量
    int getnum(); 

    //初始化从文件内读取员工至数组内
    void inint();

//************************界面接口  

    //售货员视角菜单（最外层）
     virtual void showMenu( LogUser *log);    

    //查看商品界面（输入1的界面）
    void showgoods();
};
