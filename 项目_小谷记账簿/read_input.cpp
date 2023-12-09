#include "account_item.h"
#include "common.h"


//读取键盘输入的菜单选项进行校验
char readMenuSelection(int options)
{
	string str;

	while (true)
	{
		getline(cin, str);

		//进行校验
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
			cout << "输入错误，请重新选择:";
		else
			break;
	}

	return str[0];
}

//读取确认信息
char readQuitConfirm()
{
	string str;

	while (true)
	{
		getline(cin, str);

		//进行校验toupper小写大写转换函数
		if (str.size() != 1 || toupper(str[0]) !='Y' && toupper(str[0]) !='N')
			cout << "输入错误，请重新输入:";
		else
			break;
	}

	return toupper(str[0]);
}


//读取键盘的金额数
int readAmount()
{
	int amount;

	string str;
	while (true)
	{
		getline(cin, str);

		//进行校验toupper小写大写转换函数
		try
		{
			amount = stoi(str);
			break;
		}
		catch (invalid_argument e)
		{
			cout << "输入错误，请正确输入数字:";
		}
	}
	//输入合法
	return amount;
}