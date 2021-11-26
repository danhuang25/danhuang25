#define _CRT_SECURE_NO_WARNINGS   //Ϊ��ʹ��fopen
#include"GoodsManage_Employee.h"



int GoodsManage_Employee::getnum()
{
    int repertory;
    string name, type, barcode;
    double purchase_price, sale_price;
    int num=0;
    fstream in("Goods.txt", ios::in);
    while (in >> barcode >> name >> type >> repertory >> purchase_price >> sale_price)
    {
        num++;
    }
    in.close();
    return num;

}
void GoodsManage_Employee::inint() 
{
    ifstream in("Goods.txt");
    if (!in)
    {
        cout << "Goods.txt error!" << endl;
        abort();
    }
    else
    {
        int repertory, i = 0;
        string name, type, barcode;
        double purchase_price, sale_price;

        while (in >> barcode >> name >> type >> repertory >> purchase_price >> sale_price)
        {

            Goods* temp=NULL;
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
            goods[i++] = temp; 
            if (in.eof())break;

        }
    }
    in.close();
}
GoodsManage_Employee::~GoodsManage_Employee()
{
    for (int i = 0; i < goodsnums; i++)
    {
        if (goods[i] != NULL)
        {
            delete goods[i];
            goods[i] = NULL;
        }
    }
    if(goods!=NULL)
    delete[] goods;
}
GoodsManage_Employee::GoodsManage_Employee()
{
    goodsnums = GoodsManage_Employee::getnum();
    goods = new Goods * [goodsnums];
    inint();
}
void GoodsManage_Employee::save()
{
    ofstream ofs;
    ofs.open("Goods.txt", ios::out);
    //����Ʒ������д�뵽�ļ���
    for (int i = 0; i < goodsnums; i++)  
    {
        ofs << goods[i]->barcode << " "
            << goods[i]->name << " "
            << goods[i]->type << " "
            << goods[i]->repertory << " "
            << goods[i]->purchase_price << " "
            << goods[i]->sale_price<< endl;

    }
    ofs.close();
}
void GoodsManage_Employee::billsave(int num)
{

    fstream fs("Bills.txt", ios::app);
    
    for (int i = 0; i < num; i++)
    {
        fs << shopping_Cart[i].time << " " << shopping_Cart[i].saleman << " " << shopping_Cart[i].barcode << " " << shopping_Cart[i].name << " " << shopping_Cart[i].type  << " " << shopping_Cart[i].repertory
            << " " << shopping_Cart[i].purchase_price << " " << shopping_Cart[i].sale_price<<" "<< (shopping_Cart[i].sale_price- shopping_Cart[i].purchase_price)* shopping_Cart[i].repertory  << endl;
    }

    fs.close();
}

void GoodsManage_Employee::showByIndex()
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

        cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "�ۼ�\t" << endl;
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

            int n = goodsnums, i;
            for (i = 0; i < n; i++)
            {
                if (goods[i]->barcode == barcode || goods[i]->name == barcode)
                {
                    goods[i]->show1();
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
void GoodsManage_Employee::showall()
{
    system("cls");
    cout << "��Ʒ��������Ϊ��" << goodsnums << "\t" << "С���ࣺ" << snack::num << "\t" << "�����ࣺ" << drink::num << "\t" << "��ʳ�ࣺ" << deli::num << endl;
    cout << endl;
    cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "�ۼ�\t" << endl;
    for (int i = 0; i < goodsnums; i++)
    {
        goods[i]->show1();
    }

}


void GoodsManage_Employee::sell(LogUser * log)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "������������ƹ���" << setw(14) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0�������" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(26) << "��������ʱ����0��ȡ������" << setw(6) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        string barcode; 
        puts("");
        cout << endl;
        ////չʾ��Ʒ
        //cout << "��Ʒ��������Ϊ��" << goodsnums << "\t" << "��ʳ�ࣺ" << snack::num << "\t" << "�����ࣺ" << drink::num << "\t" << "��ʳ�ࣺ" << deli::num << endl;
        //cout << endl;
        //cout << "����\t" << "��Ʒ����\t" << "��Ʒ����\t" << "���\t" << "�ۼ�\t" << endl;
        //for (int i = 0; i < goodsnums; i++)
        //{
        //    goods[i]->show1();
        //}
        //�����ʮ��
        shopping_Cart = new soldgoods[50];
        int n = goodsnums;
        //�ܽ��
        double sum = 0;
        //���������
        int num = 0;
        //�����ʱ��
        string  time1;

        //������±���
        int sign = 1000;
        //��һ�η�һ��shopping_Cart
        while (1)
        {
          
            int amount;
            cin >> barcode;

            if (barcode == "0")break;
            int i = 0;
            for (i; i < n; i++)
            {
                if (goods[i]->barcode == barcode||goods[i]->name==barcode)
                {
                    cout << "����\t" << "��Ʒ����\t" << "���\t" << "����\t" << endl;
                    cout << goods[i]->barcode << "\t" << goods[i]->name << "\t\t" << goods[i]->repertory << "\t" << goods[i]->sale_price << endl;
                    sign = i;
                    break;
                }
            }
            if (i == n)
            {
                cout << "��������û�д���Ʒ,����������" << endl;
                continue;
            }
            if (goods[i]->repertory == 0)
            {
                cout << "����Ʒ������"<<endl;
                continue;
            }
            cout << "���빺������" << endl;
            cin >> amount;
            if ((goods[i]->repertory < amount))
            {
                do
                {
                    cout << "������ȷ�Ĺ�������" << endl;
                    cin >> amount;
                } while ((goods[i]->repertory < amount) );
            }
            if (!amount)
            {
                cout << "ȡ������" << endl;
                i--;
                continue;
            }

            time1 = GetSystemTime();
            shopping_Cart[num++] = soldgoods(time1, log->name, goods[i]->barcode, goods[i]->name, goods[i]->type, amount, goods[i]->purchase_price, goods[i]->sale_price);
            sum += amount * (goods[i]->sale_price);
            goods[sign]->repertory -= amount;
        }
        if (num)
        {
            system("cls");
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "����1��ӡ�˵�" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            cout << setw(16) << left << "��" << setw(16) << "���������򲻴�ӡ" << setw(16) << right << "��" << endl;
            cout << setw(46) << left << "��" << "��" << endl;
            for (int i = 0; i < 24; i++) cout << "��";
            puts("");
            string a;
            cin >> a;
            //���Ҫ��ӡ
            if (a == "1")
            {
                //�����ļ�
                string time3 = GetSystemTime();
                string time2 = GetSystemTime1() + ".txt";
                ofstream os(time2.c_str(), ios::out);
                if (!os)
                {
                    cout << time << "�ļ���������" << endl;
                    abort();
                }
                else//cout << "����\t\t" << "ʱ��\t\t" << "�ۻ�Ա\t" << "����\t" << "��Ʒ��\t" << "����\t" << "����\t" << "������\t" << "������\t" << "����\t" << endl;
                {
                    os << setw(15) << " " << "��ӭ����danhuang250������" << endl << endl;;
                    os << "����\t" << "��Ʒ����\t" << "����\t" << "����\t" << "�ۼ�\t" << "�ܼ�" << endl;
                    for (int i = 0; i < num; i++)
                    {
                        os <<shopping_Cart[i].barcode << "\t" << shopping_Cart[i].name << "\t" << shopping_Cart[i].type << "\t" << shopping_Cart [i].repertory<<"\t" 
                            << shopping_Cart[i].sale_price << "\t" << shopping_Cart[i].sale_price* shopping_Cart[i].repertory << endl;
                    }
                    
                    os << endl;

                    os << "�ܽ��:" << sum << "\t\t" << "�ۻ�Ա:" << log->name << "\t" << endl << "ʱ�䣺" << time3 << endl;

                    os.close();
                }
            }

        }

        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����0�����ϼ�" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "����������������" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << "�˿͹������Ʒ�˵����£�" << endl << endl;
        cout << "����\t" << "��Ʒ����\t" << "����\t" << "�ۼ�\t" << "�ܼ�" << endl;
        for (int j = 0; j < num; j++)
        {
            cout << shopping_Cart[j].barcode << "\t" << shopping_Cart[j].name << "\t\t" << shopping_Cart[j].repertory << "\t" << shopping_Cart[j].sale_price << "\t" << shopping_Cart[j].repertory * shopping_Cart[j].sale_price << endl;
        }
        cout << endl;
        cout << "�ܽ�" <<sum<< endl;
        billsave(num);
        string work;
        cin >> work;
        if (work=="0")
        {
            save();
            break;
        }
    }
}

//��Ʒ��Ϣչʾ����
void GoodsManage_Employee::showgoods()
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
        else if (choice1 == 0)
        {
            break;
        }
        else
        {
            cout << "�������,����������..." << endl;
        }
    }

}

void GoodsManage_Employee::showMenu( LogUser *log)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "1.�鿴��Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "2.������Ʒ" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        cout << setw(16) << left << "��" << setw(16) << "0.���ص�¼����" << setw(16) << right << "��" << endl;
        cout << setw(46) << left << "��" << "��" << endl;
        for (int i = 0; i < 24; i++) cout << "��";
        puts("");
        cout << "������ִ�в����ı��:" << endl;

        int choice;

        cin >> choice;
        if (choice == 1)
        {
            showgoods();
        }
        else if (choice == 2)
        {
            sell(log);
        }
        else if (choice == 0)
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



