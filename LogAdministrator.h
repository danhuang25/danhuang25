#pragma once
#include"LogUser.h"
class LogAdministrator : public LogUser                     //����Ա����
{
protected:

public:
    LogAdministrator(string n, string ui, string up, string ul);
    void addUser();                                          //����Ա���еĴ���Ա���˺Ź���
};
