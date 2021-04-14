#include "method.h"

void screening(bool*prime,ll maxValue)       //进行筛选 
{
//	memset(prime,true,sizeof(prime));  //初始化，假定都为素数 
	prime[0] = false;      
	prime[1] = false;         
	for(ll i=2;i<maxValue;++i)
		prime[i]=true;
	ll s = sqrt(maxValue);
	for(ll i = 2;i<s;++i)
	{
		if(prime[i])
		{
			for(ll j=i*i;j<maxValue;j+=i) //考虑到i*x（x<i)已被剔除，从i*i开始 
			{
				prime[j] = false;
			}
		 } 
	 } 
}
void eratosthenes(ll *test, int length)
{
	ll maxValue = * max_element(test, test+length);  //获取数列中最大的数值，以确定进行素数筛选的范围 
	maxValue = (maxValue>2)?maxValue:2;              //避免maxValue过小，产生warnning 
	// 建立prime 布尔类型数组用于存放 0~maxValue所有数的类型 true表示 
	bool *prime = new bool[maxValue+1];      
	screening(prime,maxValue);
	for (int i = 0; i < length; i++)
	{
		if (test[i] <= 2)
			cout << test[i] << " 小于等于2，不能验证哥德巴赫猜想\n";
		else if (test[i] % 2)
			cout << test[i] << " 是奇数，不能验证哥德巴赫猜想\n";
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
	cout << "Bye!\n";
	delete[] prime;
}





