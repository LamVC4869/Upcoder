#include <iostream>
#define ll long long
#define endl '\n'

using namespace std;

struct NhanVien {
    string id;
    string name;
    ll salary;
    friend istream& operator >> (istream &is, NhanVien &nv) {
        getline (is, nv.id);
        getline (is, nv.name);
        is >> nv.salary;
        is.ignore ();
        return is;
    }
    friend ostream& operator << (ostream &os, NhanVien nv) {
        os << '{' << nv.name << ", " << nv.id << ", ";
        os << nv.salary << '}';
        return os;
    }
};

struct Node {
    NhanVien data;
    Node* next;
};

typedef struct Node* node;

node make_node (NhanVien &x) {
    node p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList {
    node pHead = NULL;
    node pTail = NULL;
    void AddTail (node p) {
        if (pHead == NULL) pHead = pTail = p;
        else {
            pTail->next = p;
            pTail = p;
        }
    }
    void sort () {
        for (node p = pHead; p != pTail; p = p->next) {
            for (node p1 = p->next; p1 != NULL; p1 = p1->next) {
                if (p->data.salary < p1->data.salary) swap (p->data, p1->data);
            }
        }
    }
    string TenNhanVienLuongCaoNhat (ll max) {
        string str;
        for (node p = pHead; p != NULL; p = p->next) {
            if (p->data.salary == max) {
                str = p->data.name;
                break;
            }
        }
        return str;
    }
    ll tongLuong () {
        ll res = 0;
        for (node p = pHead; p != NULL; p = p->next) res += p->data.salary;
        return res;
    }
    void PrintList () {
        for (node p = pHead; p != NULL; p = p->next) {
            cout << p->data << endl;
        }
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
    LinkedList l;
    int n; cin >> n;
    cin.ignore ();
    NhanVien x;
    while (n--) {
        cin >> x;
        l.AddTail (make_node (x));
    }
    l.PrintList ();
    LinkedList l1 = l;
    l1.sort ();
    ll total = l1.pHead->data.salary;
    cout << l.TenNhanVienLuongCaoNhat (total) << endl;
    cout << l.tongLuong () << endl;
    node p = make_node (l1.pHead->data);
    cout << p;
    return 0;
}