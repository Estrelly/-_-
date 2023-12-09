#include "common.h"
#include"account_item.h"

int main()
{
	//1.�����ļ�������
	//2.����vector����
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	while (!quit)
	{
		//��ʾ���˵�
		showMainMenu();

		//��ȡ����ѡ�񣬲���У��
		char key = readMenuSelection(3);

		switch (key)
		{
		case'1':	//����
			showAccountMenu();
			accounting(items);
			break;
		case'2':	//2.��ѯ
			showQueryMenu();
			query(items);
			break;
		case'3':	//3.�˳�
			cout << "\n�Ƿ�ȷ���˳���(Y/N):";
			if (readQuitConfirm() == 'Y')
				quit = true;
			break;
		default:
			break;
		}

		cout << endl;
	}
}