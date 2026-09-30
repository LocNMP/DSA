//C9 — P6 — Phân tích điểm hòa vốn chiến lược tra cứu kho hàng
#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    long long a[2005];
    long long b[2005];
    long long truyVan[2005];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> truyVan[i];
    }

    // =========================
    // CHIẾN LƯỢC A
    // =========================

    long long chiPhiA = 0;

    for (int k = 0; k < q; k++) {
        long long target = truyVan[k];

        for (int i = 0; i < n; i++) {
            chiPhiA++;

            if (a[i] == target) {
                break;
            }
        }
    }

    // =========================
    // CHIẾN LƯỢC B
    // =========================

    long long chiPhiSort = 0;

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        long long key = b[i];
        int j = i - 1;

        while (j >= 0 && b[j] > key) {
            chiPhiSort++;

            b[j + 1] = b[j];
            j--;
        }

        // Nếu dừng do b[j] <= key
        // thì phép so sánh thất bại này cũng được tính
        if (j >= 0) {
            chiPhiSort++;
        }

        b[j + 1] = key;
    }

    long long chiPhiTimKiemB = 0;

    for (int k = 0; k < q; k++) {
        long long target = truyVan[k];

        for (int i = 0; i < n; i++) {
            chiPhiTimKiemB++;

            if (b[i] == target) {
                break;
            }

            if (b[i] > target) {
                break;
            }
        }
    }

    long long chiPhiB = chiPhiSort + chiPhiTimKiemB;

    cout << chiPhiA << "\n";
    cout << chiPhiB << "\n";

    if (chiPhiA < chiPhiB) {
        cout << "STRATEGY A";
    }
    else {
        cout << "STRATEGY B";
    }

    return 0;
}