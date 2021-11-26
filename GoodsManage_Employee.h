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

class GoodsManage_Employee            //��Ʒ������(�ۻ�Ա)
{
protected:
    int goodsnums;                      //��¼��Ʒ����  
    Goods** goods;                      //�洢������Ϣ������ָ��              
    soldgoods* shopping_Cart;              //�洢���ﳵ��Ϣ��ָ������
    GoodsManage_Employee();
    ~GoodsManage_Employee();
public:
//*************************ʵ�ֹ��ܵĺ���


    //���������ѯ��Ʒ��Ϣ����
    void showByIndex();

        //���ȫ����Ʒ��Ϣ����
    void showall();

    //���۹��ܼ��ڲ�����
    void sell(LogUser *log);

    //��ȡ�˵�ʱ��
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
    //��ӡ�˵���Ҫ����ʱ������
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



//*******************�ļ������ĺ���
 
    //�����������ļ�
    void save();

    //���������������ļ�
    void billsave(int num);

    //����ļ���Ʒ����
    int getnum(); 

    //��ʼ�����ļ��ڶ�ȡԱ����������
    void inint();

//************************����ӿ�  

    //�ۻ�Ա�ӽǲ˵�������㣩
     virtual void showMenu( LogUser *log);    

    //�鿴��Ʒ���棨����1�Ľ��棩
    void showgoods();
};
