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
    node Phead = nullptr;
    node pTail = nullptr;
    void AddTail (node p) {
        if (Phead == nullptr) Phead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    int node_of_pos (int k) {
        node p = Phead;
        while (k) {
            p = p->next;
            k--;
        }
        return p->data;
    }
    void DeleteList () {
        node p = nullptr;
        while (Phead != nullptr) {
            p = Phead;
            Phead = Phead->next;
            delete p;
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
    int k; cin >> k;
    cout << l.node_of_pos (k);
    l.DeleteList ();
    return 0;
}