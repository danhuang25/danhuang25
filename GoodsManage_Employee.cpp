#define _CRT_SECURE_NO_WARNINGS   //为了使用fopen
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
    //将商品的数据写入到文件中
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

        cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "售价\t" << endl;
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
                cout << "未查询到对应商品信息!请输入正确的条码!" << endl;
            }
        }
    }
}
void GoodsManage_Employee::showall()
{
    system("cls");
    cout << "商品的总数量为：" << goodsnums << "\t" << "小吃类：" << snack::num << "\t" << "饮料类：" << drink::num << "\t" << "熟食类：" << deli::num << endl;
    cout << endl;
    cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "售价\t" << endl;
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
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入条码或名称购买" << setw(14) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0购买完毕" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(26) << "购买数量时输入0可取消购买" << setw(6) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        string barcode; 
        puts("");
        cout << endl;
        ////展示商品
        //cout << "商品的总数量为：" << goodsnums << "\t" << "零食类：" << snack::num << "\t" << "饮料类：" << drink::num << "\t" << "熟食类：" << deli::num << endl;
        //cout << endl;
        //cout << "条码\t" << "商品名称\t" << "商品类型\t" << "库存\t" << "售价\t" << endl;
        //for (int i = 0; i < goodsnums; i++)
        //{
        //    goods[i]->show1();
        //}
        //最多五十件
        shopping_Cart = new soldgoods[50];
        int n = goodsnums;
        //总金额
        double sum = 0;
        //购买的数量
        int num = 0;
        //购买的时间
        string  time1;

        //编码的下标标记
        int sign = 1000;
        //买一次放一次shopping_Cart
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
                    cout << "条码\t" << "商品名称\t" << "库存\t" << "单价\t" << endl;
                    cout << goods[i]->barcode << "\t" << goods[i]->name << "\t\t" << goods[i]->repertory << "\t" << goods[i]->sale_price << endl;
                    sign = i;
                    break;
                }
            }
            if (i == n)
            {
                cout << "输入有误，没有此商品,请重新输入" << endl;
                continue;
            }
            if (goods[i]->repertory == 0)
            {
                cout << "该商品已售完"<<endl;
                continue;
            }
            cout << "输入购买数量" << endl;
            cin >> amount;
            if ((goods[i]->repertory < amount))
            {
                do
                {
                    cout << "输入正确的购买数量" << endl;
                    cin >> amount;
                } while ((goods[i]->repertory < amount) );
            }
            if (!amount)
            {
                cout << "取消购买" << endl;
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
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入1打印账单" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            cout << setw(16) << left << "●" << setw(16) << "输入其他则不打印" << setw(16) << right << "●" << endl;
            cout << setw(46) << left << "●" << "●" << endl;
            for (int i = 0; i < 24; i++) cout << "●";
            puts("");
            string a;
            cin >> a;
            //如果要打印
            if (a == "1")
            {
                //创建文件
                string time3 = GetSystemTime();
                string time2 = GetSystemTime1() + ".txt";
                ofstream os(time2.c_str(), ios::out);
                if (!os)
                {
                    cout << time << "文件创建出错" << endl;
                    abort();
                }
                else//cout << "日期\t\t" << "时间\t\t" << "售货员\t" << "条码\t" << "商品名\t" << "类型\t" << "数量\t" << "进货价\t" << "售卖价\t" << "利润\t" << endl;
                {
                    os << setw(15) << " " << "欢迎光临danhuang250便利店" << endl << endl;;
                    os << "条码\t" << "商品名称\t" << "类型\t" << "数量\t" << "售价\t" << "总价" << endl;
                    for (int i = 0; i < num; i++)
                    {
                        os <<shopping_Cart[i].barcode << "\t" << shopping_Cart[i].name << "\t" << shopping_Cart[i].type << "\t" << shopping_Cart [i].repertory<<"\t" 
                            << shopping_Cart[i].sale_price << "\t" << shopping_Cart[i].sale_price* shopping_Cart[i].repertory << endl;
                    }
                    
                    os << endl;

                    os << "总金额:" << sum << "\t\t" << "售货员:" << log->name << "\t" << endl << "时间：" << time3 << endl;

                    os.close();
                }
            }

        }

        system("cls");
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入0返回上级" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "输入其他继续销售" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << "顾客购买的商品账单如下：" << endl << endl;
        cout << "条码\t" << "商品名称\t" << "数量\t" << "售价\t" << "总价" << endl;
        for (int j = 0; j < num; j++)
        {
            cout << shopping_Cart[j].barcode << "\t" << shopping_Cart[j].name << "\t\t" << shopping_Cart[j].repertory << "\t" << shopping_Cart[j].sale_price << "\t" << shopping_Cart[j].repertory * shopping_Cart[j].sale_price << endl;
        }
        cout << endl;
        cout << "总金额：" <<sum<< endl;
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

//商品信息展示界面
void GoodsManage_Employee::showgoods()
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
        else if (choice1 == 0)
        {
            break;
        }
        else
        {
            cout << "输入错误,请重新输入..." << endl;
        }
    }

}

void GoodsManage_Employee::showMenu( LogUser *log)
{
    while (1)
    {
        system("cls");
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "1.查看商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "2.售卖商品" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        cout << setw(16) << left << "●" << setw(16) << "0.返回登录界面" << setw(16) << right << "●" << endl;
        cout << setw(46) << left << "●" << "●" << endl;
        for (int i = 0; i < 24; i++) cout << "●";
        puts("");
        cout << "请输入执行操作的编号:" << endl;

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
            cout << "输入错误,请重新输入..." << endl;
            system("pause");

        }
    }

}



