#include "common.h"

void showMainMenu() 
{
	system("cls");

	cout << "------------------------------" << endl;
	cout << "------欢迎适用记账簿----------" << endl;
	cout << "                " << endl;
	cout << "----------1.记账--------------" << endl;
	cout << "----------2.查询--------------" << endl;
	cout << "----------3.退出-- -----------" << endl;
	cout << "                " << endl;
	cout << "------------------------------" << endl;

	cout << "\n请选择（1-3):";
}

void showAccountMenu()
{
	cout << "----------------" << endl;
	cout << "-选择记账种类-" << endl;
	cout << "                " << endl;
	cout << "-----1.收入------" << endl;
	cout << "-----2.支出------" << endl;
	cout << "---3.返回主菜单---" << endl;
	cout << "                " << endl;
	cout << "----------------" << endl;

	cout << "\n请选择（1-3):";
}
void showQueryMenu()
{
	cout << "----------------" << endl;
	cout << "-选择查询条件-" << endl;
	cout << "                " << endl;
	cout << "-----1.统计所有账目------" << endl;
	cout << "-----2.统计支出------" << endl;
	cout << "-----3.统计收入---" << endl;
	cout << "-----4.返回主菜单---" << endl;
	cout << "                " << endl;
	cout << "----------------" << endl;

	cout << "\n请选择（1-4):";

}