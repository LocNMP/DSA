#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k; cin >> n >> k;
	int a[n];
	int invalid_cout = 0, step_cout = 0;
	long long  invalid_sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		step_cout += 1;
		if (a[i] == 0) {
			break;
		}
		else {
			step_cout += 1;
			if (a[i] < k) {
				invalid_cout += 1;
				invalid_sum += a[i];
			}
		}
	}
	cout << step_cout << endl;
	cout << invalid_cout << " " << invalid_sum;
}