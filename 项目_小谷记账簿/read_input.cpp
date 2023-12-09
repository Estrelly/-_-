#include "account_item.h"
#include "common.h"


//��ȡ��������Ĳ˵�ѡ�����У��
char readMenuSelection(int options)
{
	string str;

	while (true)
	{
		getline(cin, str);

		//����У��
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
			cout << "�������������ѡ��:";
		else
			break;
	}

	return str[0];
}

//��ȡȷ����Ϣ
char readQuitConfirm()
{
	string str;

	while (true)
	{
		getline(cin, str);

		//����У��toupperСд��дת������
		if (str.size() != 1 || toupper(str[0]) !='Y' && toupper(str[0]) !='N')
			cout << "�����������������:";
		else
			break;
	}

	return toupper(str[0]);
}


//��ȡ���̵Ľ����
int readAmount()
{
	int amount;

	string str;
	while (true)
	{
		getline(cin, str);

		//����У��toupperСд��дת������
		try
		{
			amount = stoi(str);
			break;
		}
		catch (invalid_argument e)
		{
			cout << "�����������ȷ��������:";
		}
	}
	//����Ϸ�
	return amount;
}