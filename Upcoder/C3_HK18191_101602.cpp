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
    void addHead (node p) {
        if (pHead == NULL) pHead = pTail = p;
        else {
            p->next = pHead;
            pHead = p;
        }
    }
    void addTail (node p) {
        if (pHead == NULL) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    bool empty () {
        return pHead == NULL;
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

int main () {
    LinkedList list;
    LinkedList reverseList;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        if (k > 0) list.addTail (make_node (i));
        else if (k < 0) reverseList.addHead (make_node (i));
    }
    if (k > 0) {
        node p = list.pHead;
        while (!list.empty ()) {
            int i = k;
            while (--i) {
                if (p->next == NULL) p = list.pHead;
                p = p->next;
            }
            cout << p->data << ' ';
            
        }
    } else if (k < 0) {
        k *= -1;

    }
    return 0;
}