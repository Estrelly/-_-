#include "account_item.h"
#include "common.h"


//��ȡ�ļ��е���Ŀ����
void loadDataFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);	//��ȡ�ļ�

	//���ж�ȡÿһ����Ŀ������װ��AccountItem
	AccountItem item;

	while (input >> item.itemType >> item.amount >>item.datail)
	{
		items.push_back(item);

	}

	input.close();
}

//����
void accounting(vector<AccountItem>& items)
{

	//��ȡ����ѡ�񣬲���У��
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1':	//����
		income(items);
		break;
	case'2':	//2.֧��
		expand(items);
		break;
	case'3':	//3.�˳�
		break;
	default:
		break;
	}

	cout << endl;
}

//��¼����
void income(vector<AccountItem>& items)
{
	//�¹���һ��accountitem����
	AccountItem item;
	//����
	item.itemType = INCOME;

	//���û�����
	cout << "\n����������:";
	item.amount = readAmount();

	cout << "��ע:";
	getline(cin, item.datail);

	//��ӵ�vector
	items.push_back(item);

	//д���ļ���ȥ
	insertIntoFile(item);

	//��ʾ��Ϣ
	cout << "\n------���˳ɹ�---------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}

//��Ǯ���뵽�ļ���
void insertIntoFile(const AccountItem& item)
{
	//����һ��ofstream����,����׷�ӵķ�ʽ����д��
	ofstream output(FILENAME,ios::out | ios::app);

	output << item.itemType << "\t" << item.amount << "\t" << item.datail << endl;

	output.close();
}

//��¼֧��
void expand(vector<AccountItem>& items)
{
	//�¹���һ��accountitem����
	AccountItem item;
	//֧��
	item.itemType = EXPAND;

	//���û�����
	cout << "\n����֧�����:";
	item.amount = - readAmount();

	cout << "��ע:";
	getline(cin, item.datail);

	//��ӵ�vector��
	items.push_back(item);

	//д���ļ���ȥ
	insertIntoFile(item);

	//��ʾ��Ϣ
	cout << "\n------���˳ɹ�---------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}

//---------------2.��ѯ-------------
void query(const vector<AccountItem>& items)
{
	//��ȡ����ѡ�񣬲���У��
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1':	//��ѯ������Ŀ
		queryItems(items);
		break;
	case'2':	//2.��ѯ��������
		queryItems(items,INCOME);
		break;
	case'3':	//3.��ѯ����֧��
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}

}

//��ѯ��Ŀ���ܺ���
void queryItems(const vector<AccountItem>& items)
{
	cout << "------��ѯ���---------" << endl;
	cout << "\n����\t\t���\t\t��ע\t\t\n" << endl;

	//����������Ŀ
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}

	//�����Ϣ
	cout << "---------------------------------" << endl;
	cout << "����֧��" << total << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}


//��������
void queryItems(const vector<AccountItem>& items,const string itemType)
{
	cout << "------��ѯ���---------" << endl;
	cout << "\n����\t\t���\t\t��ע\t\t\n" << endl;

	//����������Ŀ,�����룬��֧��
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType == itemType)
			continue;
			printItem(item);
			total += item.amount;
		
	}

	//�����Ϣ
	cout << "---------------------------------" << endl;
	cout << ((itemType == INCOME)?"����֧��":"��֧����") << total << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}

//��ӡһ����Ŀ��Ϣ
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.datail << endl;

}