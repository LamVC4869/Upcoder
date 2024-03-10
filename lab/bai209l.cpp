#include <iostream>

using namespace std;

struct TacGia {
    int n;
    string danhsach[5];
    friend istream& operator >> (istream &is, TacGia &tg) {
        is >> tg.n;
        is.ignore ();
        for (int i = 0; i < tg.n; i++) {
            getline (is, tg.danhsach[i]);
        }
        return is;
    }
};

struct Sach {
    string nameBook;
    TacGia tacgia;
    string NXB;
    int namXB;
    friend istream& operator >> (istream& is, Sach &book) {
        is >> book.nameBook;
        is >> book.tacgia;
        getline (is, book.NXB);
        is >> book.namXB;
        is.ignore ();
        return is;
    }
    friend ostream& operator << (ostream &os, Sach book) {
        os << book.nameBook << '-' << book.tacgia.n << " tac gia-" << book.NXB << '-' << book.namXB;
        return os << endl;
    }
};

struct Node {
    Sach data;
    Node* next;
};

typedef struct Node* node;

node make_node (Sach &x) {
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
    int Count_Sach_Cua_TacGia (string &tenTacGia) {
        int cnt = 0;
        for (node p = pHead; p != nullptr; p = p->next) {
            for (int i = 0; i < p->data.tacgia.n; i++) {
                if (p->data.tacgia.danhsach[i] == tenTacGia) cnt++;
            }
        }
        return cnt;
    }
    void PrintList () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data;
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
    int Y, soLuong;
    string NameNXB, nameTacGia;
    cin >> Y;
    cin.ignore ();
    getline (cin, NameNXB);
    getline (cin, nameTacGia);
    cin >> soLuong;
    LinkedList l;
    for (int i = 0; i < soLuong; i++) {
        Sach x; cin >> x;
        l.AddTail (make_node (x));
    }
    l.PrintList ();
    cout << l.Count_Sach_Cua_TacGia (nameTacGia) << endl;
    LinkedList list;
    int count = 0;
    for (node p = l.pHead; p != nullptr; p = p->next) {
        if (p->data.NXB == NameNXB && p->data.namXB == Y) {
            count++;
            list.AddTail (make_node (p->data));
        }
    }
    cout << count << '\n';
    list.PrintList ();
    return 0;
}