// HashSearch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;
#define NUMBER 5 //������
#define HASH_LEN 7 //��ϣ����

class HashList {
public:
	HashList();
	~HashList();
	int getHash(int key);//�õ���ϣ��ַ
	int hashAddress(int key);//�����ϣ��ַ
	int isCollision(int address);//�ж��Ƿ��ͻ
	void inputData();//��������
	void traveral();//������ϣ��
	int hashSearch(int key);//��������
private:
	int hashArray[HASH_LEN];
	//int hashArray[HASH_LEN];
};

HashList::HashList()
{
	
	for (int i = 0; i<HASH_LEN;i++)
	{
		hashArray[i] = -1;//ͨ��-1�жϵ�ַ�Ƿ��ͻ
	}
}

HashList::~HashList()
{

}

//�����ϣ��ַ
int HashList::getHash(int key)
{
	int newaddress, offset = 3, count = 0;//�µĵ�ַ��ƫ����Ϊ3
	newaddress = key % HASH_LEN;
	while (hashArray[newaddress] != key) {
		if (count > 5)
			return -1;
		count++;
		newaddress = (newaddress + offset) % HASH_LEN;//��ƫ�����������ַ
	}
	return newaddress + 1;
}

//�����ϣ��ַ
int HashList::hashAddress(int key)
{
	int newaddress, offset = 3;//�µĵ�ַ��ƫ����Ϊ3
	newaddress = key % HASH_LEN;
	while (isCollision(newaddress)) {
		newaddress = (newaddress + offset) % HASH_LEN;//��ƫ�����������ַ
	}
	hashArray[newaddress] = key;//û�г�ͻ���������������ַ��
	return newaddress;
}
//��ͻ�����ѯ��ַ��ŵ����Ƿ�Ϊ-1
int HashList::isCollision(int address)
{
	return hashArray[address] == -1 ? false : true;//���Ϊ-1����falseû�г�ͻ���򷵻�true���ֳ�ͻ
}

void HashList::inputData()
{
	int number;//���������
	cout << "�������������" << endl;
	for (int i = 0;i<NUMBER;i++) {
		cin >> number;
		hashAddress(number);
	}
}

void HashList::traveral()
{
	cout << "��ϣ�������Ϊ:" << endl;
	for (int i = 0;i<HASH_LEN;i++)
	{
		if (hashArray[i] == -1)
			cout << "[" << i + 1 << "]" << "-->" << "��" << endl;
		else
			cout << "[" << i + 1 << "]" << "-->" << hashArray[i] << endl;
	}
}


//���Һ���
int HashList::hashSearch(int key)
{
	if (getHash(key) == -1)
		cout << key << "û���ҵ���" << endl;
	else
		cout << key << "�Ĺ�ϣ��ַ��:" << getHash(key) << endl;
	return 0;
}

int main()
{
	system("color f0");
	system("title ʵ����-��ϣ����");
	int key;
	HashList my;
	my.inputData();
	
	for (; ; )
	{
		system("cls");
		my.traveral();
		cout << endl;
		cout << "����һ�������ǽ�������(-1��ʾ�˳�)" << endl;
		cin >> key;
		if (key == -1)
			break;
		my.hashSearch(key);
		cout << endl;
		system("pause");
	}
	system("pause");
	return 0;
}