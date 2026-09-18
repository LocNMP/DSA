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

	int i = 0;
	int j = n - 1;

	while (i < j) {
		long long tong = a[i] + a[j];

		if (tong == T) {
			cout << i << " " << j;
			return 0;
		}
		else if (tong < T) {
			i++;
		}
		else {
			j--;
		}
	}

	cout << -1;

	return 0;
}