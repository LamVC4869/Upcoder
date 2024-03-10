#include <iostream>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct Node {
    char data;
    Node* next;
};

typedef struct Node* node;

node make_node (char x) {
    node p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

struct LinkedList {
    node pHead = nullptr;
    node pTail = nullptr;
    void AddHead (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            p->next = pHead;
            pHead = p;
        }
    }
    void AddTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    bool found (char x) {
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data == x) return true;
        }
        return false;
    }
    void addNode (node p) {
        if (pHead == nullptr || p->data < pHead->data) AddHead (p);
        else {
            node prev = nullptr;
            node cur = pHead;
            while (cur != nullptr && p->data > cur->data) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = p;
            p->next = cur;
        }
    }
    void PushNode () {
        for (char c : alphabet) if (!found (c)) addNode (make_node (c));
    }
    void print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data;
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
    char c;
    while (cin >> c) l.AddTail (make_node (c));
    l.print ();
    cout << endl;
    l.PushNode ();
    l.print ();
    return 0;
}