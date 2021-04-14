#include  "method.h"

bool isPrime(ll n )
{
	if(n==2||n==3)
		return true;
	if((n%6!=1)&&(n%6!=5))    //����һ����6�ı������� 
		return false;
	ll s = ll(sqrt(n));       
	for(ll i=5;i<s;i+=6)
		if(n%i==0||n%(i+2)==0)  //��6���ڲ���һ��Ϊ���������μ��� 
			return false;
	return true;
	
}
void violent(ll* test, int length)
{
	DWORD start = GetTickCount();
	for (int i = 0; i < length; i++)
	{
		if (test[i] <= 2)
			cout << test[i] << "С�ڵ���2��������֤��°ͺղ���\n";
		else if (test[i] % 2)
			cout << test[i] << "��������������֤��°ͺղ���\n";
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
	cout<<"--------������ⷨ��ʱ��"<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
}
