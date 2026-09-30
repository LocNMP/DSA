//C6 — P2 — Chia đôi hàng đợi công việc
#include <iostream>
using namespace std;

class JobList {
private:
    struct Node {
        int id;
        Node* next;
    };

    typedef Node* node;

    node head;
    node tail;
    int size;

    node taoNode(int jobId) {
        node tmp = new Node;
        tmp->id = jobId;
        tmp->next = NULL;
        return tmp;
    }

public:
    JobList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void pushBack(int jobId) {
        node tmp = taoNode(jobId);

        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    void splitAndPrint() {
        node slow = head;
        node fast = head;
        node prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << slow->id << "\n";

        node headA = head;
        node headB = slow;

        if (prev != NULL) {
            prev->next = NULL;
        }

        int k1 = size / 2;
        int k2 = size - k1;

        cout << k1;

        node tmp = headA;

        while (tmp != NULL) {
            cout << " " << tmp->id;
            tmp = tmp->next;
        }

        cout << "\n";

        cout << k2;

        tmp = headB;

        while (tmp != NULL) {
            cout << " " << tmp->id;
            tmp = tmp->next;
        }

        cout << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    JobList jobs;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int jobId;
        cin >> jobId;
        jobs.pushBack(jobId);
    }

    jobs.splitAndPrint();

    return 0;
}