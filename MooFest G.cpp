/*#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e4 + 5;
int n;
int v[MAXN], x[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> v[i] >> x[i];
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll tmp = 0;
		for (int j = i + 1; j < n; j++)
		{
			tmp = max(v[i], v[j]) * abs(x[i] - x[j]);
			ans += tmp;
		}
	}
	printf("%lld\n", ans);
	return 0;
}*/
//暴力会超时

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll total = 0;
const int MAXN = 5e5 + 5;
int value[MAXN], pos[MAXN]; // v[i] 和 x[i]
int sorted_idx[MAXN], temp[MAXN]; // id 和临时数组


//比较函数
bool cmp(int i, int j) {
	return pos[i] < pos[j];
}

//归并排序

ll merge_sort(int left, int right) {
	if (left == right) return pos[sorted_idx[left]];
	int mid = (left + right) / 2;
	ll left_sum = merge_sort(left, mid);
	ll right_sum = merge_sort(mid + 1, right);

	ll res_l = left_sum;  //左半部分剩余x和
	ll res_r = right_sum; //右半部分剩余x和

	int left_p = left, right_p = mid + 1;
	int temp_p = left; //临时数组指针

	//归并
	while (left_p <= mid && right_p <= right) {
		if (value[sorted_idx[left_p]] > value[sorted_idx[right_p]])
		{
			int cur = sorted_idx[left_p];
			total += (ll)value[cur] * (res_r - (ll)pos[cur] * (right - mid));
			res_l -= pos[cur];
			temp[temp_p++] = sorted_idx[left_p++];
		}
		else
		{
			int cur = sorted_idx[right_p];
			total += (ll)value[cur] * ((ll)pos[cur] * (mid - left + 1) - res_l);
			res_r -= pos[cur];
			temp[temp_p++] = sorted_idx[right_p++];
		}
	}
	while (left_p <= mid) {
		temp[temp_p++] = sorted_idx[left_p++];
	}
	while (right_p <= right) {
		temp[temp_p++] = sorted_idx[right_p++];
	}
	for (int i = left; i <= right; i++) {
		sorted_idx[i] = temp[i];
	}
	return left_sum + right_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
				cin >> value[i] >> pos[i];
				sorted_idx[i] = i;
	}
	sort(sorted_idx + 1, sorted_idx + n + 1, cmp);
	merge_sort(1, n);
	cout << total << endl;
	return 0;
}
