#include <iostream>

using namespace std;

struct PHONG {
    string id, name;
    double price;
    int soLuongGiuong, tinhTrang;
    friend istream& operator >> (istream &is, PHONG &p) {
        is >> p.id >> p.name;
        is >> p.price >> p.soLuongGiuong >> p.tinhTrang;
        return is;
    }
    friend ostream& operator << (ostream &os, PHONG p) {
        os << "Ma Phong: " << p.id << endl;
        os << "Ten Phong: " << p.name << endl;
        os << "Don Gia: " << p.price << endl;
        os << "So Luong Giuong: " << p.soLuongGiuong << endl;
        os << "Tinh Trang: " << p.tinhTrang;
        return os;
    }
};

struct Node {
    PHONG data;
    Node* next;
};

typedef struct Node* node;

node make_node (PHONG &x) {
    node p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

struct LinkedList {
    node pHead = nullptr;
    node pTail = nullptr;
    void AddTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    int tongSoGiuong () {
        int cnt = 0;
        for (node p = pHead; p != nullptr; p = p->next) cnt += p->data.soLuongGiuong;
        return cnt;
    }
    void sort () {
        for (node p = pHead; p != pTail; p = p->next) {
            for (node pNext = p->next; pNext != nullptr; pNext = pNext->next) {
                if (p->data.price > pNext->data.price) swap (p->data, pNext->data);
            }
        }
    }
    void PrintPhongTrong () {
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data.tinhTrang == 0) cout << p->data << endl;
        }
    }
    void Print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data << endl;
        }
    }
    ~LinkedList () {
        node p = nullptr;
        while (pHead != nullptr) {
            p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
};

int main () {
    int n; cin >> n;
    LinkedList l;
    while (n--) {
        PHONG x; cin >> x;
        l.AddTail (make_node (x));
    }
    l.PrintPhongTrong ();
    cout << l.tongSoGiuong () << endl;
    l.sort ();
    l.Print ();
    return 0;
}