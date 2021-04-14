#include "method.h"
/*
作者：陈铮
修改时间：20210411
内容：验证哥德巴赫猜想 
*/
const int MAX = 1000; 
void menu(ll*test,int length)
{
	cout<<"-----可供选择的方法如下，超过允许范围可能造成程序停滞！\n";
	cout << "--1--优雅的暴力求解法(允许4~1e14)" << endl;
	cout << "--2--埃拉托斯特尼筛法（允许4~1e5）"<<endl; 
	cout<<"--3--欧拉筛法（允许4~1e5)"<<endl; 
	cout << "--4--米勒-拉宾素性检验法(允许4~1e17)" << endl;
	cout << "--0--退出\n" << endl;
	cout << "-----请选择进行素数测试的方法：\n";
	while(1) 
	{
		int a;
		cin >> a;
		switch (a)
		{
			case 1:
				cout << "-----正在执行优雅的暴力求解法\n";
				violent(test, length); break;
			case 2:
				cout << "-----正在执行埃拉托斯特尼筛法\n";
				eratosthenes(test, length); break;
			case 3:
				cout<<"------正在执行欧拉筛法\n";
				euler(test,length);
			case 4:
				cout << "-----正在执行米勒-拉宾素性检验法\n";
				miller_rabin(test, length); break;
			case 0:
				break;
			default:
				cout<<"-----无该选项，请输入0~4之间的数\n" ;
		}
		cout<<"-----尝试其他方法（or手动关闭）：";
	}
}
int input(ll*test)
{ 
	int i=0;
	while (1)   
	{
		cout << "-----当前正在输入第" << i + 1 << "个数(4~1e17)：";
		cin >> test[i];
		string s = to_string(test[i]);
		if ((!cin) || (s.size() > 18))
		{
			printf("\n-----输入有误！请重新输入\n");
			cin.clear();
			cin.sync();   //清空流
			continue;
		}
		if (0 == test[i])
			break;		
		++i;
	}
	int length = 0;
	for (int i = 0;; ++i)
	{
		if (!test[i])
			break;
		++length;
	}
	return length;
}
int main()
{
	printf("=======This is a program for Goldbach=======\n");
	cout << "-----请输入用于测试哥德巴赫猜想的数的序列：\n";
	cout << "-----支持测试1000个数\n";
	ll test[MAX];
	int length = input(test);    //输入用于验证哥德巴赫猜想的数并返回数列长度 
	menu(test,length);
}
