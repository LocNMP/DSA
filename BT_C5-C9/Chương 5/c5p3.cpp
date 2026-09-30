#include <iostream>
using namespace std;

const int MAXN = 200005;
long long a[MAXN];
long long pref[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, q; cin >> n >> q;
	pref[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	while (q) {
		int l, r; cin >> l >> r;
		cout << pref[r + 1] - pref[l] << endl;
		q--;
	}

}