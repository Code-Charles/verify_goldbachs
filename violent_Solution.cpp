#include  "method.h"

bool isPrime(ll n )
{
	if(n==2||n==3)
		return true;
	if((n%6!=1)&&(n%6!=5))    //素数一定与6的倍数相邻 
		return false;
	ll s = ll(sqrt(n));       
	for(ll i=5;i<s;i+=6)
		if(n%i==0||n%(i+2)==0)  //与6相邻并不一定为素数，二次检验 
			return false;
	return true;
	
}
void violent(ll* test, int length)
{
	DWORD start = GetTickCount();
	for (int i = 0; i < length; i++)
	{
		if (test[i] <= 2)
			cout << test[i] << "小于等于2，不能验证哥德巴赫猜想\n";
		else if (test[i] % 2)
			cout << test[i] << "是奇数，不能验证哥德巴赫猜想\n";
		else
		{ 
			for (int j = 2; j < test[i]; ++j)
			{
				if (isPrime(j) && isPrime(test[i] - j))
				{
					cout << test[i] << " = " << j << " + " << test[i] - j << endl;
					break;
				}
			}
		} 

	}
	DWORD end = GetTickCount();
	cout<<"--------暴力求解法耗时："<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
}
