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
    node pHead = nullptr;
    node pTail = nullptr;

    void addTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    void PrintList () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
    }
    void DeleteList () {
        node p = nullptr;
        while (pHead != nullptr) {
            p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
    void ChangeData_ofNode (int a, int b) {
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data == a) p->data = b;
        }
    }
};

int main () {
    LinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l.addTail (make_node (x));
    }
    int a, b; cin >> a >> b;
    l.ChangeData_ofNode (a, b);
    l.PrintList ();
    l.DeleteList ();
    return 0;
}