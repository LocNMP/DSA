//C9 — P2 — Tối ưu hóa lượt ghi bộ nhớ Flash
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

    int soLanSwap = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(a[i], a[minIndex]);
            soLanSwap++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << "\n";
    cout << soLanSwap;

    return 0;
}