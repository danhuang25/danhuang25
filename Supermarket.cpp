#include"Supermarket.h"
#include"conio.h"





void Supermarket::Welcome()
{
    system("cls");
    for (int i = 0; i < 24; i++) cout << "��";
    puts("");
    cout << setw(46) << left << "��" << "��" << endl;
    cout << setw(16) << left << "��" << setw(2) << "��ӭ" << setw(14) << user->name << setw(14) << right << "��" << endl;
    cout << setw(46) << left << "��" << "��" << endl;
    cout << setw(10) << left << "��" << setw(2) << "���ڽ��볬�й���ϵͳ" << "(Ȩ��:" << user->userLevel << ")" << setw(5) << right << "��" << endl;
    cout << setw(46) << left << "��" << "��" << endl;
    cout << setw(46) << left << "��" << "��" << endl;
    for (int i = 0; i < 24; i++) cout << "��";
    puts("");
    cout << "����������";
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
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "��ӭ�������й���ϵͳ" << setw(12) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << ".....���¼....." << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "�˺�����0�˳�ϵͳ" << setw(15) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            cout << "�˺�:";
            cin >> Log_Id;
            if (Log_Id == "0")
            {
                system("cls");
                for (int i = 0; i < 24; i++) cout << "��";
                puts("");
                cout << setw(46) << left << "��" << "��" << endl;
                cout << setw(16) << left << "��" << setw(16) << "��ӭ�´μ���ʹ��" << setw(16) << right << "��" << endl;
                cout << setw(46) << left << "��" << "��" << endl;
                for (int i = 0; i < 24; i++) cout << "��";
                puts("");
                cout <<"�����˳�";
                for (int i = 0; i < 6; i++)
                {
                    cout << ".";
                    Sleep(500);
                }
                return;
            }
            cout << "����:";
            char c;
            int count = 0;
            char* password = new char[50]; // ��̬����ռ�
            while ((c = _getch()) != '\r')
            {

                if (c == 8) { // �˸�
                    if (count == 0) {
                        continue;
                    }
                    putchar('\b'); // ����һ��
                    putchar(' '); // ���һ���ո�ԭ����*����
                    putchar('\b'); // �ٻ���һ��ȴ�����
                    count--;
                }
                if (count == 49) { // ��󳤶�Ϊ49
                    continue;
                }
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // ����ֻ�ɰ������ֺ���ĸ
                    putchar('*');  // ���յ�һ���ַ���, ��ӡһ��*
                    password[count] = c;
                    count++;
                }
            }
            password[count] = '\0';
            Log_Password = password;
            delete[] password; // �ͷſռ�

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
                        if (userLevel == "����Ա")
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
                cout << "�˺Ż�����������µ�¼";
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
        if (user->userLevel == "����Ա")
        {
                GoodsManage_Administrator::showMenu(user);
        }
        else
        {
            GoodsManage_Employee::showMenu(user);
        }

   }
}

