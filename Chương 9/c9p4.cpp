//C9 — P4 — Bảng xếp hạng xét tuyển giữ nguyên thứ tự ưu tiên
#include <iostream>
#include <string>
using namespace std;

struct ThiSinh {
    string ten;
    long long diem;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ThiSinh a[5005];

    for (int i = 0; i < n; i++) {
        cin >> a[i].ten >> a[i].diem;
    }

    for (int i = 1; i < n; i++) {
        ThiSinh key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].diem < key.diem) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i].ten << " " << a[i].diem << "\n";
    }

    return 0;
}