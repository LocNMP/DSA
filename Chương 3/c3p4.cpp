//C3 — P4 — Kiểm chứng Tốc độ Tăng trưởng bằng Doubling Test trong Công cụ Phát hiện Đạo văn
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout << fixed << setprecision(2);
	int n; cin >> n;
	long long TA_N = n*n, TA_2N = 4*n*n, TA_4N = 16*n*n;
	float  R1_A = TA_2N/TA_N;
	float R2_A = TA_4N/TA_2N;
	double log_n = floor(log2(n));
	double TB_N = n*(log_n + 1), TB_2N = 2*n*(log_n + 2), TB_4N = 4*n*(log_n + 3);
	float  R1_B = TB_2N/TB_N;
	float R2_B = TB_4N/TB_2N;
	cout << TA_N << " " << TA_2N << " " << TA_4N << endl;
	cout << R1_A << " " << R2_A << endl;
	cout << (long long)TB_N << " " << (long long)TB_2N << " " << (long long)TB_4N << endl;
	cout << R1_B << " " << R2_B << endl;
	cout << "O(n log n)";

}