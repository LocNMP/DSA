//C9 — P3 — Sắp xếp luồng thẻ bài trực tuyến
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

    long long soLanDich = 0;

    for (int i = 1; i < n; i++) {
        long long key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            soLanDich++;
            j--;
        }

        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << "\n";
    cout << soLanDich;

    return 0;
}