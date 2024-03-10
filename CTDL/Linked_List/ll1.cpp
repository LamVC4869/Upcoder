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

void AddTail (LinkedList &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void PrintList (LinkedList l) {
    for (node p = l.pHead; p != nullptr; p = p->next) {
        cout << p->data << ' ';
    }
}

void GiaiPhongDSLK (LinkedList &l) {
    node p = nullptr;
    while (l.pHead != nullptr) {
        p = l.pHead;
        l.pHead = l.pHead->next;
        delete p;
    }
}

int main () {
    LinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        node p = make_node (x);
        AddTail (l, p);
    }
    PrintList (l);
    GiaiPhongDSLK (l);
    return 0;
}