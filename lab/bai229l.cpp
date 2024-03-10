#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Ngay {
    int ngay, thang, nam;
    friend istream& operator >> (istream &is, Ngay &n) {
        char c;
        is >> n.ngay >> c >> n.thang >> c >> n.nam;
        return is;
    }
    friend ostream& operator << (ostream &os, Ngay n) {
        if (n.ngay < 10) os << 0;
        os << n.ngay << '/';
        if (n.thang < 10) os << 0;
        os << n.thang << '/';
        os << n.nam;
        return os;
    }
    bool operator > (Ngay another) {
        if (this->nam > another.nam) return true;
        else if (this->nam == another.nam) {
            if (this->thang > another.thang) return true;
            else if (this->thang == another.thang) {
                if (this->ngay > another.ngay) return true;
            }
        }
        return false;
    }
};

struct HOPSUA {
    string id;
    double weight;
    Ngay hsd;
    friend istream& operator >> (istream &is, HOPSUA &hs) {
        char c;
        is >> hs.id;
        hs.id.erase (hs.id.length () - 1, 1);
        is >> hs.weight >> c;
        is >> hs.hsd;
        return is;
    }
    friend ostream& operator << (ostream &os, HOPSUA hs) {
        os << hs.id << ", " << hs.weight << ", " << hs.hsd << endl;
        return os;
    }
};

struct Node {
    HOPSUA data;
    Node* next;
};

typedef struct Node* node;

node make_node (HOPSUA &x) {
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
    int demHopSuaTruoc2003 () {
        int cnt = 0;
        for (node p = pHead; p != nullptr; p = p->next) {
            if (p->data.hsd.nam < 2003) cnt++;
        }
        return cnt;
    }
    void sort () {
        for (node p = pHead; p != pTail; p = p->next) {
            for (node p1 = p->next; p1 != nullptr; p1 = p1->next) {
                if (p->data.hsd > p1->data.hsd) swap (p->data, p1->data);
            }
        }
    }
    void PrintID () {
        for (node p = pHead; p != nullptr; p = p->next) {
            cout << p->data.id;
            if (p->next->next != nullptr) cout << ", ";
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
    int n; cin >> n;
    LinkedList l;
    while (n--) {
        HOPSUA x; cin >> x;
        l.addTail (make_node (x));
    }
    cout << l.demHopSuaTruoc2003 () << endl;
    l.sort ();
    cout << l.pTail << endl;
    l.PrintID ();
    return 0;
}