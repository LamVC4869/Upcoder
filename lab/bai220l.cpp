#include <iostream>
#include <fstream>

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
    void Print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
        cout << endl;
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
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    LinkedList l;
    int n, k;
    while (cin >> n) l.addTail (make_node (n));
    cin >> k;
    l.Print ();
    bool GiaTriNhoHonK = false;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        if (p->data < k) {
            cout << p->data << ' ';
            GiaTriNhoHonK = true;
        }
    }
    if (GiaTriNhoHonK) cout << endl;
    else cout << -1 << endl;
    bool GiaTriLonHonBangK = false;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        if (p->data >= k) {
            cout << p->data << ' ';
            GiaTriLonHonBangK = true;
        }
    }
    if (GiaTriLonHonBangK) cout << endl;
    else cout << -1 << endl;
    node p = l.pHead;
    while (p->next != nullptr) p = p->next;
    node x = make_node (k);
    x->next = p->next;
    p->next = x;
    l.pTail = x->next;
    l.Print ();
    return 0;
}