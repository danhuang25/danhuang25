#include"GoodsManage_Administrator .h"
#include"Sortnum.h"
#include"Sortmoney.h"
GoodsManage_Administrator::GoodsManage_Administrator()
{
    usernum = getusernum();
    logusers = new LogUser[usernum];
    //����Ա������
    ifstream in("Users.txt");
    if (!in)
    {
        cout << "Users.txt error!" << endl;
        abort();
    }
    else
    {
        string name, userId, userPassword, userLevel;
        int i = 0;
        while (in >> name >> userId >> userPassword >> userLevel)
        {

            LogUser* temp = NULL;
            temp = new LogUser(name, userId, userPassword, userLevel);
            logusers[i++] = *temp;
            if (in.eof())break;

        }
    }
    in.close();

}

GoodsManage_Administrator :: ~GoodsManage_Administrator()
{
    if (logusers != NULL)
        delete[] logusers;
    if (snacks != NULL)
        delete[]snacks;
    if (drinks != NULL)
        delete[]drinks;
    if (delis != NULL)
        delete[]delis;
}
int GoodsManage_Administrator::getusernum()
{
    string Log_Id, Log_Password;
    string name, userId, userPassword, userLevel;
    int num = 0;
    fstream in("Users.txt", ios::in);
    while (in >> name >> userId >> userPassword >> userLevel)
    {
        num++;
    }
    in.close();
    return num;
}
void GoodsManage_Administrator::savestaff()
{
    ofstream ofs;
    // out << name << " " << userId << " " << userPassword << " " << userLevel << endl;
    ofs.open("Users.txt", ios::out);
    //����Ա������д�뵽�ļ���
    for (int i = 0; i < usernum; i++)
    {
        ofs << logusers[i].name << " "
            << logusers[i].userId << " "
            << logusers[i].userPassword << " "
            << logusers[i].userLevel << endl;

    }
    ofs.close();
}
bool GoodsManage_Administrator::comparetime(string a, string b)
{
    for (int i = 0; i < 10; i++)
    {

        if (a[i] == b[i])continue;
        else if (a[i] < b[i])return true;
        else if (a[i] > b[i])return false;
    }
    return true;
}


void GoodsManage_Administrator::modify()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(13) << left << "��" << setw(22) << "��������������޸���Ʒ" << setw(13) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        cout << endl;

        //չʾ�е���Ʒ
        cout << "��Ʒ��������Ϊ��" << goodsnums << "\t" << "С���ࣺ" << snack::num << "\t" << "�����ࣺ" << drink::num << "\t" << "��ʳ�ࣺ" << deli::num << endl;
        cout << endl;
        cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
        for (int i = 0; i < goodsnums; i++)
        {
            goods[i]->show2();
        }

        //�ҵ���Ӧ����
        string barcode;
        cin >> barcode;

        //�����㷵��
        if (barcode == "0")
            return;

        int n = goodsnums, i, sign = 1;
        for (i = 0; i < n; i++)
        {
            if (goods[i]->barcode == barcode||goods[i]->name==barcode)
            {
                sign = 0;
                break;
            }
        }
        if (sign)
        {
            cout << "δ��ѯ����Ӧ��Ʒ��Ϣ!����������!" << endl;
            continue;
        }


        while (1)
        {
            system("cls");
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����1�޸Ľ�����" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;;
            cout << setw(16) << left << "��" << setw(16) << "����2�޸����ۼ�" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����3�޸Ŀ��" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            for (int i = 0; i < 24; i++) cout << "��";
            cout << endl;

            cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
            goods[i]->show2();

            int choice;
             cin >> choice;
             if (choice == 1)
             {

                 double temp;
                 cout << "������" << endl;
                 cin >> temp;
                 goods[i]->purchase_price = temp;
                 cout << "�޸����" << endl;
                 system("pause");
                 system("cls");
                 continue;
             }

             else if (choice == 2)
             {
                 double temp;
                 cout << "������" << endl;
                 cin >> temp;
                 goods[i]->sale_price = temp;
                 cout << "�޸����" << endl;
                 system("pause");
                 system("cls");
                 continue;
             }
             else if (choice == 3)
             {
                 int  temp;
                 cout << "������ӵ�����" << endl;
                 cin >> temp;
                 goods[i]->repertory += temp;
                 cout << "�޸����" << endl;
                 system("pause");
                 system("cls");
                 continue;
             }
             else if (choice == 0)
             {
                 save();
                 break;
             }
             else
             {
                 cout << "������������������" << endl;
                 system("pause");
             }
        }
    }
}       
void GoodsManage_Administrator::addgoods()
{

    system("cls");
    for (int i = 0; i < 24; i++) cout << "��";
    puts("");
    cout << setw(46) << left << "��" << "��" << endl;
    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
    cout << setw(46) << left << "��" << "��" << endl;
    for (int i = 0; i < 24; i++) cout << "��";
    cout << endl;
    cout << "������Ʒ��������" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {

        //��������¿ռ��С
        int newSize = goodsnums + addNum;
        // �����¿ռ�
        Goods** newSpace = new Goods * [newSize];
        //��ԭ���ݿ����µ�����
        if (goods != NULL)
        {
            for (int i = 0; i < goodsnums; i++)
            {
                newSpace[i] = goods[i];
            }
        }
        for (int i = 0; i < addNum; i++)
        {
            int repertory, sign = 1;
            string name, type, barcode;
            double purchase_price, sale_price;
            cout << "�������" << i + 1 << "����Ʒ���룺 " << endl;
            cin >> barcode;
            for (int j = 0; j < goodsnums+i; j++)
            {
                if (barcode == goods[j]->barcode)
                {
                    cout << "���������" << endl;
                    cout << "����Ϣ���£�" << endl;
                    cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" <<"�ۼ�" << endl;
                    goods[j]->show2();
                    cout << "����������" << endl;
                    i--;
                    sign = 0;
                    break;
                   
                }
            }
            if (!sign)continue;
            cout << "�������" << i + 1 << "����Ʒ���ƣ� " << endl;
            cin >> name;

            for (int j = 0; j < goodsnums + i; j++)
            {
                if (name == goods[j]->name)
                {
                    cout << "�����ƴ���" << endl;
                    cout << "����Ϣ���£�" << endl;
                    cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
                    goods[j]->show2();
                    cout << "����������" << endl;
                    i--;
                    sign = 0;
                    break;
                  
                }
            }
            if (!sign)continue;
            cout << "�������" << i + 1 << "����Ʒ���ͣ���ʳ�ࡢ�����ࡢ��ʳ�ࣩ�� " << endl;
            cin >> type;
            while (type != "��ʳ��" && type != "������" && type != "��ʳ��")
            {
                cout <<"�������" << "�����������" << i + 1 << "����Ʒ���ͣ���ʳ�ࡢ�����ࡢ��ʳ�ࣩ�� " << endl;
                cin >> type;
            }
            cout << "�������" << i + 1 << "����Ʒ��棺 " << endl;
            cin >> repertory;
            cout << "�������" << i + 1 << "����Ʒ�����ۣ� " << endl;
            cin >> purchase_price;
            cout << "�������" << i + 1 << "����Ʒ�ۼۣ� " << endl;
            cin >> sale_price;

            Goods* temp = NULL;
            if (type == "��ʳ��")
            {
                temp = new snack(barcode, name, type, repertory, purchase_price, sale_price);
                snack::num++;
            }
            else if (type == "������")
            {
                temp = new drink(barcode, name, type, repertory, purchase_price, sale_price);
                drink::num++;
            }
            else if (type == "��ʳ��")
            {
                temp = new deli(barcode, name, type, repertory, purchase_price, sale_price);
                deli::num++;
            }

            //����������Ʒ�����������
            newSpace[goodsnums + i] = temp;
        }
        delete[]goods;
        goods = newSpace; //�����¿ռ��ָ��
        //�����µ�ְ������
        goodsnums = newSize;
        //�������ݵ��ļ���
        save();
        // ��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "����Ʒ" << endl;
        //��������� �����ص��ϼ�Ŀ¼
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��������" << endl;
    }
}
void GoodsManage_Administrator::delegood()
{
    while (1)
    {
        system("cls");
        //����
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(13) << left << "��" << setw(22) << "�������������ɾ����Ʒ" << setw(13) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;

        for (int i = 0; i < 24; i++) cout << "��";
        cout << endl;
        //չʾ�е���Ʒ
        cout << "��Ʒ��������Ϊ��" << goodsnums << "\t" << "С���ࣺ" << snack::num << "\t" << "�����ࣺ" << drink::num << "\t" << "��ʳ�ࣺ" << deli::num << endl;
        cout << endl;
        cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
        for (int i = 0; i < goodsnums; i++)
        {
            goods[i]->show2();
        }

        string id;
        cin >> id;
        if (id == "0")
        {
            save();
            break;
        }
        int i = 0;
        int sign = 1;
        for (i; i < goodsnums; i++)
        {
            if (goods[i]->name == id || goods[i]->barcode == id)
            {
                sign = 0;
                break;
            }
        }
        if (sign)
        {
            cout << "û�и���Ʒ������������" << endl;
            system("pause");
            continue;
        }
        for (i; i < goodsnums - 1; i++)
        {
            goods[i] = goods[i + 1];
        }
        goodsnums--;
        cout << " ɾ���ɹ�" << endl;
        system("pause");
    }
}
void GoodsManage_Administrator::showByIndex()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(13) << left << "��" << setw(13) << "������������Ʋ鿴��Ʒ" << setw(13) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����1����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        cout << endl;
        string barcode;

        cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
        while (1)
        {
            cin >> barcode;
            if (barcode == "0")
            {
                return;
            }
            else if (barcode == "1")
            {
                break;
            }

            int n =goodsnums, i;
            for (i = 0; i < n; i++)
            {
                if (goods[i]->barcode == barcode || goods[i]->name == barcode)
                {
                    goods[i]->show2();
                    break;
                }
            }
            if (i == n)
            {
                cout << "δ��ѯ����Ӧ��Ʒ��Ϣ!��������ȷ������!" << endl;
            }
        }
    }
}
void GoodsManage_Administrator::showall()
{
    {
        system("cls");
        cout << "��Ʒ��������Ϊ��" << goodsnums << "\t" << "С���ࣺ" << snack::num << "\t" << "�����ࣺ" << drink::num << "\t" << "��ʳ�ࣺ" << deli::num << endl;
        cout << endl;
        cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "����\t" << "�ۼ�" << endl;
        for (int i = 0; i < goodsnums; i++)
        {
            goods[i]->show2();
        }

    }
}

void GoodsManage_Administrator::staffs()
{
    double purchase_price, sale_price, money;
    string time1, barcode, name, salename, time2, type;
    int  repertory;
    //Ա������
    int n = getusernum();
    //��ʼ�����۶�Ϊ��
    for (int i = 0; i < n; i++)
        logusers[i].money = 0;
    ifstream in("Bills.txt");
    if (!in)
    {
        cout << "Bills.txt error!" << endl;
        abort();
    }
    else
    {
        while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
        {
            for (int i = 0; i < n; i++)
            {
                if (logusers[i].name == salename)
                {
                    logusers[i].money += money;
                    break;
                }
            }
        }
        sortmoney(logusers, n);
        cout << "����\t\t" << "���۶�\t\t" << endl;
        for (int i = 0; i < n; i++)
        {

            cout << logusers[i].name <<"\t\t" << logusers[i].money << endl;
        }
    }
}
void GoodsManage_Administrator:: account()
{
    system("cls");
    //��֤�Ǹ��µ�
    //�������޸ļ۸��ѡ�һ����Ʒ���������ּ۸�������Ϊ������Ʒ���ۺϿ��ǣ��������������С
    delinum = 2 * deli::num;
    snacknum = 2 * snack::num;
    drinknum = 2 * drink::num;
    snacks = new snack[snacknum];
    drinks = new drink[drinknum];
    delis = new deli[delinum];
    double purchase_price, sale_price, money;
    string time1, barcode, name, salename, time2, type;
    int  repertory;
    //���˵��е�ÿ����Ʒ���浽����������
        int i = 0, j = 0, k = 0;
        ifstream in("Bills.txt");
        if (!in)
        {
            cout << "Bills.txt error!" << endl;
            abort();
        }
        else
        {
            while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
            {
                if (type == "��ʳ��")
                {
                    int sign=1;
                    for (int i1 = 0; i1 < i; i1++)
                    {
                        if (name == snacks[i1].name && purchase_price == snacks[i1].purchase_price && sale_price == snacks[i1].sale_price)
                        {
                            snacks[i1].repertory += repertory;
                            snacks[i1].money += money;
                            sign = 0;
                            break;
                        }
                    }
                    if (sign)
                    {
                        snack* temp = NULL;
                        temp = new snack(barcode, name, type, repertory, purchase_price, sale_price ,money);
                        snacks[i++] = *temp;
                    }
                }
                else if (type == "������")
                {
                    int sign = 1;
                    for (int j1 = 0; j1 < j; j1++)
                    {
                        if (name == drinks[j1].name && purchase_price == drinks[j1].purchase_price && sale_price == drinks[j1].sale_price)
                        {
                            snacks[j1].repertory += repertory;
                            snacks[j1].money += money;
                            sign = 0;
                            break;
                        }
                    }
                    if (sign)
                    {
                        drink* temp = NULL;
                        temp = new drink(barcode, name, type, repertory, purchase_price, sale_price, money);
                        drinks[j++] = *temp;
                    }
                }
                else if (type == "��ʳ��")
                {
                    int sign = 1;
                    for (int k1 = 0; k1 < k; k1++)
                    {
                        if (name == delis[k1].name && purchase_price == delis[k1].purchase_price && sale_price == delis[k1].sale_price)
                        {
                            delis[k1].repertory += repertory;
                            delis[k1].money += money;
                            sign = 0;
                            break;
                        }
                    }
                    if (sign)
                    {
                        deli* temp = NULL;
                        temp = new deli(barcode, name, type, repertory, purchase_price, sale_price, money);
                        delis[k++] = *temp;
                    }
                }
                if (in.eof())break;
            }
        }
        while (1)
        {
            system("cls");
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "1.��ӯ��������" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "2.������������" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "3.������ԱӪҵ��" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            for (int i = 0; i < 24; i++) cout << "��";
            cout << endl;
            string choice;
            cin >> choice;
            if (choice == "1")
            {
                //��3����Ʒ�����ఴ��������
                sortmoney(snacks, i);
                sortmoney(drinks, j);
                sortmoney(delis, k);
                cout << "С������Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int ii = 0; ii < i; ii++)
                {
                    cout << snacks[ii].barcode << "\t" << snacks[ii].name << "\t\t" << snacks[ii].type << "\t\t" <<
                        snacks[ii].repertory << "\t" << snacks[ii].purchase_price << "\t" << snacks[ii].sale_price << "\t" << snacks[ii].money << endl;
                }
                cout << endl;

                cout << "��������Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int jj = 0; jj < j; jj++)
                {
                    cout << drinks[jj].barcode << "\t" << drinks[jj].name << "\t\t" << drinks[jj].type << "\t\t" <<
                        drinks[jj].repertory << "\t" << drinks[jj].purchase_price << "\t" << drinks[jj].sale_price << "\t" << drinks[jj].money << endl;
                }
                cout << endl;

                cout << "��ʳ����Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int kk = 0; kk < k; kk++)
                {
                    cout << delis[kk].barcode << "\t" << delis[kk].name << "\t\t" << delis[kk].type << "\t\t" <<
                        delis[kk].repertory << "\t" << delis[kk].purchase_price << "\t" << delis[kk].sale_price << "\t" << delis[kk].money << endl;
                }
                system("pause");
            }
            else if (choice == "2")
            {
                sortnum(snacks, i);
                sortnum(drinks, j);
                sortnum(delis, k);
                cout << "С������Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int ii = 0; ii < i; ii++)
                {
                    cout << snacks[ii].barcode << "\t" << snacks[ii].name << "\t\t" << snacks[ii].type << "\t\t" <<
                        snacks[ii].repertory << "\t" << snacks[ii].purchase_price << "\t" << snacks[ii].sale_price << "\t" << snacks[ii].money << endl;
                }
                cout << endl;

                cout << "��������Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int jj = 0; jj < j; jj++)
                {
                    cout << drinks[jj].barcode << "\t" << drinks[jj].name << "\t\t" << drinks[jj].type << "\t\t" <<
                        drinks[jj].repertory << "\t" << drinks[jj].purchase_price << "\t" << drinks[jj].sale_price << "\t" << drinks[jj].money << endl;
                }
                cout << endl;

                cout << "��ʳ����Ʒ����������£�" << endl;
                cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "ӯ��" << endl;
                for (int kk = 0; kk < k; kk++)
                {
                    cout << delis[kk].barcode << "\t" << delis[kk].name << "\t\t" << delis[kk].type << "\t\t" <<
                        delis[kk].repertory << "\t" << delis[kk].purchase_price << "\t" << delis[kk].sale_price << "\t" << delis[kk].money << endl;
                }
                system("pause");
            }
            else if (choice == "3")
            {
                staffs();
                system("pause");
            }
            else if (choice == "0")
                return ;
            else
            {
                cout << "�����������������" << endl;
                system("pause");
                continue;
            }
           
        }
    


   

}
void GoodsManage_Administrator::showBills()
{
    while (1)  
    {
        

            system("cls");
            double purchase_price, sale_price, money;
            string time1, barcode, name, salename, time2, type;
            int  repertory;
            for (int i = 0; i < 25; i++) cout << "��";
            puts("");
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "1.�鿴ĳ���˵�" << setw(18) << right << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "2.�鿴ĳʱ���˵�" << setw(18) << right << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "3.�鿴ĳ����Ʒ�˵�" << setw(16) << right << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "4.�鿴ӪҵԱ���ۼ�¼" << setw(14) << right << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(18) << right << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            cout << setw(48) << left << "��" << "��" << endl;
            for (int i = 0; i < 25; i++) cout << "��";
            puts("");
            int choice;
            cin >> choice;
            //�鿴ĳ���˵�
            if (choice == 1)
            {
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "��";
                    puts("");
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(8) << left << "��" << setw(16) << "����ʽ��Ϊ��2020-01-01 00-00-00��" << setw(7) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    for (int i = 0; i < 24; i++) cout << "��";
                    cout << endl;
                    string temp;
                    cout << "������Ҫ�鿴���˵��ļ�����";
                    getline(cin,temp);
                    if (temp == "0")
                    {

                        break;
                    }
                    temp = temp + ".txt";
                    ifstream in(temp.c_str());
                    in.clear();
                    in.seekg(0, ios::beg);
                    char s[100];
                    in.getline(s, 100);
                    in.getline(s, 100);
                    in.getline(s, 100);
                    cout<< "����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "�ܼ�" << endl;
                    while (in >> barcode >> name >> type >> repertory >> sale_price >> money)
                    {
                        cout <<barcode << "\t" << name << "\t\t" << type << "\t" << repertory << "\t" << sale_price << "\t" << money << endl;
                    }
                    cout << barcode << "\t\t" << name << endl;
                    system("pause");
                    in.close();
                }

            }

            //2.�鿴ĳʱ���˵�
            else if (choice == 2)
            {
                ifstream in("Bills.txt");
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "��";
                    puts("");
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(3) << left << "��" << setw(16) << "������Ҫ��ѯ�����ڣ���ʽ��Ϊ��2020-01-01��" << setw(3) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    for (int i = 0; i < 24; i++) cout << "��";
                    cout << endl;
                    string temp,temp1;
                    cout << "������ʼ���ڣ�";
                    cin >> temp;
                    if (temp == "0")
                    {
                        break;
                    }
                    cout << "�����ֹ���ڣ�";
                    cin >> temp1;
                    double sum = 0;

                    in.clear();
                    in.seekg(0, ios::beg);
                    while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
                    {
                     
                        if (comparetime(temp, time1) && comparetime(time1, temp1))
                        {
                            cout << time1 << "\t" << time2 << "\t" << salename << "\t" << barcode << "\t" << name << "\t" << type << "\t" << repertory
                                << "\t" << purchase_price << "\t" << sale_price << "\t" << money << endl;
                            sum += money;
                        }
                        else if (comparetime(temp, time1))
                            break;
                    }
                    cout << temp <<"��"<<temp1 << "�����۶�Ϊ��" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            //�鿴ĳ����Ʒ�����˵�
            else if (choice == 3)
            {
                ifstream in("Bills.txt");
            
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "��";
                    puts("");
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "��������Ʒ���������" << setw(12) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    for (int i = 0; i < 24; i++) cout << "��";
                    cout << endl;
                    int work = 1;
                    string temp;
                    cin >> temp;
                    string tian;
                    double sum = 0;
                    //�Ƴ���ť
                    if (temp == "0")
                    {
                        break;
                    }
                    int i = 0;
                    for (i; i < goodsnums; i++)
                    {
                        if (temp == goods[i]->name||temp==goods[i]->barcode)
                        {
                            cout << "����Ʒ���ڣ������ۼ�¼Ϊ��" << endl;
                            work = 0;
                            break;
                        }
                    }
                    //���û����Ʒ
                    if (work)
                    {
                        cout << "����Ʒ�����ڣ�����������" << endl;
                        system("pause");
                        continue;
                    }
                    //�������Ʒ����
                    cout << "����\t\t" << "ʱ��\t\t" << "�ۻ�Ա\t" << "����\t" << "��Ʒ��\t" << "����\t" << "����\t" << "������\t" << "������\t" << "����\t" << endl;
                    int n = 0;
                    in.clear();
                    in.seekg(0, ios::beg);
                    while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
                    {
                        if (n == 0)
                        {
                            n++;
                            tian = time1;
                        }
                        if (goods[i]->barcode == barcode || goods[i]->name == name)
                        {
                            cout << time1 << "\t" << time2 << "\t" << salename << "\t" << barcode << "\t" << name << "\t" << type << "\t" << repertory
                                << "\t" << purchase_price << "\t" << sale_price << "\t" << money << endl;
                            sum += money;
                        }
     
                    }
                    cout << "��" << tian << "����" << goods[i]->name << "�����۶�Ϊ��" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            //�鿴ӪҵԱ���ۼ�¼
            else if (choice == 4)
            {
              ifstream in("Bills.txt");
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "��";
                    puts("");
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "������Ҫ��ѯ��ӪҵԱ������" << setw(6) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
                    cout << setw(46) << left << "��" << "��" << endl;
                    for (int i = 0; i < 24; i++) cout << "��";
                    cout << endl;
                    int work = 1;
                    string temp;
                    cin >> temp;
                    string tian;
                    double sum = 0;

                    //�Ƴ���ť
                    if (temp == "0")
                    {
                        break;
                    }
                    int i = 0;
                    for (i; i < usernum; i++)
                    {
                        if (temp == logusers[i].name )
                        {
                            cout << "����Ա���ڣ������ۼ�¼Ϊ��" << endl;
                            work = 0;
                            break;
                        }
                    }
                    //���û�����
                    if (work)
                    {
                        cout << "����Ա�����ڣ�����������" << endl;
                        system("pause");
                        continue;
                    }  
                    //����д��˴���
                    cout << "����\t\t" << "ʱ��\t\t" << "�ۻ�Ա\t" << "����\t" << "��Ʒ��\t" << "����\t" << "����\t" << "������\t" << "������\t" << "����\t" << endl;
                    int n = 0;
                    in.clear();
                    in.seekg(0, ios::beg);
                    while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
                    {
                        //��ȡ�ʼ�������ʱ��
                        if (n == 0)
                        {
                            n++;
                            tian = time1;
                        }
                        if (temp == salename)
                        {
                            cout << time1 << "\t" << time2 << "\t" << salename << "\t" << barcode << "\t" << name << "\t" << type << "\t" << repertory
                                << "\t" << purchase_price << "\t" << sale_price << "\t" << money << endl;
                            sum += money;
                        }
                      
                        if (in.eof())break;
                    }
                    cout << "��" << tian << "����" << temp << "�����۶�Ϊ��" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            else if (choice == 0)return;
            else

            {
                cout << "�����������������" << endl;
                system("pause");
            }
            

    }
}

void GoodsManage_Administrator::addUser()
{
    system("cls");
    for (int i = 0; i < 24; i++) cout << "��";
    puts("");
    cout << setw(46) << left << "��" << "��" << endl;
    cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
    cout << setw(46) << left << "��" << "��" << endl;
    for (int i = 0; i < 24; i++) cout << "��";
    cout << endl;
    cout << "������Ա��������" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {
        //��������¿ռ��С
        int newSize = usernum + addNum;
        // �����¿ռ�
        LogUser* newSpace = new LogUser [newSize];
        //��ԭ���ݿ����µ�����
        if (goods != NULL)
        {
            for (int i = 0; i < usernum; i++)
            {
                newSpace[i] = logusers[i];
            }
        }
        for (int i = 0; i < addNum; i++)
        {
            int sign = 1;
            string name, userId, userPassword, userLevel;
            cout << "�������" << i + 1 << "����Ա����Ϣ:" << endl;
            cout << "����:";
            cin >> name;
            cout << "ID:";       
            cin >> userId;
            //�鿴��ID���ظ�
            for (int j = 0; j < goodsnums + i; j++)
            {
                if (userId == logusers[j].userId)
                {
                    cout << "�ó�Ա����" << endl;
                    cout << "����Ϣ���£�" << endl;
                    cout << "����\t\t" << "ID\t\t" << "����\t\t" << "Ȩ��\t\t" << endl;
                    if (logusers[i].userLevel == "�ۻ�Ա")
                        cout << logusers[i].name << "\t\t" << logusers[i].userId << "\t\t" << logusers[i].userPassword << "\t\t" << logusers[i].userLevel << endl;
                    else cout << "��ID��ԱȨ��Ϊ����Ա�����ɷ���"<<endl;
                    cout << "����������" << endl;
                    i--;
                    sign = 0;
                    break;

                }
            }
            if (!sign)continue;
            cout << "����:";
            cin >> userPassword;
            cout << "Ȩ�ޣ�����Ա���ۻ�Ա��:";
            cin >> userLevel;
            while (userLevel != "����Ա" || userLevel != "�ۻ�Ա")
            {
                cout << "��������ȷȨ��" << endl;
                cin >> userLevel;
            }
               
            LogUser* temp = NULL;
            temp = new LogUser(name, userId, userPassword, userLevel);
            newSpace[usernum + i] = *temp;
        }
        delete[]logusers;

        logusers = newSpace; //�����¿ռ��ָ��
        //�����µ�ְ������
        usernum = newSize;
        savestaff();
   
        // ��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "��Ա��" << endl;
        //��������� �����ص��ϼ�Ŀ¼
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��������" << endl;
    }
}
void GoodsManage_Administrator::showstaff(LogUser* my)
{
    system("cls");
    cout << "����\t\t" << "ID\t\t" << "����\t\t" << "Ȩ��\t\t" << endl;
    for (int i = 0; i < usernum; i++)
    {
        if (logusers[i].userLevel == "�ۻ�Ա")
            cout << logusers[i].name << "\t\t" << logusers[i].userId << "\t\t" << logusers[i].userPassword << "\t\t" << logusers[i].userLevel << endl;
        else if (logusers[i].name == my->name && logusers[i].userId == my->userId)
            cout << logusers[i].name << "\t\t" << logusers[i].userId << "\t\t" << logusers[i].userPassword << "\t\t" << logusers[i].userLevel << endl;
    }
}
void GoodsManage_Administrator::delestaff()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "ֻ��ɾ���ۻ�Ա" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(13) << left << "��" << setw(22) << "����Ҫɾ��Ա����ID" << setw(13) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        cout << endl;
        cout << "����\t\t" << "ID\t\t" << "����\t\t" << "Ȩ��\t\t" << endl;
        for (int i = 0; i < usernum; i++)
        {
            if (logusers[i].userLevel == "�ۻ�Ա")
                cout << logusers[i].name << "\t\t" << logusers[i].userId << "\t\t" << logusers[i].userPassword << "\t\t" << logusers[i].userLevel << endl;
        }
        string id;
        cin >> id;
        if (id == "0")
        {
            savestaff();
            break;
        }
        int i = 0;
        int sign = 1;
        for (i; i < usernum; i++)
        {
            if (logusers[i].userId == id)
            {
                sign = 0;
                break;
            }
        }
        if (sign)
        {
            cout << "�˱��û�ж�Ӧ��Ա��������������" << endl;
            system("pause");
            continue;
        }
        for (i; i < usernum - 1; i++)
        {
            logusers[i] = logusers[i + 1];
        }
        usernum--;
        cout << " ɾ���ɹ�" << endl;
        system("pause");
    }
}




void GoodsManage_Administrator::showgoods()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "1.�鿴������Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "2.��ѯ��Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "3.������Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "4.ɾ����Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "5.�޸���Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "0.����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << "������ִ�в����ı��:" << endl;

        int choice1;
        cin >> choice1;
        if (choice1 == 1)
        {
            showall();
            //��������� �����ص��ϼ�Ŀ¼
            system("pause");
        }
        else if (choice1 == 2)
        {
            showByIndex();
        }
        else if (choice1 == 3)
        {
            addgoods();
        }
        else if (choice1 == 4)
        {
            delegood();
        }
        else if (choice1 == 5)
        {
            modify();
        }
        else if (choice1 == 0)
        {
            break;
        }
        else
        {
            cout << "�������,����������..." << endl;
            cin.sync();
            system("pause");
        }
    }
}
void GoodsManage_Administrator::showstaffs(LogUser* my)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "1.�鿴����Ա��" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "2.����Ա��" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "3.ɾ��Ա��" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "0.����" << setw(16) << right << "��" << endl;

        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << "������ִ�в����ı��:" << endl;

        int choice1;
        cin >> choice1;
        if (choice1 == 1)
        {
            showstaff(my);
            //��������� �����ص��ϼ�Ŀ¼
            system("pause");
        }
        else if (choice1 == 2)
        {
            addUser();
        }
        else if (choice1 == 3)
        {
            delestaff();
        }
        else if (choice1 == 4)
        {
            delegood();
        }
        else if (choice1 == 5)
        {
            modify();
        }
        else if (choice1 == 0)
        {
            break;
        }
        else
        {
            cout << "�������,����������..." << endl;
            system("pause");
        }
    }
}
void GoodsManage_Administrator::showMenu( LogUser* log)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        cout<<endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "1.��Ʒ����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "2.Ա������" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "3.�˵��鿴" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "4.С�˱�" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "5.������Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "0.���ص�¼����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        cout << endl;
        cout << "������ִ�в����ı��:" << endl;

        int choice;
        cin >> choice;
        if (choice == 1)
        {
            showgoods();
        }
        else if (choice == 2)
        {
            showstaffs(log);
        }
        else if (choice == 3)
        {
            showBills();
        }
        else if (choice == 4)
        {
            account();
        }
        else if (choice == 5)
        {
            sell(log);
        }
        else if (choice == 0)
        {
            return;
        }
        else
        {
            cout << "�������,����������" << endl;
            system("pause");
        }
    }
}
