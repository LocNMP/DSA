//C9 — P5 — Phân tích độ hỗn loạn dữ liệu và đếm số cặp nghịch thế
#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long long a[5005];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long k = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                k++;
            }
        }
    }

    cout << k << "\n";

    if (k == 0) {
        cout << "SORTED\n";
    }
    else if (k <= n) {
        cout << "NEARLY SORTED\n";
    }
    else {
        cout << "HIGHLY DISORDERED\n";
    }

    cout << k;

    return 0;
}