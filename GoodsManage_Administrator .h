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
    LogUser* logusers;//��¼Ա��������
    int usernum;

public:
    GoodsManage_Administrator();
    ~GoodsManage_Administrator();

//*********************************�ļ�����
   //��Ա�����鱣�����ļ�
    void savestaff();
    //��ȡUsrs ����
    int getusernum();

//***********************************����
     //��ʾ�˵�
    void showBills();  
                                 
     //����Ա������
    void addUser();                                        

    //չʾԱ���Ĺ���
    void showstaff(LogUser* my);
   
    //ɾ��Ա������
    void delestaff();

    //�˱�
    void  account();

    //���������޸���Ʒ��Ϣ����
    void modify();

    //������Ʒ����
    void addgoods();

    //���������ѯ��Ʒ��Ϣ����
    void showByIndex();

    //���ȫ����Ʒ��Ϣ����
    void showall();

    //ɾ����Ʒ��Ϣ����
    void delegood();
    
    //��Ա�����۶��������
    void staffs();

    //�Ƚ�ʱ���С,a<=b;
    bool comparetime(string a, string b);
    //*********************����
    //�ܽ���
    virtual void showMenu( LogUser* log);

    //�鿴��Ʒ���棨����1�Ľ��棩
    void showgoods();

    //����Ա����(����Ľ���)
    void showstaffs(LogUser* my);


};