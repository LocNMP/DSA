//C4 — P1 — Quản lý tồn kho hàng hóa
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class InventoryTracker {
private:
	unordered_map<string, long long> inventory;
	long long total = 0;

public:
	void add(string id, long long qty) {
		inventory[id] += qty;
		total += qty;
	}

	void remove(string id, long long qty) {
		auto it = inventory.find(id);
		if (it == inventory.end()) {
			return;
		}
		long long current = it->second;
		if (current <= qty) {
			total -= current;
			it->second = 0;
		}
		else {
			it->second -= qty;
			total -= qty;
		}
	}

	long long count(string id) {
		auto it = inventory.find(id);

		if (it == inventory.end()) {
			return 0;
		}

		return it->second;
	}

	long long getTotal() {
		return total;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Q;
	cin >> Q;
	InventoryTracker tracker;
	while (Q--) {
		string command;
		cin >> command;
		if (command == "ADD") {
			string id;
			long long qty;
			cin >> id >> qty;
			tracker.add(id, qty);
		}
		else if (command == "REMOVE") {
			string id;
			long long qty;
			cin >> id >> qty;
			tracker.remove(id, qty);
		}
		else if (command == "COUNT") {
			string id;
			cin >> id;
			cout << tracker.count(id) << '\n';
		}
		else if (command == "TOTAL") {
			cout << tracker.getTotal() << '\n';
		}
	}
	return 0;
}