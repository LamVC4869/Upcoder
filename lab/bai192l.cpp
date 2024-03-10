#include <iostream>

using namespace std;

int reverse_int (int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

struct SoDao {
    int num;
    friend istream& operator >> (istream &is, SoDao &a) {
        is >> a.num;
        return is;
    }
    friend ostream& operator << (ostream &os, SoDao a) {
        os << "[SoDao] " << a.num;
        return os << '\n';
    }
    int reverse () {
        int res = 0;
        while (num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    friend bool operator > (SoDao a, SoDao b) {
        return a.reverse () > b.reverse ();
    }
    friend int operator + (SoDao a, SoDao b) {
        return a.reverse() + b.reverse ();
    }
    int operator = (int index) {
        index = this->num;
        return index;
    }
    int operator = (SoDao s) {
        return this->num = s.num;
    }
    friend int operator + (SoDao s, int n) {
        return s.reverse () + reverse_int (n);
    }
};

int reverse_int (SoDao n) {
    int res = 0;
    while (n.num) {
        res = res * 10 + n.num % 10;
        n.num /= 10;
    }
    return res;
}

template <typename T>
struct Arr {
    int size = 0;
    T arr[1000];
    friend istream& operator >> (istream &is, Arr<T> &a) {
        T tmp; is >> tmp;
        a.arr[a.size++] = tmp;
        return is;
    }
    int TongSo () {
        int tmp = reverse_int (arr[0]);
        for (int i = 1; i < size; i++) tmp = tmp + reverse_int(arr[i]);
        return tmp;
    }
    T maxVal () {
        T result = arr[0];
        for (int i = 1; i < size; i++) if (arr[i] > result) result = arr[i];
        return result;
    }
};

int main () {
    Arr<int> a;
    Arr<SoDao> b;
    char c;
    while (cin >> c) {
        if (c == 'T') cin >> a;
        else if (c == 'D') cin >> b;
    }
    if (a.size == 0) cout << "khong co" << '\n' << "khong co" << '\n';
    else {
        cout << a.TongSo () << '\n' << a.maxVal ();
    }
    if (b.size == 0) cout << "khong co" << '\n' << "khong co";
    else {
        cout << b.TongSo () << '\n' << b.maxVal ();
    }
    return 0;
}