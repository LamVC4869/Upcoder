#include <iostream>
#include <cmath>

using namespace std;

bool scp (int n) {
    return int (sqrt (n)) == sqrt (n);
}

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
    void AddTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    int tongSCP () {
        int sum = 0;
        for (node p = pHead; p != nullptr; p = p->next) {
            if (scp (p->data)) sum += p->data;
        }
        return sum;
    }
    void DeleteHead () {
        if (pHead == nullptr) return;
        else {
            node p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
    void deleteSCP () {
        node p = pHead;
        node prev = nullptr;
        while (p != nullptr) {
            if (scp (p->data)) {
                if (p == pHead) DeleteHead ();
                else {
                    node tmp = p;
                    prev->next = tmp->next;
                    p = p->next;
                    delete tmp;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
    }
    void print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data << ' ';
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
    LinkedList list;
    int n; cin >> n;
    while (cin >> n) list.AddTail (make_node (n));
    cout << list.tongSCP () << endl;
    list.deleteSCP ();
    list.print ();
    return 0;
}