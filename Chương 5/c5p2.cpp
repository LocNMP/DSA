#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k; cin >> n >> k;
	long long a[200005];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long tong = 0;
	for (int i = 0; i < k; i++) {
		tong += a[i];
	}
	long long lonNhat = tong;

	for (int i = k; i < n; i++) {
		tong = tong - a[i - k] + a[i];

		if (tong > lonNhat) {
			lonNhat = tong;
		}
	}

	cout << lonNhat;

	return 0;
}