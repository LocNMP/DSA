//C2 — P4 — So sánh Space-Time Tradeoff trong Kiểm tra Đơn hàng Trùng lặp
#include <iostream>
#include <vector>
using namespace std;

struct Result {
	bool duplicate;
	long long steps;
	int aux_space;
};

Result approachA(const vector<int>& A) {
	int n = A.size();
	long long steps_A = 0;
	int aux_space_A = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			steps_A++;
			if (A[i] == A[j]) {
				return {true, steps_A, aux_space_A};
			}
		}
	}

	return {false, steps_A, aux_space_A};
}
Result approachB(const vector<int>& A, int M) {
	int n = A.size();
	long long steps_B = 0;
	int aux_space_B = M + 1;
	vector<int> seen(M + 1, 0);
	for (int i = 0; i < n; i++) {
		steps_B++;
		if (seen[A[i]] == 1) {
			return {true, steps_B, aux_space_B};
		}
		seen[A[i]] = 1;
		steps_B++;
	}
	return {false, steps_B, aux_space_B};
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	Result A_result = approachA(A);
	Result B_result = approachB(A, M);

	bool has_duplicate = A_result.duplicate || B_result.duplicate;

	cout << "HAS_DUPLICATE: "
		 << (has_duplicate ? "YES" : "NO") << '\n';

	cout << "APPROACH_A: "
		 << A_result.steps << " steps, "
		 << A_result.aux_space << " aux_space\n";

	cout << "APPROACH_B: "
		 << B_result.steps << " steps, "
		 << B_result.aux_space << " aux_space\n";

	// So sánh số phép toán
	if (A_result.steps < B_result.steps) {
		cout << "FASTER_APPROACH: APPROACH_A\n";
	}
	else if (B_result.steps < A_result.steps) {
		cout << "FASTER_APPROACH: APPROACH_B\n";
	}
	else {
		cout << "FASTER_APPROACH: EQUAL\n";
	}
	return 0;
}
