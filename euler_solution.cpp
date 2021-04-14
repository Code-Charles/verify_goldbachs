#include "method.h"
#include<vector>
/*ŷ��ɸ˼��ĺ�����Ҫ��֤����ÿ������ֻ�����������С��������ɸ����
����ֻɸһ�Σ�û���ظ�ɸ�����������Ҫ�õ��������ش���if(i%prime[j]==0) break;��

ŷ��ɸ���ѵ�����ڶ�if (i % prime[j] == 0)�ⲽ����⣬
��i��prime[j]��������ʱ���� m = i / prime[j]��
��ô i * prime[j+1] �Ϳ��Ա�Ϊ (m * prime[j+1]) * prime[j]��
��˵�� i * prime[j+1] �� prime[j] ����������
����Ҫ����ɸ������Ϊ��֮��ɸ��������i * prime[j+1] �������һ���ᱻprime[j]ɸ����
prime[j]֮�����������ͬ������break����ѭ��
*/
void screening_2(bool*prime,ll maxValue)       //����ɸѡ 
{
	memset(prime,true,sizeof(prime));  //��ʼ�����ٶ���Ϊ���� 
	prime[0] = false;      
	prime[1] = false;           
	vector<int> storage;      //��������Ĳ��������� 
	ll count=0;             //��¼storage�Ĵ�С 
	for(ll i = 2;i<maxValue;++i)
	{
		if(prime[i])
		{
			storage.push_back(i);
			++count;
		 } 
		for(ll j=0;j<count && i*storage[j]<=maxValue;++j)
		{
			prime[i*storage[j]] = false;
			if(i%storage[j]==0) break;
		}
	 } 
}
void euler(ll *test, int length)
{
	DWORD start = GetTickCount();
	ll maxValue = * max_element(test, test+length);
	maxValue = (maxValue>2)?maxValue:2;            //����maxValue��С������warnning 
	bool *prime = new bool[maxValue+1];   // ����prime ���������������ڴ�� 0~maxValue������������ 
	screening_2(prime,maxValue);
	for (int i = 0; i < length; i++)
	{
		if (test[i] <= 2)
			cout << test[i] << " С�ڵ���2��������֤��°ͺղ���\n";
		else if (test[i] % 2)
			cout << test[i] << " ��������������֤��°ͺղ���\n";
		else
		{ 
			for (int j = 3; j < test[i]; ++j)
			{
				if (prime[j] && prime[test[i] - j])
				{
					cout << test[i] << " = " << j << " + " << test[i] - j << endl;
					break;
				}
			}
		} 
	}
	DWORD end = GetTickCount();
	cout<<"--------ŷ��ɸ����ʱ��"<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
	delete[] prime;
}
