//C6 — P2 — Chia đôi hàng đợi công việc
#include <iostream>
using namespace std;

class Playlist {
private:
    struct Node {
        int id;
        Node* next;
    };

    typedef Node* node;

    node head;
    node tail;
    int size;

    node taoNode(int newid) {
        node tmp = new Node;
        tmp->id = newid;
        tmp->next = NULL;
        return tmp;
    }

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void pushFront(int newid) {
        node tmp = taoNode(newid);

        if (head == NULL) {
            head = tail = tmp;
        } else {
            tmp->next = head;
            head = tmp;
        }

        size++;
    }

    void pushBack(int newid) {
        node tmp = taoNode(newid);

        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    void popFront() {
        if (head == NULL) {
            return;
        }

        node tmp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }

        delete tmp;
        size--;
    }

    bool deleteValue(int x) {
        if (head == NULL) {
            return false;
        }

        if (head->id == x) {
            popFront();
            return true;
        }

        node prev = head;

        while (prev->next != NULL) {
            node tmp = prev->next;

            if (tmp->id == x) {
                prev->next = tmp->next;

                if (tmp == tail) {
                    tail = prev;
                }

                delete tmp;
                size--;
                return true;
            }

            prev = prev->next;
        }

        return false;
    }

    int getSize() {
        return size;
    }

    void inDslk() {
        node tmp = head;

        while (tmp != NULL) {
            cout << tmp->id << " ";
            tmp = tmp->next;
        }

        cout << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Playlist playlist;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int newid;
        cin >> newid;
        playlist.pushBack(newid);
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        if (s == "PUSH_FRONT") {
            int newid;
            cin >> newid;
            playlist.pushFront(newid);
        } 
        else if (s == "PUSH_BACK") {
            int newid;
            cin >> newid;
            playlist.pushBack(newid);
        } 
        else if (s == "POP_FRONT") {
            playlist.popFront();
        } 
        else if (s == "DELETE_VALUE") {
            int newid;
            cin >> newid;
            playlist.deleteValue(newid);
        }
    }

    cout << playlist.getSize() << "\n";

    if (playlist.getSize() > 0) {
        playlist.inDslk();
    }
}