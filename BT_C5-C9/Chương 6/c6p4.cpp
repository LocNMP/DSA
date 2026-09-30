//C6 — P4 — Bộ nhớ đệm thẻ trình duyệt
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class LRUCache {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    typedef Node* node;

    node head;
    node tail;

    int size;
    int capacity;

    unordered_map<int, node> mp;

    node taoNode(int x) {
        node tmp = new Node;

        tmp->data = x;
        tmp->prev = NULL;
        tmp->next = NULL;

        return tmp;
    }

    // Tháo node p ra khỏi danh sách
    // Không delete vì có thể còn dùng lại node p
    void unlink(node p) {
        if (p->prev != NULL) {
            p->prev->next = p->next;
        }
        else {
            head = p->next;
        }

        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        else {
            tail = p->prev;
        }

        p->prev = NULL;
        p->next = NULL;
    }

    // Đưa node p vào đầu danh sách
    void addFront(node p) {
        p->prev = NULL;
        p->next = head;

        if (head != NULL) {
            head->prev = p;
        }
        else {
            tail = p;
        }

        head = p;
    }

    // Xóa node cuối cùng - LRU
    void removeBack() {
        if (tail == NULL) {
            return;
        }

        node tmp = tail;

        // Xóa khỏi map trước
        mp.erase(tmp->data);

        // Tháo khỏi danh sách
        unlink(tmp);

        delete tmp;
        size--;
    }

public:
    LRUCache(int c) {
        head = NULL;
        tail = NULL;
        size = 0;
        capacity = c;
    }

    void access(int x) {
        auto it = mp.find(x);

        // Trường hợp tab đã tồn tại
        if (it != mp.end()) {
            node p = it->second;

            // Nếu đã ở đầu thì không cần di chuyển
            if (p != head) {
                unlink(p);
                addFront(p);
            }

            return;
        }

        // Tab chưa tồn tại và cache đã đầy
        if (size == capacity) {
            removeBack();
        }

        // Tạo tab mới
        node tmp = taoNode(x);

        // Đưa tab mới lên đầu
        addFront(tmp);

        // Lưu địa chỉ node vào map
        mp[x] = tmp;

        size++;
    }

    void closeTab(int x) {
        auto it = mp.find(x);

        // Không tìm thấy tab
        if (it == mp.end()) {
            return;
        }

        node p = it->second;

        // Xóa khỏi danh sách
        unlink(p);

        // Xóa khỏi map
        mp.erase(x);

        // Giải phóng bộ nhớ
        delete p;

        size--;
    }

    int getSize() {
        return size;
    }

    void print() {
        node tmp = head;

        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }

        cout << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int C, Q;
    cin >> C >> Q;

    LRUCache cache(C);

    while (Q--) {
        string command;
        int x;

        cin >> command >> x;

        if (command == "ACCESS") {
            cache.access(x);
        }
        else if (command == "CLOSE") {
            cache.closeTab(x);
        }
    }

    cout << cache.getSize() << "\n";

    if (cache.getSize() > 0) {
        cache.print();
    }

    return 0;
}