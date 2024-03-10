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
    int size = 0;
    void addTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
        size++;
    }
    void Print () {
        for (node p = pHead->next; p != nullptr; p = p->next) {
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
    LinkedList l;
    int n, cnt = 0;
    while (cin >> n) {
        if (n % 2 == 0) cnt++;
        l.addTail (make_node (n));
    }
    if (l.size == 0) cout << "NO" << endl;
    else cout << l.size << endl;
    if (l.size < 2) cout << "NO" << endl;
    else l.Print ();
    if (cnt <= 1) cout << "NO";
    else cout << cnt;
    return 0;
}