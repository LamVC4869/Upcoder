#include <iostream>

using namespace std;

struct SoMoi {
    int num;
    friend istream& operator >> (istream &is, SoMoi &somoi) {
        is >> somoi.num;
        return is;
    }
    friend ostream& operator << (ostream &os, SoMoi somoi) {
        os << "[SoMoi] " << somoi.num;
        return os;
    }
    int TongChuSo (SoMoi index) {
        int res = 0;
        int tmp = index.num;
        while (tmp) {
            res += tmp % 10;
            tmp /= 10;
        }
        return res;
    }
    friend bool operator > (SoMoi s1, SoMoi s2) {
        return s1.num > s2.num;
    }
    friend SoMoi operator + (SoMoi s1, SoMoi s2) {
        SoMoi s3;
        s3.num = s1.num + s2.num;
        return s3;
    }
    friend SoMoi operator + (SoMoi s, int n) {
        SoMoi s3;
        s3.num = s.num + n;
        return s3;
    }
    friend bool operator == (SoMoi s1, SoMoi s2) {
        return s1.num == s2.num;
    }
};

int TongChuSo (int index) {
    int res = 0;
    while (index) {
        res += index % 10;
        index /= 10;
    }
    return res;
}

template <typename T>
struct Arr {
    int size;
    T arr[1000];
    void Printf () {
        this->size = 0;
        T digit;
        while (cin >> digit) this->arr[this->size++] = digit;
    }
    T MaxNum () {
        T max = this->arr[0];
        for (int i = 1; i < this->size; i++) if (this->arr[i] > max) max = this->arr[i];
        return max;
    }
    int MaxNum_Quantity () {
        int count = 0;
        T maxVal = MaxNum ();
        for (int i = 0; i < this->size; i++) if (this->arr[i] == maxVal) count++;
        return count;
    }
    int tongDaySoint () {
        int res = 0;
        for (int i = 0; i < this->size; i++) res = res + TongChuSo (arr[i]);
        return res;
    }
    SoMoi tongDaySo () {
        SoMoi res;
        res.num = 0;
        for (int i = 0; i < this->size; i++) res.num = res.num + TongChuSo (arr[i]);
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie(0);
    char Type; cin >> Type;
    switch (Type) {
    case 'N':
        Arr<int> a;
        a.Printf ();
        cout << a.MaxNum () << endl << a.MaxNum_Quantity () << endl << a.tongDaySoint ();
        break;
    default:
        Arr<SoMoi> b;
        b.Printf ();
        cout << b.MaxNum () << endl << b.MaxNum_Quantity () << endl << b.tongDaySo ();
        break;
    }
    return 0;
}