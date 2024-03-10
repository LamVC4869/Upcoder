#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;

node make_node (int x) {
    node p = new Node;
    p ->data = x;
    p->next = nullptr;
    return p;
}

struct LinkedList {
    node Head;
    node Tail;
    LinkedList () : Head (nullptr), Tail (nullptr) {}
    void AddHead (node p) {
        if (this->Head == nullptr) {
            this->Head = this->Tail = p;
        } else {
            p->next = this->Head;
            this->Head = p;
        }
    }
    void AddTail (node p) {
        if (this->Head == nullptr) {
            this->Head = this->Tail = p;
        } else {
            this->Tail->next = p;
            this->Tail = p;
        }
    }
    void Delete () {
        node p = nullptr;
        while (this->Head != nullptr) {
            p = this->Head;
            this->Head = this->Head->next;
            delete p;
        }
    }
    int getSize () {
        int cnt = 0;
        for (node p = this->Head; p != nullptr; p = p->next)cnt++;
        return cnt;
    }
    void Add_new_node (node a, int k) {
        if (this->Head == nullptr || k == 1) AddHead (a);
        else if (k == getSize () + 1) AddTail (a);
        else {
            node p = this->Head;
            for (int i = 1; i < k - 1; i++) p = p->next;
            a->next = p->next;
            p->next = a;
        }
    }
    void PrintList () {
        for (node p = this->Head; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
    }
};

int main () {
    LinkedList l;
    int n, a, k; cin >> n >> a >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l.AddTail (make_node (x));
    }
    l.Add_new_node (make_node (a), k);
    cout << l.getSize () << endl;
    l.PrintList ();
    l.Delete ();
    return 0;
}