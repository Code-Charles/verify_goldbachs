#include "method.h"
#include<vector>
/*欧拉筛思想的核心是要保证的是每个合数只被这个合数最小的质因子筛除，
而且只筛一次，没有重复筛除，这里就需要用到这行神秘代码if(i%prime[j]==0) break;。

欧拉筛的难点就在于对if (i % prime[j] == 0)这步的理解，
当i是prime[j]的整数倍时，记 m = i / prime[j]，
那么 i * prime[j+1] 就可以变为 (m * prime[j+1]) * prime[j]，
这说明 i * prime[j+1] 是 prime[j] 的整数倍，
不需要现在筛出，因为在之后筛除过程中i * prime[j+1] 这个合数一定会被prime[j]筛除，
prime[j]之后的所有素数同理，所以break跳出循环
*/
void screening_2(bool*prime,ll maxValue)       //进行筛选 
{
	memset(prime,true,sizeof(prime));  //初始化，假定都为素数 
	prime[0] = false;      
	prime[1] = false;           
	vector<int> storage;      //存放素数的不定长数组 
	ll count=0;             //记录storage的大小 
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
	maxValue = (maxValue>2)?maxValue:2;            //避免maxValue过小，产生warnning 
	bool *prime = new bool[maxValue+1];   // 建立prime 布尔类型数组用于存放 0~maxValue所有数的类型 
	screening_2(prime,maxValue);
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
	DWORD end = GetTickCount();
	cout<<"--------欧拉筛法耗时："<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
	delete[] prime;
}
