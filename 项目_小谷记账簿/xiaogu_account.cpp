#include "common.h"
#include"account_item.h"

int main()
{
	//1.加载文件中数据
	//2.定义vector数组
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	while (!quit)
	{
		//显示主菜单
		showMainMenu();

		//读取键盘选择，并做校验
		char key = readMenuSelection(3);

		switch (key)
		{
		case'1':	//记账
			showAccountMenu();
			accounting(items);
			break;
		case'2':	//2.查询
			showQueryMenu();
			query(items);
			break;
		case'3':	//3.退出
			cout << "\n是否确认退出？(Y/N):";
			if (readQuitConfirm() == 'Y')
				quit = true;
			break;
		default:
			break;
		}

		cout << endl;
	}
}