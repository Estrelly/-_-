#include "account_item.h"
#include "common.h"


//读取文件中的账目数据
void loadDataFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);	//读取文件

	//逐行读取每一条账目，并包装成AccountItem
	AccountItem item;

	while (input >> item.itemType >> item.amount >>item.datail)
	{
		items.push_back(item);

	}

	input.close();
}

//记账
void accounting(vector<AccountItem>& items)
{

	//读取键盘选择，并做校验
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1':	//收入
		income(items);
		break;
	case'2':	//2.支出
		expand(items);
		break;
	case'3':	//3.退出
		break;
	default:
		break;
	}

	cout << endl;
}

//记录收入
void income(vector<AccountItem>& items)
{
	//新构建一个accountitem对象
	AccountItem item;
	//收入
	item.itemType = INCOME;

	//与用户交互
	cout << "\n本次收入金额:";
	item.amount = readAmount();

	cout << "备注:";
	getline(cin, item.datail);

	//添加到vector
	items.push_back(item);

	//写入文件中去
	insertIntoFile(item);

	//显示信息
	cout << "\n------记账成果---------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}

//将钱加入到文件中
void insertIntoFile(const AccountItem& item)
{
	//创建一个ofstream对象,并以追加的方式进行写入
	ofstream output(FILENAME,ios::out | ios::app);

	output << item.itemType << "\t" << item.amount << "\t" << item.datail << endl;

	output.close();
}

//记录支出
void expand(vector<AccountItem>& items)
{
	//新构建一个accountitem对象
	AccountItem item;
	//支出
	item.itemType = EXPAND;

	//与用户交互
	cout << "\n本次支出金额:";
	item.amount = - readAmount();

	cout << "备注:";
	getline(cin, item.datail);

	//添加到vector中
	items.push_back(item);

	//写入文件中去
	insertIntoFile(item);

	//显示信息
	cout << "\n------记账成果---------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}

//---------------2.查询-------------
void query(const vector<AccountItem>& items)
{
	//读取键盘选择，并做校验
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1':	//查询所有账目
		queryItems(items);
		break;
	case'2':	//2.查询所有收入
		queryItems(items,INCOME);
		break;
	case'3':	//3.查询所有支出
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}

}

//查询账目功能函数
void queryItems(const vector<AccountItem>& items)
{
	cout << "------查询结果---------" << endl;
	cout << "\n类型\t\t金额\t\t备注\t\t\n" << endl;

	//遍历所有账目
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}

	//输出信息
	cout << "---------------------------------" << endl;
	cout << "总收支：" << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}


//函数重载
void queryItems(const vector<AccountItem>& items,const string itemType)
{
	cout << "------查询结果---------" << endl;
	cout << "\n类型\t\t金额\t\t备注\t\t\n" << endl;

	//遍历所有账目,总收入，总支出
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType == itemType)
			continue;
			printItem(item);
			total += item.amount;
		
	}

	//输出信息
	cout << "---------------------------------" << endl;
	cout << ((itemType == INCOME)?"总收支：":"总支出：") << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}

//打印一条账目信息
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.datail << endl;

}