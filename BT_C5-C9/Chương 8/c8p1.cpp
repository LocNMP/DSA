#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    // Hash table: mã vé -> đã được quét hay chưa.
    unordered_map<string, bool> tickets;
    tickets.reserve(n);

    for (int i = 0; i < n; ++i) {
        string ticket;
        cin >> ticket;
        tickets[ticket] = false;
    }

    int q;
    cin >> q;

    while (q--) {
        string ticket;
        cin >> ticket;

        auto it = tickets.find(ticket);
        if (it == tickets.end()) {
            cout << "INVALID\n";
        } else if (!it->second) {
            it->second = true;
            cout << "VALID\n";
        } else {
            cout << "DUPLICATE\n";
        }
    }

    return 0;
}
