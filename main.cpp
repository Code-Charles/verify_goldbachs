#include "method.h"
/*
���ߣ����
�޸�ʱ�䣺20210411
���ݣ���֤��°ͺղ��� 
*/
const int MAX = 1000; 
void menu(ll*test,int length)
{
	cout<<"-----�ɹ�ѡ��ķ������£���������Χ������ɳ���ͣ�ͣ�\n";
	cout << "--1--���ŵı�����ⷨ(����4~1e14)" << endl;
	cout << "--2--������˹����ɸ��������4~1e5��"<<endl; 
	cout<<"--3--ŷ��ɸ��������4~1e5)"<<endl; 
	cout << "--4--����-�������Լ��鷨(����4~1e17)" << endl;
	cout << "--0--�˳�\n" << endl;
	cout << "-----��ѡ������������Եķ�����\n";
	while(1) 
	{
		int a;
		cin >> a;
		switch (a)
		{
			case 1:
				cout << "-----����ִ�����ŵı�����ⷨ\n";
				violent(test, length); break;
			case 2:
				cout << "-----����ִ�а�����˹����ɸ��\n";
				eratosthenes(test, length); break;
			case 3:
				cout<<"------����ִ��ŷ��ɸ��\n";
				euler(test,length);
			case 4:
				cout << "-----����ִ������-�������Լ��鷨\n";
				miller_rabin(test, length); break;
			case 0:
				break;
			default:
				cout<<"-----�޸�ѡ�������0~4֮�����\n" ;
		}
		cout<<"-----��������������or�ֶ��رգ���";
	}
}
int input(ll*test)
{ 
	int i=0;
	while (1)   
	{
		cout << "-----��ǰ���������" << i + 1 << "����(4~1e17)��";
		cin >> test[i];
		string s = to_string(test[i]);
		if ((!cin) || (s.size() > 18))
		{
			printf("\n-----������������������\n");
			cin.clear();
			cin.sync();   //�����
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
	cout << "-----���������ڲ��Ը�°ͺղ�����������У�\n";
	cout << "-----֧�ֲ���1000����\n";
	ll test[MAX];
	int length = input(test);    //����������֤��°ͺղ���������������г��� 
	menu(test,length);
}
