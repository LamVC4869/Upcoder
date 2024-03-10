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
    void AddTail (node p) {
        if (pHead == nullptr) {
            pHead = pTail = p;
        } else {
            pTail->next = p;
            pTail = p;
        }
        size++;
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
            size--;
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
            size--;
        }
    }
    void Delete_Node_Random_Pos (int pos) {
        if (pos >= size || pHead == nullptr) return;
        else if (pos == 0) DeleteHead ();
        else if (pos == size - 1) {
            DeleteTail ();
            return;
        }
        else {
            node p = pHead;
            for (int i = 0; i < pos - 2; i++) p = p->next;
            node tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            size--;
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
    int pos; cin >> pos;
    l.Delete_Node_Random_Pos (pos);
    l.PrintList ();
    l.DeleteList ();
    return 0;
}