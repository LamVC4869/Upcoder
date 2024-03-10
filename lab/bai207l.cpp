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
    void addTail (node p) {
        if (pHead == nullptr) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
        size++;
    }
    void Solve () {
        bool duyet[size] = {};
        int cnt = 0, j = 0;
        node p1 = pHead;
        while (p1 != nullptr && p1->next != nullptr && p1->next->next != nullptr) {
            node p2 = p1->next;
            j++;
            if (p2->next != nullptr && p1->data * p2->next->data == p2->data && p2 != nullptr) {
                cnt++;
                duyet[j] = true;
            }
            p1 = p1->next;
        }
        if (cnt == 0) cout << -1;
        else {
            cout << cnt << endl;
            for (int i = 0; i < size; i++) {
                if (duyet[i]) cout << i + 1<< ' ';
            }
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
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l.addTail (make_node(x));
    }
    if (n < 3) {
        cout << -1;
        return 0;
    }
    l.Solve ();
    return 0;
}