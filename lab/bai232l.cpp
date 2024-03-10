#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct THISINH {
    string sbd;
    double mon1, mon2, mon3;
    friend istream& operator >> (istream &is, THISINH &a) {
        is >> a.sbd >> a.mon1 >> a.mon2 >> a.mon3;
        return is;
    }
    friend ostream& operator << (ostream &os, THISINH a) {
        os << a.sbd << ' ' << a.mon1 << ' ' << a.mon2 << ' ' << a.mon3;
        return os << endl;
    }
    double dtb () {
        return (mon1 + mon2 + mon3) * 1.0 / 3;
    }
    bool operator < (THISINH another) {
        if (this->dtb () < another.dtb ()) return true;
        else if (this->dtb () == another.dtb ()) {
            return this->sbd > another.sbd;
        }
    }
};

int main () {
    int n;
    double score;
    cin >> n >> score;
    vector<THISINH> v(n);
    vector<THISINH> pass;
    for (THISINH &i : v) {
        cin >> i;
        if (i.dtb () >= score) pass.push_back (i);
    }
    if (pass.empty ()) cout << "NULL";
    else {
        sort (pass.rbegin (), pass.rend ());
        for (THISINH i : pass) cout << i;
    }
    return 0;
}