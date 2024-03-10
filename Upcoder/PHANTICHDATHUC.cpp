#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct DaThuc {
    int size;
    vector<int> v;
    friend istream& operator >> (istream &is, DaThuc &dathuc) {
        is >> dathuc.size;
        dathuc.v = vector<int> (dathuc.size + 1, 0);
        for (int &i : dathuc.v) is >> i;
        return is;
    }
    void Scanf () {
        for (int i = 0; i <= this->size; i++) {
            if (this->v[i] == 0) continue;
            if (i > 0) {
                if (v[i] > 0) cout << '+';
                else cout << '-';
            }
            if (abs(this->v[i]) != 1) cout << abs (this->v[i]);
            else if (i == size) cout << abs (this->v[i]);
            if (i < size - 1) cout << "x^" << this->size - i;
            else if (i == size - 1) cout << 'x';
        }
    }
    bool operator < (DaThuc another) {
        if (this->size < another.size) return true;
        else if (this->size == another.size) {
            for (int i = 0; i <= this->size; i++) {
                if (this->v[i] < another.v[i]) return true;
            }
        }
        return false;
    }
    DaThuc () : size(0) {}
    DaThuc (int size, int value = 1) {
        this->size = size;
        this->v = vector<int>(size + 1, value);
    }
    int Value (int index) {
        int total = 0;
        for (int i = 0; i <= this->size; i++) total += this->v[i] * pow (index, this->size - i);
        return total;
    }
    vector<DaThuc> pt () {
        vector<DaThuc> result;
            for (int i = -10; i <= 10; i++) {
                if (Value(i) == 0 && this->size > 1) {
                    DaThuc t (1, 1);
                    t.v[1] = -i;
                    result.push_back (t);
                    for (int j = 1; j <= this->size; j++) this->v[j] += i * this->v[j - 1];
                    this->size--;
                }
            }
            result.push_back (*this);
            sort (result.begin (), result.end ());
        return result;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    DaThuc a; cin >> a;
    a.Scanf ();
    cout << '=';
    vector<DaThuc> list = a.pt ();
    for (int i = 0; i < list.size (); i++) {
        if (list[i].size == 1 && list[i].v[1] == 0) list[i].Scanf ();
        else {
            cout << "(";
            list[i].Scanf ();
            cout << ")";
        }
    }
    return 0;
}