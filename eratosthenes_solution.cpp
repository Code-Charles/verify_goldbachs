#include "method.h"

void screening(bool*prime,ll maxValue)       //����ɸѡ 
{
//	memset(prime,true,sizeof(prime));  //��ʼ�����ٶ���Ϊ���� 
	prime[0] = false;      
	prime[1] = false;         
	for(ll i=2;i<maxValue;++i)
		prime[i]=true;
	ll s = sqrt(maxValue);
	for(ll i = 2;i<s;++i)
	{
		if(prime[i])
		{
			for(ll j=i*i;j<maxValue;j+=i) //���ǵ�i*x��x<i)�ѱ��޳�����i*i��ʼ 
			{
				prime[j] = false;
			}
		 } 
	 } 
}
void eratosthenes(ll *test, int length)
{
	ll maxValue = * max_element(test, test+length);  //��ȡ������������ֵ����ȷ����������ɸѡ�ķ�Χ 
	maxValue = (maxValue>2)?maxValue:2;              //����maxValue��С������warnning 
	// ����prime ���������������ڴ�� 0~maxValue������������ true��ʾ 
	bool *prime = new bool[maxValue+1];      
	screening(prime,maxValue);
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
	cout << "Bye!\n";
	delete[] prime;
}





