//C6 — P3 — Kiểm tra vòng lặp chuyển hướng Web
#include <iostream>
using namespace std;

class RedirectList {
private:
    struct Node {
        long long id;
        Node* next;
    };

    typedef Node* node;

    node head;
    node tail;
    int size;

    node taoNode(long long id) {
        node tmp = new Node;
        tmp->id = id;
        tmp->next = NULL;
        return tmp;
    }

public:
    RedirectList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void pushBack(long long id) {
        node tmp = taoNode(id);

        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    void taoCycle(int pos) {
        if (pos == -1) {
            return;
        }

        node tmp = head;

        for (int i = 0; i < pos; i++) {
            tmp = tmp->next;
        }

        tail->next = tmp;
    }

    void kiemTraCycle() {
        node slow = head;
        node fast = head;

        bool coCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                coCycle = true;
                break;
            }
        }

        if (!coCycle) {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";

        int cycleLength = 1;

        node tmp = slow->next;

        while (tmp != slow) {
            cycleLength++;
            tmp = tmp->next;
        }

        node p1 = head;
        node p2 = slow;

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        cout << cycleLength << " " << p1->id << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    RedirectList danhSach;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long id;
        cin >> id;
        danhSach.pushBack(id);
    }

    int pos;
    cin >> pos;

    danhSach.taoCycle(pos);
    danhSach.kiemTraCycle();

    return 0;
}