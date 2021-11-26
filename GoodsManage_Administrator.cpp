#include"GoodsManage_Administrator .h"
#include"Sortnum.h"
#include"Sortmoney.h"
GoodsManage_Administrator::GoodsManage_Administrator()
{
    usernum = getusernum();
    logusers = new LogUser[usernum];
    //生成员工数组
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
    //将人员的数据写入到文件中
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
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(13) << left << "●" << setw(22) << "输入条码或名称修改商品" << setw(13) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        cout << endl;

        //展示有的商品
        cout << "商品的总数量为：" << goodsnums << "\t" << "小吃类：" << snack::num << "\t" << "饮料类：" << drink::num << "\t" << "熟食类：" << deli::num << endl;
        cout << endl;
        cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
        for (int i = 0; i < goodsnums; i++)
        {
            goods[i]->show2();
        }

        //找到对应的商
        string barcode;
        cin >> barcode;

        //输入零返回
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
            cout << "未查询到对应商品信息!请重新输入!" << endl;
            continue;
        }


        while (1)
        {
            system("cls");
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入1修改进货价" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;;
            cout << setw(16) << left << "●" << setw(16) << "输入2修改销售价" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入3修改库存" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            for (int i = 0; i < 24; i++) cout << "●";
            cout << endl;

            cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
            goods[i]->show2();

            int choice;
             cin >> choice;
             if (choice == 1)
             {

                 double temp;
                 cout << "输入金额" << endl;
                 cin >> temp;
                 goods[i]->purchase_price = temp;
                 cout << "修改完成" << endl;
                 system("pause");
                 system("cls");
                 continue;
             }

             else if (choice == 2)
             {
                 double temp;
                 cout << "输入金额" << endl;
                 cin >> temp;
                 goods[i]->sale_price = temp;
                 cout << "修改完成" << endl;
                 system("pause");
                 system("cls");
                 continue;
             }
             else if (choice == 3)
             {
                 int  temp;
                 cout << "输入添加的数量" << endl;
                 cin >> temp;
                 goods[i]->repertory += temp;
                 cout << "修改完成" << endl;
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
                 cout << "输入有误，请重新输入" << endl;
                 system("pause");
             }
        }
    }
}       
void GoodsManage_Administrator::addgoods()
{

    system("cls");
    for (int i = 0; i < 24; i++) cout << "●";
    puts("");
    cout << setw(46) << left << "●" << "●" << endl;
    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
    cout << setw(46) << left << "●" << "●" << endl;
    for (int i = 0; i < 24; i++) cout << "●";
    cout << endl;
    cout << "增加商品的数量：" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {

        //计算添加新空间大小
        int newSize = goodsnums + addNum;
        // 开辟新空间
        Goods** newSpace = new Goods * [newSize];
        //将原数据拷贝新的数组
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
            cout << "请输入第" << i + 1 << "个商品条码： " << endl;
            cin >> barcode;
            for (int j = 0; j < goodsnums+i; j++)
            {
                if (barcode == goods[j]->barcode)
                {
                    cout << "该条码存在" << endl;
                    cout << "其信息如下：" << endl;
                    cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" <<"售价" << endl;
                    goods[j]->show2();
                    cout << "请重新输入" << endl;
                    i--;
                    sign = 0;
                    break;
                   
                }
            }
            if (!sign)continue;
            cout << "请输入第" << i + 1 << "个商品名称： " << endl;
            cin >> name;

            for (int j = 0; j < goodsnums + i; j++)
            {
                if (name == goods[j]->name)
                {
                    cout << "该名称存在" << endl;
                    cout << "其信息如下：" << endl;
                    cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
                    goods[j]->show2();
                    cout << "请重新输入" << endl;
                    i--;
                    sign = 0;
                    break;
                  
                }
            }
            if (!sign)continue;
            cout << "请输入第" << i + 1 << "个商品类型（零食类、饮料类、熟食类）： " << endl;
            cin >> type;
            while (type != "零食类" && type != "饮料类" && type != "熟食类")
            {
                cout <<"输入错误" << "请重新输入第" << i + 1 << "个商品类型（零食类、饮料类、熟食类）： " << endl;
                cin >> type;
            }
            cout << "请输入第" << i + 1 << "个商品库存： " << endl;
            cin >> repertory;
            cout << "请输入第" << i + 1 << "个商品进货价： " << endl;
            cin >> purchase_price;
            cout << "请输入第" << i + 1 << "个商品售价： " << endl;
            cin >> sale_price;

            Goods* temp = NULL;
            if (type == "零食类")
            {
                temp = new snack(barcode, name, type, repertory, purchase_price, sale_price);
                snack::num++;
            }
            else if (type == "饮料类")
            {
                temp = new drink(barcode, name, type, repertory, purchase_price, sale_price);
                drink::num++;
            }
            else if (type == "熟食类")
            {
                temp = new deli(barcode, name, type, repertory, purchase_price, sale_price);
                deli::num++;
            }

            //将创建的商品保存进数组内
            newSpace[goodsnums + i] = temp;
        }
        delete[]goods;
        goods = newSpace; //更改新空间的指向
        //更新新的职工人数
        goodsnums = newSize;
        //保存数据到文件中
        save();
        // 提示添加成功
        cout << "成功添加" << addNum << "个商品" << endl;
        //按任意键后 清屏回到上级目录
        system("pause");
        system("cls");
    }
    else
    {
        cout << "输入有误" << endl;
    }
}
void GoodsManage_Administrator::delegood()
{
    while (1)
    {
        system("cls");
        //界面
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(13) << left << "●" << setw(22) << "输入条码和名称删除商品" << setw(13) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;

        for (int i = 0; i < 24; i++) cout << "●";
        cout << endl;
        //展示有的商品
        cout << "商品的总数量为：" << goodsnums << "\t" << "小吃类：" << snack::num << "\t" << "饮料类：" << drink::num << "\t" << "熟食类：" << deli::num << endl;
        cout << endl;
        cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
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
            cout << "没有该商品，请重新输入" << endl;
            system("pause");
            continue;
        }
        for (i; i < goodsnums - 1; i++)
        {
            goods[i] = goods[i + 1];
        }
        goodsnums--;
        cout << " 删除成功" << endl;
        system("pause");
    }
}
void GoodsManage_Administrator::showByIndex()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(13) << left << "●" << setw(13) << "输入条码或名称查看商品" << setw(13) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入1清屏" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        cout << endl;
        string barcode;

        cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
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
                cout << "未查询到对应商品信息!请输入正确的条码!" << endl;
            }
        }
    }
}
void GoodsManage_Administrator::showall()
{
    {
        system("cls");
        cout << "商品的总数量为：" << goodsnums << "\t" << "小吃类：" << snack::num << "\t" << "饮料类：" << drink::num << "\t" << "熟食类：" << deli::num << endl;
        cout << endl;
        cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "进价\t" << "售价" << endl;
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
    //员工人数
    int n = getusernum();
    //初始化销售额为零
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
        cout << "姓名\t\t" << "销售额\t\t" << endl;
        for (int i = 0; i < n; i++)
        {

            cout << logusers[i].name <<"\t\t" << logusers[i].money << endl;
        }
    }
}
void GoodsManage_Administrator:: account()
{
    system("cls");
    //保证是更新的
    //由于有修改价格的选项，一个商品可能有两种价格，这里视为两种商品，综合考虑，给种类的两倍大小
    delinum = 2 * deli::num;
    snacknum = 2 * snack::num;
    drinknum = 2 * drink::num;
    snacks = new snack[snacknum];
    drinks = new drink[drinknum];
    delis = new deli[delinum];
    double purchase_price, sale_price, money;
    string time1, barcode, name, salename, time2, type;
    int  repertory;
    //将账单中的每种商品，存到各自数组中
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
                if (type == "零食类")
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
                else if (type == "饮料类")
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
                else if (type == "熟食类")
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
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "1.按盈利额排序" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "2.按销售量排序" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "3.按销售员营业额" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            for (int i = 0; i < 24; i++) cout << "●";
            cout << endl;
            string choice;
            cin >> choice;
            if (choice == "1")
            {
                //给3种商品种类类按利润排序
                sortmoney(snacks, i);
                sortmoney(drinks, j);
                sortmoney(delis, k);
                cout << "小吃类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
                for (int ii = 0; ii < i; ii++)
                {
                    cout << snacks[ii].barcode << "\t" << snacks[ii].name << "\t\t" << snacks[ii].type << "\t\t" <<
                        snacks[ii].repertory << "\t" << snacks[ii].purchase_price << "\t" << snacks[ii].sale_price << "\t" << snacks[ii].money << endl;
                }
                cout << endl;

                cout << "饮料类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
                for (int jj = 0; jj < j; jj++)
                {
                    cout << drinks[jj].barcode << "\t" << drinks[jj].name << "\t\t" << drinks[jj].type << "\t\t" <<
                        drinks[jj].repertory << "\t" << drinks[jj].purchase_price << "\t" << drinks[jj].sale_price << "\t" << drinks[jj].money << endl;
                }
                cout << endl;

                cout << "熟食类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
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
                cout << "小吃类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
                for (int ii = 0; ii < i; ii++)
                {
                    cout << snacks[ii].barcode << "\t" << snacks[ii].name << "\t\t" << snacks[ii].type << "\t\t" <<
                        snacks[ii].repertory << "\t" << snacks[ii].purchase_price << "\t" << snacks[ii].sale_price << "\t" << snacks[ii].money << endl;
                }
                cout << endl;

                cout << "饮料类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
                for (int jj = 0; jj < j; jj++)
                {
                    cout << drinks[jj].barcode << "\t" << drinks[jj].name << "\t\t" << drinks[jj].type << "\t\t" <<
                        drinks[jj].repertory << "\t" << drinks[jj].purchase_price << "\t" << drinks[jj].sale_price << "\t" << drinks[jj].money << endl;
                }
                cout << endl;

                cout << "熟食类商品销售情况如下：" << endl;
                cout << "条码\t" << "商品名称\t" << "商品类型\t" << "数量\t" << "进价\t" << "售价\t" << "盈利" << endl;
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
                cout << "输入错误，请重新输入" << endl;
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
            for (int i = 0; i < 25; i++) cout << "●";
            puts("");
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "1.查看某次账单" << setw(18) << right << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "2.查看某时段账单" << setw(18) << right << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "3.查看某种商品账单" << setw(16) << right << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "4.查看营业员销售记录" << setw(14) << right << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(18) << right << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            cout << setw(48) << left << "●" << "●" << endl;
            for (int i = 0; i < 25; i++) cout << "●";
            puts("");
            int choice;
            cin >> choice;
            //查看某次账单
            if (choice == 1)
            {
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "●";
                    puts("");
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(8) << left << "●" << setw(16) << "（格式例为：2020-01-01 00-00-00）" << setw(7) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    for (int i = 0; i < 24; i++) cout << "●";
                    cout << endl;
                    string temp;
                    cout << "请输入要查看的账单文件名：";
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
                    cout<< "条码\t" << "商品名称\t" << "类型\t" << "数量\t" << "售价\t" << "总价" << endl;
                    while (in >> barcode >> name >> type >> repertory >> sale_price >> money)
                    {
                        cout <<barcode << "\t" << name << "\t\t" << type << "\t" << repertory << "\t" << sale_price << "\t" << money << endl;
                    }
                    cout << barcode << "\t\t" << name << endl;
                    system("pause");
                    in.close();
                }

            }

            //2.查看某时段账单
            else if (choice == 2)
            {
                ifstream in("Bills.txt");
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "●";
                    puts("");
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(3) << left << "●" << setw(16) << "请输入要查询的日期（格式例为：2020-01-01）" << setw(3) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    for (int i = 0; i < 24; i++) cout << "●";
                    cout << endl;
                    string temp,temp1;
                    cout << "输入起始日期：";
                    cin >> temp;
                    if (temp == "0")
                    {
                        break;
                    }
                    cout << "输入截止日期：";
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
                    cout << temp <<"至"<<temp1 << "的销售额为：" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            //查看某种商品类别的账单
            else if (choice == 3)
            {
                ifstream in("Bills.txt");
            
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "●";
                    puts("");
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "请输入商品种类或条码" << setw(12) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    for (int i = 0; i < 24; i++) cout << "●";
                    cout << endl;
                    int work = 1;
                    string temp;
                    cin >> temp;
                    string tian;
                    double sum = 0;
                    //推出按钮
                    if (temp == "0")
                    {
                        break;
                    }
                    int i = 0;
                    for (i; i < goodsnums; i++)
                    {
                        if (temp == goods[i]->name||temp==goods[i]->barcode)
                        {
                            cout << "该商品存在，其销售记录为：" << endl;
                            work = 0;
                            break;
                        }
                    }
                    //如果没这商品
                    if (work)
                    {
                        cout << "该商品不存在，请重新输入" << endl;
                        system("pause");
                        continue;
                    }
                    //如果有商品存在
                    cout << "日期\t\t" << "时间\t\t" << "售货员\t" << "条码\t" << "商品名\t" << "类型\t" << "数量\t" << "进货价\t" << "售卖价\t" << "利润\t" << endl;
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
                    cout << "从" << tian << "至今" << goods[i]->name << "的销售额为：" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            //查看营业员销售记录
            else if (choice == 4)
            {
              ifstream in("Bills.txt");
                while (1)
                {
                    system("cls");
                    for (int i = 0; i < 24; i++) cout << "●";
                    puts("");
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "请输入要查询的营业员的名字" << setw(6) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
                    cout << setw(46) << left << "●" << "●" << endl;
                    for (int i = 0; i < 24; i++) cout << "●";
                    cout << endl;
                    int work = 1;
                    string temp;
                    cin >> temp;
                    string tian;
                    double sum = 0;

                    //推出按钮
                    if (temp == "0")
                    {
                        break;
                    }
                    int i = 0;
                    for (i; i < usernum; i++)
                    {
                        if (temp == logusers[i].name )
                        {
                            cout << "该人员存在，其销售记录为：" << endl;
                            work = 0;
                            break;
                        }
                    }
                    //如果没这个人
                    if (work)
                    {
                        cout << "该人员不存在，请重新输入" << endl;
                        system("pause");
                        continue;
                    }  
                    //如果有此人存在
                    cout << "日期\t\t" << "时间\t\t" << "售货员\t" << "条码\t" << "商品名\t" << "类型\t" << "数量\t" << "进货价\t" << "售卖价\t" << "利润\t" << endl;
                    int n = 0;
                    in.clear();
                    in.seekg(0, ios::beg);
                    while (in >> time1 >> time2 >> salename >> barcode >> name >> type >> repertory >> purchase_price >> sale_price >> money)
                    {
                        //收取最开始的那天的时间
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
                    cout << "从" << tian << "至今" << temp << "的销售额为：" << sum << endl;
                    system("pause");
                }
                in.close();
            }

            else if (choice == 0)return;
            else

            {
                cout << "输入错误，请重新输入" << endl;
                system("pause");
            }
            

    }
}

void GoodsManage_Administrator::addUser()
{
    system("cls");
    for (int i = 0; i < 24; i++) cout << "●";
    puts("");
    cout << setw(46) << left << "●" << "●" << endl;
    cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
    cout << setw(46) << left << "●" << "●" << endl;
    for (int i = 0; i < 24; i++) cout << "●";
    cout << endl;
    cout << "增加人员的数量：" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {
        //计算添加新空间大小
        int newSize = usernum + addNum;
        // 开辟新空间
        LogUser* newSpace = new LogUser [newSize];
        //将原数据拷贝新的数组
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
            cout << "请输入第" << i + 1 << "输入员工信息:" << endl;
            cout << "姓名:";
            cin >> name;
            cout << "ID:";       
            cin >> userId;
            //查看是ID否重复
            for (int j = 0; j < goodsnums + i; j++)
            {
                if (userId == logusers[j].userId)
                {
                    cout << "该成员存在" << endl;
                    cout << "其信息如下：" << endl;
                    cout << "姓名\t\t" << "ID\t\t" << "密码\t\t" << "权限\t\t" << endl;
                    if (logusers[i].userLevel == "售货员")
                        cout << logusers[i].name << "\t\t" << logusers[i].userId << "\t\t" << logusers[i].userPassword << "\t\t" << logusers[i].userLevel << endl;
                    else cout << "此ID成员权限为管理员，不可访问"<<endl;
                    cout << "请重新输入" << endl;
                    i--;
                    sign = 0;
                    break;

                }
            }
            if (!sign)continue;
            cout << "密码:";
            cin >> userPassword;
            cout << "权限（管理员或售货员）:";
            cin >> userLevel;
            while (userLevel != "管理员" || userLevel != "售货员")
            {
                cout << "请输入正确权限" << endl;
                cin >> userLevel;
            }
               
            LogUser* temp = NULL;
            temp = new LogUser(name, userId, userPassword, userLevel);
            newSpace[usernum + i] = *temp;
        }
        delete[]logusers;

        logusers = newSpace; //更改新空间的指向
        //更新新的职工人数
        usernum = newSize;
        savestaff();
   
        // 提示添加成功
        cout << "成功添加" << addNum << "个员工" << endl;
        //按任意键后 清屏回到上级目录
        system("pause");
        system("cls");
    }
    else
    {
        cout << "输入有误" << endl;
    }
}
void GoodsManage_Administrator::showstaff(LogUser* my)
{
    system("cls");
    cout << "姓名\t\t" << "ID\t\t" << "密码\t\t" << "权限\t\t" << endl;
    for (int i = 0; i < usernum; i++)
    {
        if (logusers[i].userLevel == "售货员")
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
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "只能删除售货员" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(13) << left << "●" << setw(22) << "输入要删除员工的ID" << setw(13) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0返回" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        cout << endl;
        cout << "姓名\t\t" << "ID\t\t" << "密码\t\t" << "权限\t\t" << endl;
        for (int i = 0; i < usernum; i++)
        {
            if (logusers[i].userLevel == "售货员")
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
            cout << "此编号没有对应的员工，请重新输入" << endl;
            system("pause");
            continue;
        }
        for (i; i < usernum - 1; i++)
        {
            logusers[i] = logusers[i + 1];
        }
        usernum--;
        cout << " 删除成功" << endl;
        system("pause");
    }
}




void GoodsManage_Administrator::showgoods()
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "1.查看所有商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "2.查询商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "3.增加商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "4.删除商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "5.修改商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "0.返回" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << "请输入执行操作的编号:" << endl;

        int choice1;
        cin >> choice1;
        if (choice1 == 1)
        {
            showall();
            //按任意键后 清屏回到上级目录
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
            cout << "输入错误,请重新输入..." << endl;
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
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "1.查看所有员工" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "2.增加员工" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "3.删除员工" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "0.返回" << setw(16) << right << "●" << endl;

        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << "请输入执行操作的编号:" << endl;

        int choice1;
        cin >> choice1;
        if (choice1 == 1)
        {
            showstaff(my);
            //按任意键后 清屏回到上级目录
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
            cout << "输入错误,请重新输入..." << endl;
            system("pause");
        }
    }
}
void GoodsManage_Administrator::showMenu( LogUser* log)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "●";
        cout<<endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "1.商品管理" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "2.员工管理" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "3.账单查看" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "4.小账本" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "5.售卖商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "0.返回登录界面" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        cout << endl;
        cout << "请输入执行操作的编号:" << endl;

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
            cout << "输入错误,请重新输入" << endl;
            system("pause");
        }
    }
}
