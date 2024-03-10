#include <iostream>
#include <cmath>

using namespace std;

struct DonThuc {
    int HeSo, SoMu;
    friend istream& operator >> (istream &is, DonThuc &d) {
        is >> d.HeSo >> d.SoMu;
        return is;
    }
    friend ostream& operator << (ostream &os, DonThuc d) {
        if (d.SoMu != 0) {
            if (abs (d.HeSo) != 1) os << abs (d.HeSo);
        }
        if (d.SoMu > 1) os << "x^" << d.SoMu;
        else if (d.SoMu == 1) os << 'x';
        return os;
    }
};

struct Node {
    DonThuc data;
    Node* next;
};

typedef struct Node* node;

node make_node (DonThuc x) {
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
    friend istream& operator >> (istream &is, LinkedList &l) {
        DonThuc d;
        while (is >> d) l.addTail (make_node (d));
        return is;
    }
    void Print () {
        bool kt = false;
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data.HeSo != 0) {
                cout << p->data;
                kt = true;
            }
            if (p->next->data.HeSo < 0 && kt && p->next != nullptr) cout << '-';
            else if (p->next->data.HeSo > 0 && kt && p->next != nullptr) cout << '+';
        }
    }
    LinkedList operator + (LinkedList &another) {
        int len = max (this->size, another.size);
        this->size = another.size = len;
        
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
    LinkedList f1, f2;
    cin >> f1 >> f2;

    return 0;
}