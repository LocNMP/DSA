//C8 — P5 — Mô phỏng Bảng băm Dò tuyến tính với Tombstone
#include <iostream>
#include <string>
using namespace std;

const int EMPTY = 0;
const int OCCUPIED = 1;
const int TOMBSTONE = 2;

struct Slot {
    long long key;
    long long value;
    int state;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, Q;
    cin >> M >> Q;

    Slot table[1000];

    for (int i = 0; i < M; i++) {
        table[i].state = EMPTY;
    }

    while (Q--) {
        string command;
        cin >> command;

        if (command == "PUT") {
            long long K, V;
            cin >> K >> V;

            int hash = K % M;
            int firstAvailable = -1;
            bool updated = false;

            for (int c = 0; c < M; c++) {
                int index = (hash + c) % M;

                // Key đã tồn tại -> cập nhật
                if (table[index].state == OCCUPIED &&
                    table[index].key == K) {

                    table[index].value = V;
                    updated = true;
                    break;
                }

                // Ghi nhớ TOMBSTONE đầu tiên
                if (table[index].state == TOMBSTONE &&
                    firstAvailable == -1) {

                    firstAvailable = index;
                }

                // Gặp EMPTY -> chắc chắn key không còn nằm phía sau
                if (table[index].state == EMPTY) {
                    if (firstAvailable == -1) {
                        firstAvailable = index;
                    }

                    break;
                }
            }

            if (updated) {
                continue;
            }

            if (firstAvailable != -1) {
                table[firstAvailable].key = K;
                table[firstAvailable].value = V;
                table[firstAvailable].state = OCCUPIED;
            }
            else {
                cout << "FULL\n";
            }
        }

        else if (command == "GET") {
            long long K;
            cin >> K;

            int hash = K % M;
            bool found = false;

            for (int c = 0; c < M; c++) {
                int index = (hash + c) % M;

                if (table[index].state == EMPTY) {
                    break;
                }

                if (table[index].state == OCCUPIED &&
                    table[index].key == K) {

                    cout << table[index].value << "\n";
                    found = true;
                    break;
                }

                // Nếu là TOMBSTONE thì tiếp tục dò
            }

            if (!found) {
                cout << "NOT_FOUND\n";
            }
        }

        else if (command == "DEL") {
            long long K;
            cin >> K;

            int hash = K % M;
            bool found = false;

            for (int c = 0; c < M; c++) {
                int index = (hash + c) % M;

                if (table[index].state == EMPTY) {
                    break;
                }

                if (table[index].state == OCCUPIED &&
                    table[index].key == K) {

                    table[index].state = TOMBSTONE;

                    cout << "DELETED\n";

                    found = true;
                    break;
                }

                // TOMBSTONE -> tiếp tục dò
            }

            if (!found) {
                cout << "NOT_FOUND\n";
            }
        }
    }

    return 0;
}