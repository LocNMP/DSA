#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Định nghĩa kiểu 'node' đại diện cho con trỏ 'Node*'
typedef Node* node;

// Tạo một node mới
node taoNode(int x) {
    node tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Hàm phụ trợ: đếm số node hiện có để kiểm tra tính hợp lệ của pos
int demSoLuong(node head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Thêm vào đầu danh sách (dùng 'node &head' để tham chiếu con trỏ)
void themDau(node &head, int x) {
    node moi = taoNode(x);
    moi->next = head;
    head = moi;
}

void themCuoi(node &head, int x) {
    node moi = taoNode(x);

    // TH1: Danh sách đang rỗng
    if (head == NULL) {
        head = moi;
        return;
    }

    // TH2: Duyệt tìm node cuối cùng
    node tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next; // Bắt buộc phải có bước nhảy này
    }

    // Nối node mới vào sau node cuối
    tmp->next = moi;
}

// Chèn giá trị x vào vị trí pos (đánh số từ 1)
void themGiua(node &head, int x, int pos) {
    int n = demSoLuong(head);

    // Kiểm tra vị trí hợp lệ
    if (pos < 1 || pos > n + 1) {
        cout << "Vi tri " << pos << " khong hop le! (Danh sach hien co " << n << " phan tu)\n";
        return;
    }

    // Nếu chèn vào vị trí 1 -> Thêm vào đầu
    if (pos == 1) {
        themDau(head, x);
        return;
    }

    // Tìm node ở vị trí pos - 1
    node p = head;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    // Tạo node mới và nối liên kết
    node moi = taoNode(x);
    moi->next = p->next;
    p->next = moi;
}

void xoaDau(node &head){
    if (head == NULL) return;
    node tmp = head;
    head = head->next;
    delete tmp;
}

void xoaCuoi(node &head){
    if(head == NULL) return;
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node tmp = head;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = NULL;
}

void xoaGiua(node &head, int pos){
    if (head == NULL || pos < 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    if(pos == 1){
        xoaDau(head);
        return;
    }
    node pre = head;
    for(int i = 1; i < pos - 1 && pre->next != NULL; i++){
        pre = pre->next;
    }
    if(pre->next == NULL) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    node tmp = pre->next;
    pre->next = tmp->next;
    delete tmp;
}

// In các phần tử trong danh sách
void inDslk(node head) {
    if (head == NULL) {
        cout << "(Danh sach rong)";
    }
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Giải phóng bộ nhớ
void giaiPhong(node &head) {
    while (head != NULL) {
        node tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    // Nếu muốn đọc/ghi bằng file, bỏ comment 2 dòng dưới:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    node head = NULL;
    int chon;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Them vao dau danh sach\n";
        cout << "2. Them vao cuoi danh sach\n";
        cout << "3. Them vao giua danh sach\n";
        cout << "4. Xoa phan tu dau danh sach\n";
        cout << "5. Xoa phan tu cuoi danh sach\n";
        cout << "6. Xoa phan tu giua danh sach\n";
        cout << "7. In danh sach lien ket\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Lua chon cua ban: ";
        cin >> chon;

        if (chon == 1) {
            int x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            themDau(head, x);
            cout << "-> Da them " << x << " vao danh sach.\n";
        } 

        else if(chon == 2){
            int x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            themCuoi(head, x);
            cout << "-> Da them " << x << " vao danh sach.\n";
        }

        else if(chon == 3){
            cout << "Nhap gia tri can them: ";
            int x; cin >> x;
            cout << "Nhap vi tri can them: ";
            int i; cin >> i;
            themGiua(head, x, i);
            cout << "-> Da them " << x << " vao danh sach.\n";

        }

        else if(chon == 4){
            if(head == NULL){
                cout << "Danh sach rong\n";
            }
            else{
                xoaDau(head);
                cout << "Da xoa khoi danh sach.\n";
            }
        }

        else if(chon == 5){
            if(head == NULL){
                cout << "Danh sach rong\n";
            }
            else{
                xoaCuoi(head);
                cout << "Da xoa khoi danh sach.\n";

            }
        }

        else if(chon == 6){
            cout << "Nhap vi tri can xoa: ";
            int pos; cin >> pos;
            if(head == NULL){
                cout << "Danh sach rong\n";
            }
            else{
                xoaGiua(head, pos);
                cout << "Da xoa khoi danh sach.\n";
            }
        }

        else if (chon == 7) {
            cout << "Danh sach lien ket hien tai: ";
            inDslk(head);
        } 

        else if (chon == 0) {
            cout << "Tam biet!\n";
            break;
        } 

        else {
            cout << "Lua chon khong hop le, vui long chon lai!\n";
        }
    }

    giaiPhong(head);
    return 0;
}