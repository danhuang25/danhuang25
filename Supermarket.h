#pragma once
#include"GoodsManage_Administrator .h"
class Supermarket:public GoodsManage_Administrator
{
protected:
    LogUser *user=nullptr ;


public:
    void Welcome();
    void showmenu();
    Supermarket();
    ~Supermarket();
};