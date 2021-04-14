#include "method.h"
ll mul(ll a, ll b, ll mod) {//�߾���
    a %= mod;
    b %= mod;
    ll c = (long double)a * b / mod;
    ll ans = a * b - c * mod;
    return (ans % mod + mod) % mod;
}
ll pow_mod(ll x, ll n, ll mod) {//������
    ll res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, x, mod);
        x = mul(x, x, mod);
        n >>= 1;
    }
    return (res + mod) % mod;
}
bool Miller_Rabbin(ll a, ll n) {

    //��n-1  ת���� (2^r)*d
    ll s = n - 1, r = 0;
    while ((s & 1) == 0) {
        s >>= 1; r++;
    }

    //��� 2^d  ���� k ��
    ll k = pow_mod(a, s, n);

    //����̽��  ���仯�������ǲ��ǵ���1 �� n-1
    if (k == 1)return true;
    for (int i = 0; i < r; i++, k = k * k % n) {
        if (k == n - 1)return true;
    }
    return false;
}
bool miller(ll n) {
    //����������ȡaֵ����̽��  ̽����������Լ���

    ll times = 7;
    ll prime[100] = { 2,3,5,7,11,233,331 };
    for (int i = 0; i < times; i++) {
        if (n == prime[i])
            return true;
        if (Miller_Rabbin(prime[i], n) == false)
            return false;//δͨ��̽�� ���ؼ�
    }
    return true;//����̽����� ������
}



void miller_rabin(ll* test, int length)
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
			for (int j = 3; j < test[i]; ++j)
			{
				if (miller(j) && miller(test[i] - j))
				{
					cout << test[i] << " = " << j << " + " << test[i] - j << endl;
					break;
				}
			}
		} 
	}
	DWORD end = GetTickCount();
	cout<<"--------����-�������Լ��鷨��ʱ��"<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
	return;
}
