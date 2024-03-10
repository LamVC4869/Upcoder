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
    void AddHead (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            p->next = pHead;
            pHead = p;
        }
    }
    void PrintList () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data;
            if (p->next != nullptr) cout << ' ';
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
    int element;
    while (cin >> element) l.AddHead (make_node (element));
    l.PrintList ();
    return 0;
}