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
    p->next = NULL;
    return p;
}

struct LinkedList {
    node pHead = NULL;
    node pTail = NULL;
    void addTail (node p) {
        if (pHead == NULL) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    bool found (int digit) {
        node p = pHead;
        while (p != NULL) {
            if (p->data == digit) return true;
            p = p->next;
        }
        return false;
    }
    ~LinkedList () {
        node p = NULL;
        while (pHead != NULL) {
            p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
};

bool KiemTra (LinkedList l) {
    node start = l.pHead;
    while (start != NULL) {
        node end = start->next;
        while (end != NULL) {
            int total = start->data + end->data;
            if (l.found (total)) return true;
            end = end->next;
        }
        start = start->next;
    }
    return false;
}

int main () {
    LinkedList l;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        l.addTail (make_node (x));
    }
    cout << (KiemTra (l) ? "YES" : "NO");
    return 0;
}