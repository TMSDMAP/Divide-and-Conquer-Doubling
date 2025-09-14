#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];

	vector<int> lg(m + 1);
	lg[1] = 0;
	for (int i = 2; i <= m; i++) lg[i] = lg[i / 2] + 1;
	int k = lg[m];
	//st[k][i]:i+2^k-1 .[i,i+2^k-1]
	vector<vector<int>> st(k + 1, vector<int>(m));
	for (int i = 0; i < m; i++) st[0][i] = a[i];
	for (int j = 1; j <= k; j++) {
		int len = 1 << j;
		for (int i = 0; i + len - 1 < m; i++)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}

	for (int q = 0; q < n; q++) {
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		l--; r--;
		int len = r - l + 1;
		int k = lg[len];
		int ans = min(st[k][l], st[k][r - (1 << k) + 1]);
		if (q) cout << " ";
		cout << ans;
	}
	cout << "\n";
	return 0;
}