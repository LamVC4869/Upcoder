#include <iostream>
#include <fstream>
#include <cmath>

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
    ~LinkedList () {
        node p = nullptr;
        while (pHead != nullptr) {
            p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
};

struct Pair {
    int x, y;
    Pair () {}
    Pair (int x, int y) {
        if (x > y) swap (x, y);
        this->x = x;
        this->y = y;
    }
    ~Pair () {}
    friend ostream& operator << (ostream &os, Pair p) {
        os << '(' << p.x << ", " << p.y << ')';
        return os;
    }
};

int main () {
    freopen ("CONTRO.inp", "r", stdin);
    freopen ("CONTRO.out", "w", stdout);
    LinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l.AddTail (make_node (x));
    }
    Pair point[1000];
    int PairSize = 0;
    node p = l.pHead;
    int min = abs (p->data - p->next->data);
    while (p->next != nullptr) {
        node p1 = p->next;
        while (p1 != nullptr) {
            int total = p->data - p1->data;
            if (abs (total) < min) min = abs (total);
            p1 = p1->next;
        }
        p = p->next;
    }
    p = l.pHead;
    while (p->next != nullptr) {
        node p1 = p->next;
        while (p1 != nullptr) {
            int total = p->data - p1->data;
            if (abs (total) == min) {
                point[PairSize++] = Pair (p->data, p1->data);
            }
            p1 = p1->next;
        }
        p = p->next;
    }
    cout << PairSize << ' ' << min << endl;
    for (int i = 0; i < PairSize; i++) {
        cout << point[i] << ' ';
    }
    return 0;
}