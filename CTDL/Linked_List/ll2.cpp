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
    int size = 0;
    LinkedList () : pHead(nullptr), pTail(nullptr) {}
    void AddHead (node p) {
        if (pHead == nullptr) {
            pHead = pTail = p;
        } else {
            p->next = pHead;
            pHead = p;
        }
        size++;
    }
    void AddTail (node p) {
        if (pHead == nullptr) {
            pHead = pTail = p;
        } else {
            pTail->next = p;
            pTail = p;
        }
        size++;
    }
    void Add_node_randomPos (node p, int pos) {
        if (pos == 1 || size == 0) AddHead (p);
        else if (pos == size + 1) AddTail (p);
        else {
            node k = pHead;
            for (int i = 1; i < pos - 1; i++) k = k->next;
            p->next = k->next;
            k->next = p;
            size++;
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
};

int main () {
    LinkedList list;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        list.AddTail (make_node (x));
    }
    int k, x; cin >> k >> x;
    list.Add_node_randomPos (make_node (x), k + 1);
    list.PrintList ();
    list.DeleteList ();
    return 0;
}