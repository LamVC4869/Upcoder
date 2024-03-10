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
    LinkedList () : pHead (nullptr), pTail (nullptr) {}
};

void addTail (LinkedList &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->next = p;
        l.pTail = p;
    }
}

int getMax (LinkedList l) {
    int max = l.pHead->data;
    for (node p = l.pHead->next; p != nullptr; p = p->next) if (p->data > max) max = p->data;
    return max;
}

int getMin (LinkedList l) {
    int min = l.pHead->data;
    for (node p = l.pHead->next; p != nullptr; p = p->next) if (p->data < min) min = p->data;
    return min;
}

void DeleteList (LinkedList &l) {
    node p = nullptr;
    while (l.pHead != nullptr) {
        p = l.pHead;
        l.pHead = l.pHead->next;
        delete p;
    }
}

int main () {
    LinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addTail (l, make_node (x));
    }
    cout << getMax (l) << endl;
    int cnt = 1;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        if (p->data == getMax (l)) cout << cnt << ' ';
        cnt++;
    }
    cout << endl << getMin (l) << endl;
    cnt = 1;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        if (p->data == getMin (l)) cout << cnt << ' ';
        cnt++;
    }
    DeleteList (l);
    return 0;
}