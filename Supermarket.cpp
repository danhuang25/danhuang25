#include"Supermarket.h"
#include"conio.h"





void Supermarket::Welcome()
{
    system("cls");
    for (int i = 0; i < 24; i++) cout << "●";
    puts("");
    cout << setw(46) << left << "●" << "●" << endl;
    cout << setw(16) << left << "●" << setw(2) << "欢迎" << setw(14) << user->name << setw(14) << right << "●" << endl;
    cout << setw(46) << left << "●" << "●" << endl;
    cout << setw(10) << left << "●" << setw(2) << "正在进入超市管理系统" << "(权限:" << user->userLevel << ")" << setw(5) << right << "●" << endl;
    cout << setw(46) << left << "●" << "●" << endl;
    cout << setw(46) << left << "●" << "●" << endl;
    for (int i = 0; i < 24; i++) cout << "●";
    puts("");
    cout << "加载数据中";
    for (int i = 0; i < 6; i++)
    {
        cout << ".";
        Sleep(250);
    }
}

Supermarket::Supermarket()
{
}

Supermarket::~Supermarket()
{
}
void Supermarket::showmenu()
{
    while (1)
    {
        ifstream in;
        string Log_Id, Log_Password;
        string name, userId, userPassword, userLevel;

        while (1)
        {
            if (user != NULL)
            {
                delete user;
                user = NULL;
            }

            in.open("Users.txt");
            system("cls");
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "欢迎来到超市管理系统" << setw(12) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << ".....请登录....." << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "账号输入0退出系统" << setw(15) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            cout << "账号:";
            cin >> Log_Id;
            if (Log_Id == "0")
            {
                system("cls");
                for (int i = 0; i < 24; i++) cout << "●";
                puts("");
                cout << setw(46) << left << "●" << "●" << endl;
                cout << setw(16) << left << "●" << setw(16) << "欢迎下次继续使用" << setw(16) << right << "●" << endl;
                cout << setw(46) << left << "●" << "●" << endl;
                for (int i = 0; i < 24; i++) cout << "●";
                puts("");
                cout <<"正在退出";
                for (int i = 0; i < 6; i++)
                {
                    cout << ".";
                    Sleep(500);
                }
                return;
            }
            cout << "密码:";
            char c;
            int count = 0;
            char* password = new char[50]; // 动态申请空间
            while ((c = _getch()) != '\r')
            {

                if (c == 8) { // 退格
                    if (count == 0) {
                        continue;
                    }
                    putchar('\b'); // 回退一格
                    putchar(' '); // 输出一个空格将原来的*隐藏
                    putchar('\b'); // 再回退一格等待输入
                    count--;
                }
                if (count == 49) { // 最大长度为49
                    continue;
                }
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
                    putchar('*');  // 接收到一个字符后, 打印一个*
                    password[count] = c;
                    count++;
                }
            }
            password[count] = '\0';
            Log_Password = password;
            delete[] password; // 释放空间

            cout << endl;
            int sign = 1;
            if (!in)
            {
                cout << "Users.txt error!" << endl;
                abort();
            }
            else
            {
                while (!in.eof())
                {
                    in >> name >> userId >> userPassword >> userLevel;
                    if (Log_Id == userId && Log_Password == userPassword)
                    {
                        sign = 0;
                        if (userLevel == "管理员")
                        {
                            user = new LogUser(name, userId, userPassword, userLevel);
                        }
                        else
                        {
                            user = new LogUser(name, userId, userPassword, userLevel);
                        }

                        break;
                    }
                }
                in.close();

            }
            if (sign)
            {
                cout << "账号或密码错误！重新登录";
                for (int i = 0; i < 6; i++)
                {
                    cout << ".";
                    Sleep(250);
                    continue;
                }
            }
            else break;           
        }
        Welcome();
        if (user->userLevel == "管理员")
        {
                GoodsManage_Administrator::showMenu(user);
        }
        else
        {
            GoodsManage_Employee::showMenu(user);
        }

   }
}

