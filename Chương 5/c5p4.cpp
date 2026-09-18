#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long A[100005], B[100005];
	long long hop[200005];

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	int i = 0;
	int j = 0;
	int soLuongHop = 0;
	int soLuongGiao = 0;

	while (i < n && j < m) {
		if (A[i] < B[j]) {
			hop[soLuongHop++] = A[i];
			i++;
		}
		else if (A[i] > B[j]) {
			hop[soLuongHop++] = B[j];
			j++;
		}
		else {
			hop[soLuongHop] = A[i];
			soLuongHop++;
			soLuongGiao++;
			i++;
			j++;
		}
	}
	while (i < n) {
		hop[soLuongHop] = A[i];
		soLuongHop++;
		i++;
	}
	while (j < m) {
		hop[soLuongHop] = B[j];
		soLuongHop++;
		j++;
	}

	cout << soLuongHop << endl;

	for (int i = 0; i < soLuongHop; i++) {
		cout << hop[i] << " ";
	}
	cout << endl;
	cout << soLuongGiao << endl;

}