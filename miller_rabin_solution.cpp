#include "method.h"
ll mul(ll a, ll b, ll mod) {//高精度
    a %= mod;
    b %= mod;
    ll c = (long double)a * b / mod;
    ll ans = a * b - c * mod;
    return (ans % mod + mod) % mod;
}
ll pow_mod(ll x, ll n, ll mod) {//快速幂
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

    //把n-1  转化成 (2^r)*d
    ll s = n - 1, r = 0;
    while ((s & 1) == 0) {
        s >>= 1; r++;
    }

    //算出 2^d  存在 k 里
    ll k = pow_mod(a, s, n);

    //二次探测  看变化过程中是不是等于1 或 n-1
    if (k == 1)return true;
    for (int i = 0; i < r; i++, k = k * k % n) {
        if (k == n - 1)return true;
    }
    return false;
}
bool miller(ll n) {
    //这里可以随机取a值进行探测  探测次数可以自己定

    ll times = 7;
    ll prime[100] = { 2,3,5,7,11,233,331 };
    for (int i = 0; i < times; i++) {
        if (n == prime[i])
            return true;
        if (Miller_Rabbin(prime[i], n) == false)
            return false;//未通过探测 返回假
    }
    return true;//所有探测结束 返回真
}



void miller_rabin(ll* test, int length)
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
	cout<<"--------米勒-拉宾素性检验法耗时："<<(end-start)<<"ms\n"; 
	cout << "Bye!\n";
	return;
}
