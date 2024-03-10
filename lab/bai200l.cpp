#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;

node make_node (int x) {
    node p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

struct ListLinked {
    node pHead;
    node pTail;
    ListLinked () : pHead (nullptr), pTail (nullptr) {}
};

void GiaiPhongDSLK (ListLinked &l) {
    node k = nullptr;
    while (l.pHead != nullptr) {
        k = l.pHead;
        l.pHead = l.pHead->next;
        delete k;
    }
    cout << "\nDa giai phong danh sach lien ket";
}

void addHead (ListLinked &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void addTail (ListLinked &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void PrintList (ListLinked l) {
    cout << "\nDanh sach lien ket: ";
    node p = l.pHead;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
}

int Max (ListLinked l) {
    if (l.pHead == nullptr) return -1;
    node p = l.pHead->next;
    int max = l.pHead->data;
    while (p != nullptr) {
        if (p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

int Min (ListLinked l) {
    if (l.pHead == nullptr) return -1;
    node p = l.pHead->next;
    int min = l.pHead->data;
    while (p != nullptr) {
        if (min > p->data) min = p->data;
        p = p->next;
    }
    return min;
}

int main () {
    ListLinked l;
    int n;
    cout << "Nhap so luong node: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "\nNhap gia tri: ";
        cin >> x;
        node p = make_node (x);
        addTail (l, p);
    }
    PrintList (l);
    cout << "\nPhan tu lon nhat la: " << Max (l);
    cout << "\nPhan tu nho nhat la: " << Min (l);
    GiaiPhongDSLK (l);
    return 0;
}