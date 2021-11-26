#include"LogAdministrator.h"
#include<fstream>

LogAdministrator::LogAdministrator(string n, string ui, string up, string ul) :LogUser(n, ui, up, ul)
{

}

void LogAdministrator::addUser()
{
    ofstream out("Users.txt", ios::app);
    if (!out)
    {
        cout << "Users.txt error!" << endl;
        abort();
    }
    else
    {
        system("cls");
        string name, userId, userPassword, userLevel;
        cout << "����Ա����Ϣ:" << endl;
        cout << "����:";
        cin >> name;
        cout << "ID:";
        cin >> userId;
        cout << "����:";
        cin >> userPassword;
        cout << "Ȩ��:";
        cin >> userLevel;
        out << name << "\t" << userId << "\t" << userPassword << "\t" << userLevel << "\n";
        out.close();
    }
}
