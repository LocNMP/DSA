#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	long long T;
	cin >> n >> T;

	long long a[200005];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 0;
	long long tong = 0;
	int doDaiNhoNhat = n + 1;

	for (int right = 0; right < n; right++) {
		tong += a[right];

		while (tong >= T) {
			int doDai = right - left + 1;

			if (doDai < doDaiNhoNhat) {
				doDaiNhoNhat = doDai;
			}

			tong -= a[left];
			left++;
		}
	}

	if (doDaiNhoNhat == n + 1) {
		cout << -1;
	}
	else {
		cout << doDaiNhoNhat;
	}

	return 0;
}