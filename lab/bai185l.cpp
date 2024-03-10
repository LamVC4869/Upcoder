#include <iostream>
#define endl '\n'

using namespace std;

struct Phonenumber {
    string pn;
    int cuocGoiDen, cuocGoiDi;
    friend istream& operator >> (istream &is, Phonenumber &p) {
        getline (is, p.pn);
        is >> p.cuocGoiDen >> p.cuocGoiDi;
        return is;
    }
    friend ostream& operator << (ostream &os, Phonenumber p) {
        os << '{' << p.pn << ',' << p.cuocGoiDen << ',' << p.cuocGoiDi << '}';
        return os << endl;
    }
    static Phonenumber Find_PhoneNumber (Phonenumber arr[], int size, string num) {
        Phonenumber result;
        for (int i = 0; i < size; i++) if (arr[i].pn == num) result = arr[i];
        return result;
    }
    static Phonenumber goiDenNhieuNhat (Phonenumber arr[], int size) {
        Phonenumber result = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i].cuocGoiDen > result.cuocGoiDen) result = arr[i];
        }
        return result;
    }
    static Phonenumber goiDiItNhat (Phonenumber arr[], int size) {
        Phonenumber result = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i].cuocGoiDi < result.cuocGoiDi) result = arr[i];
        }
        return result;
    }
};

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n;
    string num;
    cin >> n; cin.ignore ();
    getline (cin, num);
    Phonenumber arr[n];
    for (Phonenumber &i : arr) cin >> i;
    cout << Phonenumber::Find_PhoneNumber (arr, n, num) << Phonenumber::goiDenNhieuNhat (arr, n) << Phonenumber::goiDiItNhat (arr, n);
    return 0;
}