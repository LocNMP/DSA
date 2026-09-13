//C3 — P1 — Phân tích Tốc độ Tăng trưởng Pipeline Đánh giá Chất lượng Dữ liệu
#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int k1, k2, k3; cin >> k1 >> k2 >> k3;
	long long Total = k1 + k2*n + k3*n*(n-1)/2;
	string growth_class = "";
	if (k3 > 0 && n >= 2) {
		growth_class = "O(n^2)";
	}
	else if (k3 == 0 && k2 > 0) {
		growth_class = "O(n)";
	}
	else if (k3 == 0 && k2 == 0) {
		growth_class = "O(1)";
	}
	cout << Total << endl;
	cout << growth_class;
}