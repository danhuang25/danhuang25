#pragma once
#include"LogUser.h"
class LogAdministrator : public LogUser                     //管理员工类
{
protected:

public:
    LogAdministrator(string n, string ui, string up, string ul);
    void addUser();                                          //管理员特有的创建员工账号功能
};
