#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include<vector>

#define INCOME	 "����"
#define EXPAND	"֧��"
#define FILENAME	"D:\\data\\AccountBook.txt"

using namespace std;


//ͨ�ù����Ժ�������
//���Ʋ˵�����
void showMainMenu();
void showAccountMenu();
void showQueryMenu();
 

//��ȡ���̺���
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();