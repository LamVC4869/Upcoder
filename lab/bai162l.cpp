#include <iostream>
#define endl "\n"

using namespace std;

struct SoMoi {
    int a;
    friend istream& operator >> (istream &is, SoMoi &s) {
        is >> s.a;
        return is;
    }
    friend ostream& operator << (ostream &os, SoMoi s) {
        os << "[SoMoi] " << s.a;
        return os;
    }
    int tongChuSo () {
        int res = 0, x = a;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    bool operator > (SoMoi s) {
        return this->tongChuSo () > s.tongChuSo ();
    }
    SoMoi operator + (SoMoi s) {
        SoMoi r;
        r.a = this->tongChuSo () + s.tongChuSo ();
        return r;
    }
    bool operator == (SoMoi s) {
        return this->a == s.a;
    }
    int operator + (int n) {
        return n + this->tongChuSo ();
    }
};

template <typename T>
struct Arr {
    int size = 0;
    T arr[1000];
    friend istream& operator >> (istream &is, Arr<T> &a) {
        T in;
        while (is >> in) a.arr[a.size++] = in;
        return is;
    }
    T MaxVal () {
        T max = arr[0];
        for (int i = 1; i < size; i++) if (arr[i] > max) max = arr[i];
        return max;
    }
    int CountMax () {
        int cnt = 0;
        T maxVal = MaxVal ();
        for (int i = 0; i < size; i++) if (arr[i] == maxVal) cnt++;
        return cnt; 
    }
    int tongDaySo () {
        int res = 0;
        for (int i = 0; i < size; i++) res = arr[i] + res;
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    Arr<int> a;
    Arr<SoMoi> b;
    char c; cin >> c;
    if (c == 'N') {
        cin >> a;
        cout << a.MaxVal () << endl << a.CountMax () << endl;
        cout << a.tongDaySo ();
    } else if (c == 'M') {
        cin >> b;
        cout << b.MaxVal () << endl << b.CountMax () << endl;
        cout << "[SoMoi]" << b.tongDaySo ();
    }
    return 0;
}