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

struct LinkedList {
    node pHead;
    node pTail;
    LinkedList () : pHead(nullptr), pTail(nullptr) {}
};

typedef struct LinkedList list;

void addHead (list &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void addTail (list &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void PrintList (list l) {
    cout << "\nDanh sach lien ket: ";
    for (node p = l.pHead; p != nullptr; p = p->next) {
        cout << p->data << ' ';
    }
}

void giaiPhongDSLK (list &l) {
    node p = nullptr;
    while (l.pHead != nullptr) {
        p = l.pHead;
        l.pHead = l.pHead->next;
        delete p;
    }
    cout << "\nDa giai phong danh sach lien ket";
}

void Menu (list &l) {
    int option;
    while (true) {
        cout << "\n===================== Menu =====================";
        cout << "\n1. Them node vao cuoi danh sach lien ket.";
        cout << "\n2. Them node vao dau danh sach lien ket.";
        cout << "\n3. In ra danh sach lien ket.";
        cout << "\n0. Exit.";
        cout << "\n===================== End =====================";
        cout << "\nNhap lua chon: ";
        cin >> option;
        if (option == 1) {
            int x;
            cout << "\nNhap gia tri: ";
            cin >> x;
            node p = make_node (x);
            addTail (l, p);
        } else if (option == 2) {
            int x;
            cout << "\nNhap gia tri: ";
            cin >> x;
            node p = make_node (x);
            addHead (l, p);
        } else if (option == 3) {
            PrintList (l);
            break;
        } else break;
    }
}

int main () {
    list l;
    Menu (l);
    giaiPhongDSLK (l);
    return 0;
}