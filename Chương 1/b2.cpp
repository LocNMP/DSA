#include <iostream>
using namespace std;

int firstpos(int a[], int n, int k) {
	int l = 0, r = n - 1;
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == k) {
			res = m;
			r = m - 1;
		}
		else if (a[m] < k) {
			l = m + 1;
		}
		else r = m - 1;
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int start1 = firstpos(a, n, 0)
	, start2 = firstpos(a, n, 1),
	start3 = firstpos(a, n, 2);
	cout << start1 << " " << start2 << " " << start3;
	cout << endl;
	for (int x : a) {
		cout << x << " ";
	}
}