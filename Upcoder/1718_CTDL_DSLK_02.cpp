#include <iostream>
#include <cmath>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

bool isSquareNumber (int n) {
    return int (sqrt (n)) == sqrt (n);
}

int TongCacUocNgoaiTruChinhNo (int n) {
    int result = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) result += i;
    }
    return result;
}

bool isPerfectNumber (int n) {
    return n == TongCacUocNgoaiTruChinhNo (n);
}

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
    node Address (int i) {
        int j = 0;
        node p = pHead;
        while (p != nullptr && j < i) {
            p = p->next;
            j++;
        }
        return p;
    }
    bool empty () {
        return pHead == nullptr;
    }
    void Print () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data;
            if (p != pTail) cout << ' ';
        }
    }
    ~LinkedList () {
        node p = nullptr;
        while (pHead != nullptr) {
            p = pHead;
            pHead = pHead->next;
            delete p;
            size--;
        }
    }
};

int main () {
    LinkedList listPrime;
    LinkedList listSquareNumber;
    LinkedList listPerfectNumber;
    int n;
    while (cin >> n) {
        if (isPrime (n)) listPrime.addTail (make_node (n));
        if (isSquareNumber (n)) listSquareNumber.addTail (make_node (n));
        if (isPerfectNumber (n)) listPerfectNumber.addTail (make_node (n));
    }
    if (listPrime.empty ()) cout << "NULL";
    else listPrime.Print ();
    cout << endl;
    if (listSquareNumber.empty ()) cout << "NULL";
    else listSquareNumber.Print ();
    cout << endl;
    if (listPerfectNumber.empty ()) cout << "NULL";
    else listPerfectNumber.Print ();
    return 0;
}