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
    bool tonTai (char x) {
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data == x) return true;
        }
        return false;
    }
    void Push (node x) {
        if (pHead == nullptr || x->data < pHead->data) {
            AddHead (x);
            return;
        }
        node prev = nullptr;
        node current = pHead;
        while (current != nullptr && x->data > current->data) {
            prev = current;
            current = current->next;
        }
        prev->next = x;
        x->next = current;
    }
    void BoSung () {
        for (char c : alphabet) {
            if (!tonTai (c)) Push (make_node (c));
        }
    }
    void Print () {
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
    int n; cin >> n;
    LinkedList l;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        l.AddTail (make_node (c));
    }
    l.Print ();
    l.BoSung ();
    l.Print ();
    return 0;
}