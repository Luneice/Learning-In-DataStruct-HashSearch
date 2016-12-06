// HashSearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;
#define NUMBER 5 //个数数
#define HASH_LEN 7 //哈希表长度

class HashList {
public:
	HashList();
	~HashList();
	int getHash(int key);//得到哈希地址
	int hashAddress(int key);//计算哈希地址
	int isCollision(int address);//判断是否冲突
	void inputData();//输入数据
	void traveral();//遍历哈希表
	int hashSearch(int key);//查找数据
private:
	int hashArray[HASH_LEN];
	//int hashArray[HASH_LEN];
};

HashList::HashList()
{
	
	for (int i = 0; i<HASH_LEN;i++)
	{
		hashArray[i] = -1;//通过-1判断地址是否冲突
	}
}

HashList::~HashList()
{

}

//计算哈希地址
int HashList::getHash(int key)
{
	int newaddress, offset = 3, count = 0;//新的地址，偏移量为3
	newaddress = key % HASH_LEN;
	while (hashArray[newaddress] != key) {
		if (count > 5)
			return -1;
		count++;
		newaddress = (newaddress + offset) % HASH_LEN;//加偏移量后再求地址
	}
	return newaddress + 1;
}

//计算哈希地址
int HashList::hashAddress(int key)
{
	int newaddress, offset = 3;//新的地址，偏移量为3
	newaddress = key % HASH_LEN;
	while (isCollision(newaddress)) {
		newaddress = (newaddress + offset) % HASH_LEN;//加偏移量后再求地址
	}
	hashArray[newaddress] = key;//没有冲突将此数放入这个地址中
	return newaddress;
}
//冲突处理查询地址存放的数是否为-1
int HashList::isCollision(int address)
{
	return hashArray[address] == -1 ? false : true;//如果为-1返回false没有冲突否则返回true出现冲突
}

void HashList::inputData()
{
	int number;//输入的数据
	cout << "请输入五个数据" << endl;
	for (int i = 0;i<NUMBER;i++) {
		cin >> number;
		hashAddress(number);
	}
}

void HashList::traveral()
{
	cout << "哈希表的数据为:" << endl;
	for (int i = 0;i<HASH_LEN;i++)
	{
		if (hashArray[i] == -1)
			cout << "[" << i + 1 << "]" << "-->" << "空" << endl;
		else
			cout << "[" << i + 1 << "]" << "-->" << hashArray[i] << endl;
	}
}


//查找函数
int HashList::hashSearch(int key)
{
	if (getHash(key) == -1)
		cout << key << "没有找到！" << endl;
	else
		cout << key << "的哈希地址是:" << getHash(key) << endl;
	return 0;
}

int main()
{
	system("color f0");
	system("title 实验七-哈希查找");
	int key;
	HashList my;
	my.inputData();
	
	for (; ; )
	{
		system("cls");
		my.traveral();
		cout << endl;
		cout << "输入一个数我们将查找它(-1表示退出)" << endl;
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