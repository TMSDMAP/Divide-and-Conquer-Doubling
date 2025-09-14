#include <iostream>
using namespace std;
//所有子集和为2^n-1*(a1+a2+...+an)
typedef long long ll;
ll s[35];
int main() {
	int n;
	ll sum = 0;
	ll num = 0;
	while (cin >> n)
	{
		sum += n;
		num++;
	}
	cout << (1LL << (num - 1)) * sum << endl;
	return 0;
}