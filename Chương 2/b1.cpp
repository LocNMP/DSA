// C2 — P1 — Phân tích chi phí giám sát Server Log
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t; cin >> n >> t;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ops = 0, over_count = 0, max_val = -1, pair_count = 0;
	for (int i = 0; i < n; i++) {
		ops += 1;
		if (a[i] >= t) {
			over_count += 1;
			ops += 1;
		}
		ops += 1;
		if (a[i] > max_val) {
			max_val = a[i];
			ops += 1;
		}
	}
	if (over_count > 0) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ops += 1;
				if (abs(a[i] - a[j]) > t) {
					pair_count += 1;
					ops += 1;
				}
			}
		}
	}
	cout << ops << endl;
	cout << over_count << " " << pair_count;

}