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
    LinkedList () : pHead(nullptr), pTail(nullptr) {}
};

typedef struct LinkedList list;

void addHead (list &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void addTail (list &l, node p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void PrintList (list l) {
    cout << "\nDanh sach lien ket: ";
    if (l.pHead == nullptr) cout << "NULL";
    else {
        for (node p = l.pHead; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
    }
}

void giaiPhongDSLK (list &l) {
    node p = nullptr;
    while (l.pHead != nullptr) {
        p = l.pHead;
        l.pHead = l.pHead->next;
        delete p;
    }
    cout << "\nDa giai phong danh sach lien ket";
}

void Push_node_back (list &l, node p) {
    int x;
    cout << "\nVao sau node q co gia tri: ";
    cin >> x;
    node q = make_node (x);
    if (q->data == l.pHead->data && l.pHead->next == nullptr) addTail (l, p);
    else {
        node k = l.pHead;
        while (k != nullptr) {
            if (k->data == q->data) {
                node tmp = make_node (p->data);
                node m = k->next;
                tmp->next = m;
                k->next = tmp;
            }
            k = k->next;
        }
    }
}  

void push_node_front (list &l, node p) {
    int x;
    cout << "\nVao truoc node q co gia tri: ";
    cin >> x;
    node q = make_node (x);
    if (l.pHead->data == q->data && l.pHead->next == nullptr) addHead (l, p);
    else {
        node g = nullptr;
        for (node k = l.pHead; k != nullptr; k = k->next) {
            if (k == l.pHead && k->data == q->data) addHead (l, make_node (p->data));
            else if (k != l.pHead && k->data == q->data) {
                node tmp = make_node (p->data);
                tmp->next = k;
                g->next = tmp;
            }
            g = k;
        }
    }
}

void push_node_vao_vi_tri (list &l, node a) {
    int pos;
    do {
        cout << "\nVao vi tri thu: ";
        cin >> pos;
        if (pos < 1 || pos > l.size + 1) {
            cout << "\nVi tri phai nam trong doan tu [" << 1 << ", " << l.size + 1 << "]";
            cout << "\nVui long nhap lai!";
            system("pause");
        }
    } while (pos < 1 || pos > l.size + 1);
    if (pos == 1 || l.pHead == nullptr) addHead (l, a);
    else if (pos == l.size + 1) addTail (l, a);
    else {
        node p = l.pHead;
        for (int i = 1; i < pos - 1; i++) p = p->next;
        a->next = p->next;
        p->next = a;
    }
}

void DeleteHead (list &l) {
    if (l.pHead == nullptr) return;
    node p = l.pHead;
    l.pHead = l.pHead->next;
    delete p;
}

void DeleteTail (list &l) {
    if (l.pHead == nullptr) return;
    else if (l.pHead->next == nullptr) DeleteHead (l);
    else {
        for (node p = l.pHead; p != nullptr; p = p->next) {
            if (p->next == l.pTail) {
                delete l.pTail;
                p->next = nullptr;
                l.pTail = p;
            }
        }
    }
}

void Delete_node_back (list &l, node q) {
    if (l.pHead == nullptr) return;
    else if (q->data == l.pTail->data) return;
    else {
        for (node p = l.pHead; p != nullptr; p = p->next) {
            while (p->data == q->data && p->next->data == q->data) {
                node tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                l.size--;
                if (p->next == nullptr) {
                    l.pTail = p;
                    break;
                }
            }
            if (p->next != nullptr) {
                if (p->data == q->data) {
                    node tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                    l.size--;
                    if (p->next == nullptr) l.pTail = p;
                }
            }
        }
    }
}

void Delete_node_bat_ki (list &l, int pos) {
    if (l.pHead == nullptr || pos > l.size) return;
    else if (pos == 1) {
        DeleteHead (l);
        l.size--;
    } else if (pos == l.size) {
        DeleteTail (l);
        l.size--;
    } else {
        node p = l.pHead;
        for (int i = 1; i < pos - 1; i++) p = p->next;
        node tmp = p->next;
        p->next = tmp->next;
        delete tmp;
        l.size--;
    }
}

void Menu (list &l) {
    int option;
    while (true) {
        system("cls");
        cout << "\n===================== Menu =====================";
        cout << "\n1. Them node vao cuoi danh sach lien ket.";
        cout << "\n2. Them node vao dau danh sach lien ket.";
        cout << "\n3. In ra danh sach lien ket.";
        cout << "\n4. Them node p vao sau node q.";
        cout << "\n5. Them node p vao truoc node q.";
        cout << "\n6. Them node p vao vi tri bat ki.";
        cout << "\n7. Xoa node dau cua danh sach lien ket.";
        cout << "\n8. Xoa node cuoi cua danh sach lien ket.";
        cout << "\n9. Xoa node p sau node q.";
        cout << "\n10. Xoa node o vi tri bat ki nam trong danh sach lien ket.";
        cout << "\n0. Exit.";
        cout << "\n===================== End =====================";
        cout << "\nNhap lua chon: ";
        cin >> option;
        while (option < 0) {
            cout << "Lua chon khong hop le!\nVui long nhap lai lua chon: ";
            cin >> option;
        }
        if (option == 1) {
            int x;
            cout << "\nNhap gia tri: ";
            cin >> x;
            node p = make_node (x);
            addTail (l, p);
            l.size++;
        } else if (option == 2) {
            int x;
            cout << "\nNhap gia tri: ";
            cin >> x;
            node p = make_node (x);
            addHead (l, p);
            l.size++;
        } else if (option == 3) {
            PrintList (l);
            system("pause");
        } else if (option == 4) {
            int x;
            cout << "\nThem node p co gia tri: ";
            cin >> x;
            node p = make_node (x);
            Push_node_back (l, p);
            l.size++;
        } else if (option == 5) {
            int x;
            cout << "\nThem node p co gia tri: ";
            cin >> x;
            node p = make_node (x);
            push_node_front (l, p);
            l.size++;
        } else if (option == 6) {
            int x;
            cout << "\nThem node p co gia tri: ";
            cin >> x;
            node p = make_node (x);
            push_node_vao_vi_tri (l, p);
            l.size++;
        } else if (option == 7) {
            DeleteHead (l);
            l.size--;
        } else if (option == 8) {
            DeleteTail (l);
            l.size--;
        } else if (option == 9) {
            int x;
            cout << "\nXoa node p sau node q co gia tri: ";
            cin >> x;
            Delete_node_back (l, make_node (x));
        } else if (option == 10) {
            int pos;
            cout << "\nXoa node o vi tri thu: ";
            cin >> pos;
            Delete_node_bat_ki (l, pos);
        } else {
            cout << "\nDa thoat khoi menu.";
            break;
        }
    }
}

int main () {
    list l;
    Menu (l);
    giaiPhongDSLK (l);
    return 0;
}