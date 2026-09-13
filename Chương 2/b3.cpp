//C2 — P3 — Kiểm tra dây chuyền sản xuất: Best, Worst và Average Case
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout << fixed << setprecision(1);
	int n, q; cin >> n >> q;
	int a[n];
	int step_count = 0;
	bool found_error = false;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		step_count += 1;
		if (a[i] < q) {
			found_error = true;
			break;
		}
	}
	if (found_error) {
		if (step_count == 1) {
			cout << step_count << endl;
			cout << "BEST" << endl;
			cout << 1 << " " << n << " " << 1.0*(n + 1)/2;
		}
		else if (step_count == n) {
			cout << step_count << endl;
			cout << "WORST" << endl;
			cout << 1 << " " << n << " " << 1.0*(n + 1)/2;
		}
		else {
			cout << step_count << endl;
			cout << "AVERAGE" << endl;
			cout << 1 << " " << n << " " << 1.0*(n + 1)/2;
		}
	}
	else {
		cout << step_count << endl;
		cout << "WORST" << endl;
		cout << 1 << " " << n << " " << 1.0*(n + 1)/2;
	}

}