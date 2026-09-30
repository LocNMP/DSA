//C8 — P2 — Thống kê từ khóa xu hướng
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    // Tần suất khác nhau -> tần suất lớn hơn đứng trước
    if (a.second != b.second) {
        return a.second > b.second;
    }

    // Tần suất bằng nhau -> từ điển nhỏ hơn đứng trước
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    unordered_map<string, int> tanSuat;

    for (int i = 0; i < N; i++) {
        string hashtag;
        cin >> hashtag;

        tanSuat[hashtag]++;
    }

    vector<pair<string, int>> danhSach;

    for (auto& x : tanSuat) {
        danhSach.push_back({x.first, x.second});
    }

    sort(danhSach.begin(), danhSach.end(), cmp);

    for (int i = 0; i < K; i++) {
        cout << danhSach[i].first << " "
             << danhSach[i].second << "\n";
    }

    return 0;
}