# verify_goldbachs
程序设计语言课程作业2
验证哥德巴赫猜想
——《程序设计语言》作业2
1900012403 陈铮
##第一部分：作业说明
【Problem】对1000(含)以内的偶数，验证哥德巴赫猜想是否成立
【Input】	
1.每次输入都是一个不超过1000的整数N，表示需要验证的数
	2.程序需要保持接受用户输入的状态，只有当输入数字为0的时候，程序才停止运行
	3.从程序启动到接受用户输入的响应时间不超过10s
【Output】
	每一次的输出形式为X=Y+Z,其中X是输入的数，Y和Z为两个素数(Y<=Z)
	R如果X有多于一种分解方法，则只输出正确的一组即可，不需要全部输出
	如果输入不合理或会导致异常，需要进行处理并给出清晰的提示信息，但不可终止程序运行
##第二部分：求解方法
	分析题中要求的哥德巴赫猜想验证要求得知，问题的关键在于如何寻找素数Y、Z，使其和为X，思考得知，只需遍历X的所有X = Y+Z，判断Y、Z是否满足同时为素数，即可完成问题的输出，如下：
'''
	for (int i = 0; i < length; i++){  
	    if (test[i] <= 2)  
	        cout << test[i] << "小于等于2，不能验证哥德巴赫猜想\n";  
	    else if (test[i] % 2)  
	        cout << test[i] << "是奇数，不能验证哥德巴赫猜想\n";  
	    for (int j = 2; j < test[i]; ++j)  
	    {  
	        if (isPrime(j) && isPrime(test[i] - j))  
	        {  
	            cout << test[i] << " = " << j << " + " << test[i] - j << endl; break;  
	        }  
	    }  
	//test数组用于存放用于验证哥德巴赫猜想的数列，length表示数组长度
	//isPrime函数用于判定Y,Z是否为素数
'''
	由此，验证哥德巴赫猜想问题即转化为对Y和Z的素数判定问题
##第三部分：素数判定
###一、优雅的暴力求解法
1.1实现思路
	暴力求解法指直接利用素数的定义，即不存在1和自身之外的因数，对将要进行素数判定的数n进行从3到n-1的除数求余判定，出现余数为0，则不是素数
1.2细节说明
	在算法实现过程中发现，对于判定数n可以分解为6x+1、6x+2、6x+3、6x+4、6x+5、6x中一类，进一步分析可知素数只能为6x+1或6x+5。
考虑到满足6x+1或6x+5不一定为素数，由初中时学习的质因数分解可知，若6x+1或6x+5为合数，则一定能分解质因数。再联系上一段的结论可知，可分解的质因数同样包含在6x+1和6x+5中（质因数不可能为2或3）。
据此可对算法进行优化，算法步骤如下：
	判断n是否为2或3，是则返回true
	判断n是否为6相邻的数，否则返回false
	判断n是否存在与6的倍数相邻的因数，是则返回false
	返回true
1.3补充说明
	相较于直接暴力求解，优化后的优雅暴力求解法已经能够达到要求，甚至优于多数素数判定方法，或许已经无需再称之为暴力了。
###二、埃拉托斯特尼筛法
2.1 实现思路
	对于需要验证的数列，获取其中最大数maxValue，进而建立长为maxValue+1的动态数组（bool类型），分别用于表示0~maxValue数的素性（true标识该数为素数）。
	首先假定2~maxValue同为素数，之后进行遍历，每遍历一个素数，将素数的所有倍数（小于maxValue）标识为合数，从而得到一个长度为maxValue+1的用于探测一个数是否为素数的数组
2.2 细节说明
'''
	void screening(bool*prime,ll maxValue)       //进行筛选   
	{  
	//  memset(prime,true,sizeof(prime));  //初始化，假定都为素数   
	    prime[0] = false;        
	    prime[1] = false;           
	    for(ll i=2;i<maxValue;++i)  
	        prime[i]=true;  
	    for(ll i = 2;i<maxValue;+i)  
	    {  
	        if(i*i>maxValue) break;   //简化  
	        if(prime[i])  
	        {  
	            for(ll j=i*i;j<maxValue;j+=i) //考虑到i*x（x<i)已被剔除，从i*i开始   
	            {  
	                prime[j] = false;  
	            }  
	         }   
	     }   
	}  
'''
2.3 补充说明
	埃拉托斯特尼筛法通常用于筛选一定范围的所有素数，在本次作业中，如果我们打算利用验证11110000、8两数验证哥德巴赫猜想，则需要判断1~11110000范围内所有书的素性，然后根据各自素性进一步求取和式，这导致该方法其实并不太适用于该作业要求
	此外，埃拉托斯特尼筛法会发生重复筛选
###三、欧拉筛法
3.1 实现思路
	欧拉筛法是对埃拉托斯特尼筛法的优化，其关键在于保证每个合数只被这个合数最小的质因子筛除，该方法实现方法取自网络（个人不太理解）
欧拉筛的难点就在于对if (i % storage[j] == 0)这步的理解，当i是storage [j]的整数倍时，记 m = i / storage [j]，那么 i * storage [j+1] 就可以变为 (m * storage [j+1]) * storage [j]，这说明 i * storage [j+1] 是 storage [j] 的整数倍，不需要现在筛出，因为在之后筛除过程中i * storage [j+1] 这个合数一定会被storage [j]筛除，storage [j]之后的所有素数同理，所以break跳出循环
	细节说明
'''
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
'''
3.3 补充说明
	同样不太适用于本次作业

###四、米勒-拉宾素性检验法
4.1 实现思路
米勒-拉宾素性检验主要运用两个定理
	如果p是质数，那么a^(p-1)≡1(mod p)
	若p是素数，且0<x<p,则方程x^2≡1(mod p)的解为x=1，p-1
	假设n是奇素数，则n-1必为偶数。令n-1=2^q×m
	随机选取整数a(0<a<n)，由费马定理，a^(2^q×m)=a^(n-1)≡1(mod q)，由二次探测定理可知：a^(2^(q-1)×m)≡1(mod n)或a^(2^(q-1)×m)≡n-1(mod n)。若a^(2^(q-1)×m)≡1(mod n)成立，再由二次探测定理可知：若a^(2^(q-2)×m)≡1(mod n)或a^(2^(q-2)×m)≡n-1(mod n)。……。
	反复利用二次探测定理，知道某一步a^m≡1(mod n)或a^m≡n-1(mod n)。总之，若n为素数，则a^m≡1(mod n)，或存在a^m 0≤r≤q-1，使a^(2^r×m)≡n-1(mod n)

4.2 细节说明
'''
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
'''
4.3 补充说明
	优点是验证素性时极其强大，对long long 类型数几乎都是0ms完成
	缺点是算法复杂，尝试n次头痛欲裂后，决定参考已有代码
