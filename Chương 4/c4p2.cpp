//C4 — P2 — Túi vật phẩm ngẫu nhiên
#include <iostream>
#include <vector>
using namespace std;

class RewardBag {
private:
	vector<string> items;

public:
	void add(string name) {
		items.push_back(name);
	}
	void getAny() {
		if (items.empty()) {
			cout << "EMPTY" << endl;
			return;
		}
		cout << items.back() << endl;
	}
	void takeAny() {
		if (items.empty()) {
			cout << "EMPTY" << endl;
			return;
		}
		cout << items.back() << endl;
		items.pop_back();
	}
	int size() {
		return items.size();
	}
	bool contains(string name) {
		for (auto x : items) {
			if (x == name) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Q;
	cin >> Q;
	RewardBag bag;
	while (Q--) {
		string command;
		cin >> command;
		if (command == "ADD") {
			string name;
			cin >> name;
			bag.add(name);
		}
		else if (command == "GET_ANY") {
			bag.getAny();
		}
		else if (command == "TAKE_ANY") {
			bag.takeAny();
		}
		else if (command == "SIZE") {
			cout << bag.size() << endl;
		}
		else if (command == "CONTAINS") {
			string name;
			cin >> name;
			if (bag.contains(name)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}