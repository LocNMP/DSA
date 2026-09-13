//C3 — P3 — Phân tích Vòng lặp Logarithm trong Hệ thống Troubleshooting Mạng
#include <iostream>
using namespace std;

long long count(long long n, int k) {
	long long steps = 0;
	while (n >= 1) {
		n /= k;
		steps++;
	}
	return steps;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long n;
	cin >> n;
	long long SA = count(n, 2);
	long long SB = count(n, 3);
	long long SC = count(n, 10);

	cout << SA << ' ' << SB << ' ' << SC << '\n';
	cout << "O(log n)";
}