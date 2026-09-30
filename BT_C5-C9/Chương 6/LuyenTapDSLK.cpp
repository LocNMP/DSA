#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* node;

// Tạo node mới
node taoNode(int x) {
    node tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Đếm số lượng node
int demSoLuong(node head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// Thêm đầu
void themDau(node &head, int x) {
    node moi = taoNode(x);

    moi->next = head;
    head = moi;
}

// Thêm cuối
void themCuoi(node &head, int x) {
    node moi = taoNode(x);

    if (head == NULL) {
        head = moi;
        return;
    }

    node p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = moi;
}

// Thêm tại vị trí pos, đánh số từ 1
bool themGiua(node &head, int x, int pos) {
    int n = demSoLuong(head);

    if (pos < 1 || pos > n + 1) {
        return false;
    }

    if (pos == 1) {
        themDau(head, x);
        return true;
    }

    node p = head;

    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    node moi = taoNode(x);

    moi->next = p->next;
    p->next = moi;

    return true;
}

// Xóa đầu
void xoaDau(node &head) {
    if (head == NULL) return;

    node tmp = head;

    head = head->next;

    delete tmp;
}

// Xóa cuối
void xoaCuoi(node &head) {
    if (head == NULL) return;

    // Chỉ có 1 node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node p = head;

    // Tìm node đứng trước node cuối
    while (p->next->next != NULL) {
        p = p->next;
    }

    delete p->next;
    p->next = NULL;
}

// Xóa tại vị trí pos
bool xoaGiua(node &head, int pos) {
    if (head == NULL || pos < 1) {
        return false;
    }

    if (pos == 1) {
        xoaDau(head);
        return true;
    }

    node pre = head;

    for (int i = 1; i < pos - 1 && pre->next != NULL; i++) {
        pre = pre->next;
    }

    // pos vượt quá số lượng node
    if (pre->next == NULL) {
        return false;
    }

    node tmp = pre->next;

    pre->next = tmp->next;

    delete tmp;

    return true;
}

// Xóa tất cả node có data = x
int xoaData(node &head, int x) {
    int count = 0;

    // Xóa các node đầu có data = x
    while (head != NULL && head->data == x) {
        xoaDau(head);
        count++;
    }

    if (head == NULL) {
        return count;
    }

    node p = head;

    while (p->next != NULL) {
        if (p->next->data == x) {
            node tmp = p->next;

            p->next = tmp->next;

            delete tmp;

            count++;
        }
        else {
            p = p->next;
        }
    }

    return count;
}

// In danh sách
void inDslk(node head) {
    if (head == NULL) {
        cout << "Danh sach rong.\n";
        return;
    }

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << "\n";
}

// Giải phóng toàn bộ danh sách
void giaiPhong(node &head) {
    while (head != NULL) {
        xoaDau(head);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node head = NULL;
    int chon;

    while (true) {

        cout << "\n========== MENU ==========\n";
        cout << "1. Them vao dau danh sach\n";
        cout << "2. Them vao cuoi danh sach\n";
        cout << "3. Them vao vi tri bat ky\n";
        cout << "4. Xoa phan tu dau danh sach\n";
        cout << "5. Xoa phan tu cuoi danh sach\n";
        cout << "6. Xoa phan tu tai vi tri bat ky\n";
        cout << "7. Xoa tat ca phan tu co gia tri x\n";
        cout << "8. In danh sach lien ket\n";
        cout << "9. Dem so luong phan tu\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";

        cin >> chon;

        if (chon == 1) {

            int x;

            cout << "Nhap gia tri can them: ";
            cin >> x;

            themDau(head, x);

            cout << "Da them " << x << " vao dau danh sach.\n";
        }

        else if (chon == 2) {

            int x;

            cout << "Nhap gia tri can them: ";
            cin >> x;

            themCuoi(head, x);

            cout << "Da them " << x << " vao cuoi danh sach.\n";
        }

        else if (chon == 3) {

            int x, pos;

            cout << "Nhap gia tri can them: ";
            cin >> x;

            cout << "Nhap vi tri can them: ";
            cin >> pos;

            if (themGiua(head, x, pos)) {
                cout << "Da them " << x
                     << " vao vi tri " << pos << ".\n";
            }
            else {
                cout << "Vi tri khong hop le.\n";
            }
        }

        else if (chon == 4) {

            if (head == NULL) {
                cout << "Danh sach rong.\n";
            }
            else {
                xoaDau(head);

                cout << "Da xoa phan tu dau danh sach.\n";
            }
        }

        else if (chon == 5) {

            if (head == NULL) {
                cout << "Danh sach rong.\n";
            }
            else {
                xoaCuoi(head);

                cout << "Da xoa phan tu cuoi danh sach.\n";
            }
        }

        else if (chon == 6) {

            int pos;

            cout << "Nhap vi tri can xoa: ";
            cin >> pos;

            if (xoaGiua(head, pos)) {
                cout << "Da xoa phan tu tai vi tri "
                     << pos << ".\n";
            }
            else {
                cout << "Vi tri khong hop le.\n";
            }
        }

        else if (chon == 7) {

            int x;

            cout << "Nhap gia tri can xoa: ";
            cin >> x;

            int soLuongXoa = xoaData(head, x);

            if (soLuongXoa == 0) {
                cout << "Khong tim thay gia tri "
                     << x << " trong danh sach.\n";
            }
            else {
                cout << "Da xoa "
                     << soLuongXoa
                     << " node co gia tri "
                     << x << ".\n";
            }
        }

        else if (chon == 8) {

            cout << "Danh sach hien tai: ";
            inDslk(head);
        }

        else if (chon == 9) {

            cout << "So luong node: "
                 << demSoLuong(head)
                 << "\n";
        }

        else if (chon == 0) {

            cout << "Thoat chuong trinh.\n";

            break;
        }

        else {
            cout << "Lua chon khong hop le.\n";
        }
    }

    giaiPhong(head);

    return 0;
}