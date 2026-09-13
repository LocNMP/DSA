//C4 — P3 — Danh sách sản phẩm xem gần đây
#include <iostream>
#include <vector>
using namespace std;

class  RecentList {
private:
	vector<int> products;
	int K;
public:
	RecentList(int k) {
		K = k;
	}
	void view(int id) {
		int pos = -1;
		for (int i = 0; i < products.size(); i++) {
			if (products[i] == id) {
				pos = i;
				break;
			}
		}
		if (pos != -1) {
			products.erase(products.begin() + pos);
		}
		products.insert(products.begin(), id);
		if (products.size() > K) {
			products.pop_back();
		}
	}
	void get(int idx) {
		if (idx < 0 || idx >= products.size()) {
			cout << "INVALID\n";
			return;
		}

		cout << products[idx] << endl;;
	}
	void size() {
		cout << products.size() << endl;
	}
	void clear() {
		products.clear();
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int K, Q;
	cin >> K >> Q;

	RecentList list(K);

	while (Q--) {
		string command;
		cin >> command;

		if (command == "VIEW") {
			int id;
			cin >> id;

			list.view(id);
		}
		else if (command == "GET") {
			int idx;
			cin >> idx;

			list.get(idx);
		}
		else if (command == "SIZE") {
			list.size();
		}
		else if (command == "CLEAR") {
			list.clear();
		}
	}

	return 0;
}