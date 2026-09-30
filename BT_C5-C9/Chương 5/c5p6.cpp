#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long N, K;
	cin >> N >> K;

	long long capacity = 1;
	long long size = 0;
	long long copyDoubling = 0;

	for (long long i = 0; i < N; i++) {

		if (size == capacity) {
			copyDoubling += size;
			capacity *= 2;
		}

		size++;
	}
	
	capacity = 1;
	size = 0;
	long long copyAdditive = 0;

	for (long long i = 0; i < N; i++) {

		if (size == capacity) {
			copyAdditive += size;
			capacity += K;
		}

		size++;
	}

	cout << copyDoubling << endl;
	cout << copyAdditive << endl;

	if (copyDoubling < copyAdditive) {
		cout << "DOUBLING";
	}
	else if (copyAdditive < copyDoubling) {
		cout << "ADDITIVE";
	}
	else {
		cout << "TIE";
	}

	return 0;
}