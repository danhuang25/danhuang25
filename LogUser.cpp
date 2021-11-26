#include"LogUser.h"
LogUser::LogUser(string n, string ui, string up, string ul) :name(n), userId(ui), userPassword(up), userLevel(ul)
{

}

ostream& operator<<(ostream& out, LogUser& obj)
{
    out << obj.name << obj.userId << obj.userPassword << obj.userLevel;
    return out;
}

istream& operator>>(istream& in, LogUser& obj)
{
    in >> obj.name >> obj.userId >> obj.userPassword >> obj.userLevel;
    return in;
}

