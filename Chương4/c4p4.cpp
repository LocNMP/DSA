//C4 — P4 — Bảng xếp hạng điểm số Game
#include <iostream>
#include <vector>
using namespace std;

struct Data {
	string name;
	long long score;
};

class Leaderboard {
private:
	vector<Data> board;
	int M;
	bool better(const Data& a, const Data& b) {
		if (a.score != b.score) {
			return a.score > b.score;
		}

		return a.name < b.name;
	}

public:
	Leaderboard(int m) {
		M = m;
	}

	void update(string name, long long score) {
		for (auto& x : board) {
			if (x.name == name) {
				x.score = score;

				sort(board.begin(), board.end(),
				[this](const Data& a, const Data& b) {
					return better(a, b);
				});
				return;
			}
		}
		Data newPlayer{name, score};
		if (board.size() < M) {
			board.push_back(newPlayer);

			sort(board.begin(), board.end(),
			[this](const Data& a, const Data& b) {
				return better(a, b);
			});
			return;
		}
		if (better(newPlayer, board.back())) {
			board.back() = newPlayer;

			sort(board.begin(), board.end(),
				 [this](const Data& a, const Data& b) {
					 return better(a, b);
			});
		}
	}
	void getRank(string name) {
		int i = 0;
		for (auto& x : board) {
			if (x.name == name) {
				cout << i + 1 << endl;
				return;
			}
			i++;
		}
		cout << -1 << endl;
	}
	void getTop(int k) {
		if (k < 1 || k > board.size()) {
			cout << "NONE" << endl;
			return;
		}

		cout << board[k - 1].name << " "
			 << board[k - 1].score << endl;
	}
	void size() {
		cout << board.size() << endl;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int M, Q;
	cin >> M >> Q;

	Leaderboard leaderboard(M);

	for (int i = 0; i < Q; i++) {
		string command;
		cin >> command;

		if (command == "UPDATE") {
			string player;
			long long score;

			cin >> player >> score;

			leaderboard.update(player, score);
		}
		else if (command == "GET_RANK") {
			string player;
			cin >> player;

			leaderboard.getRank(player);
		}
		else if (command == "GET_TOP") {
			int k;
			cin >> k;

			leaderboard.getTop(k);
		}
		else if (command == "SIZE") {
			leaderboard.size();
		}
	}

	return 0;
}