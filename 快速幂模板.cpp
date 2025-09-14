#include <iostream>
using namespace std;
//快速幂原理，将指数拆分为二进制形式，然后通过平方和乘法来计算幂（每次b右移一位，检查是否为1，如果是就与a相乘，a每次移动都自乘(平方)）
long long qpow(long long a, long long b, long long mod) {
	long long res = 1;
	a %= mod; //防止a过大
	while (b) {
		if(b&1)
			res = res * a % mod; //如果b的当前位是1，就乘上a
		a = a * a % mod; //a自乘(平方)
		b >>= 1; //b右移一位
	}
	return res;
}

int main() {
	long long a, b, p;
	cin >> a >> b >> p;
	long long res = qpow(a, b, p);
	printf("%lld^%lld mod %lld=%lld", a, b, p, res);
	return 0;
}