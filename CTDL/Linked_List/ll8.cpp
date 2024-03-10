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
    void DeleteHead () {
        if (pHead == nullptr) return;
        else {
            node p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
    void DeleteTail () {
        if (pHead == nullptr) return;
        else if (pHead->next == nullptr) DeleteHead ();
        else {
            node p = pHead;
            while (p->next != pTail) p = p->next;
            delete pTail;
            pTail = p;
            pTail->next = nullptr;
        }
    }
    void Delete_for_request (LinkedList &l, int k) {
        if (pHead == nullptr) return;
        else {
            node request = pHead;
            while (k) {
                request = request->next;
                k--;
            }
            int value = request->data;
            node p = pHead;
            while (p != nullptr) {
                if (p->data <= value) l.addTail (make_node (p->data));
                p = p->next;
            }
        }
    }
};

int main () {
    LinkedList l1, l2;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l1.addTail (make_node (x));
    }
    int k; cin >> k;
    l1.Delete_for_request (l2, k);
    l2.PrintList ();
    l1.DeleteList ();
    l2.DeleteList ();
    return 0;
}