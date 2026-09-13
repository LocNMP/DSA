//C4 — P4 — Bảng xếp hạng điểm số Game
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Item {
	string key;
	long long val;
	long long freq;
	long long time;
};

class DataCache {
private:
	vector<Item> data;
	long long time = 0;
	// unordered_map<string, Item> data;

public:
	void put(string key, long long val) {
		time++;
		for (auto& x : data) {
			if (x.key == key) {
				x.val = val;
				x.time = time;
				return;
			}
		}
		Item newData{key, val, 0, time};
		data.push_back(newData);
	}
	void getKey(string key) {
		for (auto& x : data) {
			if (x.key == key) {
				cout << x.val << endl;
				x.freq++;
				return;
			}
		}
		cout << "MISS" << endl;
	}

	void remove(string key) {
		int pos = 0;
		for (auto& x : data) {
			if (x.key == key) {
				data.erase(data.begin() + pos);
				return;
			}
			pos++;
		}
	}

	void getFreq(string key) {
		for (auto& x : data) {
			if (x.key == key) {
				cout << x.freq << endl;
				return;
			}
		}

		cout << 0 << endl;
	}

	void mostFrequent() {
		if (data.empty()) {
			cout << "EMPTY" << endl;
			return;
		}

		int vt = 0;

		for (int i = 0; i < data.size(); i++) {
			if (data[i].freq > data[vt].freq) {
				vt = i;
			}
			else if (data[i].freq == data[vt].freq &&
					 data[i].time > data[vt].time) {
				vt = i;
					 }
		}

		cout << data[vt].key << endl;
	}
	void size() {
		cout << data.size() << endl;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int Q;
	cin >> Q;

	DataCache cache;

	for (int i = 0; i < Q; i++) {
		string command;
		cin >> command;

		if (command == "PUT") {
			string key;
			long long val;
			cin >> key >> val;
			cache.put(key,val);
		}
		else if (command == "REMOVE") {
			string key;
			cin >> key;

			cache.remove(key);
		}
		else if (command == "GET") {
			string key;
			cin >> key;

			cache.getKey(key);
		}
		else if (command == "FREQ") {
			string key; cin >> key;
			cache.getFreq(key);
		}
		else if (command == "MOST_FREQUENT") {
			cache.mostFrequent();
		}
		else if (command == "SIZE") {
			cache.size();
		}
	}
	return 0;
}