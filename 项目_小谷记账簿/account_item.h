#pragma once
#include "account_item.h"
#include "common.h"
//����ṹ������
struct AccountItem
{
	string itemType;
	int amount;
	string datail;
};

//������Ŀ����
void loadDataFromFile(vector<AccountItem>& items);


//����
void accounting(vector<AccountItem>& items);
void insertIntoFile(const AccountItem& item);
void expand(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
//��ѯ
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string itemType);
void printItem(const AccountItem& item);