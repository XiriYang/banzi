#include<bits/stdc++.h>
using namespace std;
int quick_pow1(int a, int b)//快速幂1
{
	int ans = 1;
	while (b)
	{
		if (b & 1)ans *= a;
		b = b >> 1;//取出每一位
		a *= a;//复用
	}
	return ans;
}
long long quick_pow2(long long a, long long b, long long p)//快速幂2
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)ans = (ans * a) % p;
		b = b >> 1;//取出每一位
		a = (a * a) % p;//复用
	}
	return ans;
}
int main()
{
	int a = 5, b = 50;
	cout << quick_pow2(a, b, 999999999);
	return 0;
}