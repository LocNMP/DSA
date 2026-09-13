//C2 — P2 — Quản lý bộ nhớ phụ trợ trong Lọc dữ liệu Cảm biến
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> valid_data;

	for (int i = 0; i < N; i++) {
		if (A[i] >= K) {
			valid_data.push_back(A[i]);
		}
	}
	int count_A = valid_data.size();
	long long sum_A = 0;
	for (int x : valid_data) {
		sum_A += x;
	}
	int aux_space_A = count_A;
	int count_B = 0;
	long long sum_B = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= K) {
			sum_B += A[i];
			count_B++;
		}
	}
	int aux_space_B = 2;
	int saved_space = aux_space_A - aux_space_B;
	cout << count_B << ' ' << sum_B << '\n';
	cout << aux_space_A << '\n';
	cout << aux_space_B << '\n';
	cout << saved_space << '\n';
}