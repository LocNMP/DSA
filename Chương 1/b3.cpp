#include <iostream>
using namespace std;

const int MAXN = 200005;
long long a[MAXN];
long long pref[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, m; cin >> n >> k >> m;
	long long limit;
	cin >> limit;
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	for (int i = 0; i <= n - m; ++i) {
		long long sum = pref[i + m] - pref[i];

		if (sum > limit) {
			cout << m << " " << i << endl;
			return 0;
		}
	}
	cout << -1 ;
}