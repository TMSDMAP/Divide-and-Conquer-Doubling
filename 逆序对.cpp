#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll merge(vector<int>& a, int l, int mid, int r) {
	vector<int> tmp(r - l + 1);
	int i = l, j = mid + 1, k = 0;
	ll cnt = 0;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
			cnt += mid - i + 1; // 因为 a[i] > a[j]，所以 a[i] 及其后面的元素都大于 a[j]，都算逆序对
		}
	}
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= r) tmp[k++] = a[j++];
	for (int t = 0; t < k; ++t) a[l + t] = tmp[t];
	return cnt;
}

ll mergeSort(vector<int>&a, int l, int r) {
		if (l >= r) return 0;
		int mid = (l + r) >> 1;
		ll cnt = 0;
		cnt += mergeSort(a, l, mid);
		cnt += mergeSort(a, mid + 1, r);
		cnt += merge(a, l, mid, r);
		return cnt;
}

int main() {
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cout << mergeSort(a, 1, n) << endl;
	return 0;
}
