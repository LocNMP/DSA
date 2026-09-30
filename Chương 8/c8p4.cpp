//C8 — P4 — Phân nhóm dấu hiệu di truyền
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    unordered_map<string, int> viTriNhom;
    vector<vector<string>> cacNhom;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string key = s;
        sort(key.begin(), key.end());

        if (viTriNhom.find(key) == viTriNhom.end()) {
            viTriNhom[key] = cacNhom.size();
            cacNhom.push_back({s});
        }
        else {
            int index = viTriNhom[key];
            cacNhom[index].push_back(s);
        }
    }

    for (auto& nhom : cacNhom) {
        for (int i = 0; i < nhom.size(); i++) {
            if (i > 0) {
                cout << " ";
            }

            cout << nhom[i];
        }

        cout << "\n";
    }

    return 0;
}