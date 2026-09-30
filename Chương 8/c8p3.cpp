//C8 — P3 — Cân bằng tải phiên truy cập
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    unordered_map<long long, int> viTriDau;

    long long prefix = 0;
    int maxLength = 0;

    // Prefix sum = 0 được xem như xuất hiện trước mảng, tại vị trí -1
    viTriDau[0] = -1;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        prefix += x;

        if (viTriDau.find(prefix) != viTriDau.end()) {
            int doDai = i - viTriDau[prefix];
            maxLength = max(maxLength, doDai);
        }
        else {
            viTriDau[prefix] = i;
        }
    }

    cout << maxLength;

    return 0;
}