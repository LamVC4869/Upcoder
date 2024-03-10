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
    void AddTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    void Addhead (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            p->next = pHead;
            pHead = p;
        }
    }
    void Print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
    }
    void ChangeToEven () {
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data & 1) p->data += 1;
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
    LinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l.AddTail (make_node (x));
    }
    l.Print ();
    l.ChangeToEven ();
    cout << endl;
    l.Print ();
    cout << endl;
    LinkedList l1;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        l1.Addhead (make_node (p->data));
    }
    l1.Print ();
    return 0;
}