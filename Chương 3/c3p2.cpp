//C3 — P2 — Phân loại Tốc độ Tăng trưởng trong Dashboard Code Review
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int a, b, c, d; cin >> a >> b >> c >> d;
	long long log_n = floor(log2(n));
	long long T = 1ll * a * n * n + 1ll * b * n * log_n + 1ll * c * n + 1ll * d;
	string growth_class = "";
	if (a > 0) {
		growth_class = "O(n^2)";
	}
	else if (a == 0 && b > 0) {
		growth_class = "O(n log n)";
	}
	else if (a == 0 && b == 0 && c > 0) {
		growth_class = "O(n)";
	}
	else if (a == 0 && b == 0 && c == 0) {
		growth_class = "O(1)";
	}
	cout << T << endl;
	cout << growth_class;
}