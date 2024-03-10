#include <iostream>
#include <cmath>

using namespace std;

struct tiSo {
    int banthang1, banthang2;
    friend istream& operator >> (istream &is, tiSo &t) {
        is >> t.banthang1 >> t.banthang2;
        return is;
    }
    friend ostream& operator << (ostream &os, tiSo t) {
        os << t.banthang1 << ' ' << t.banthang2;
        return os;
    }
    bool operator > (tiSo another) {
        if (abs (this->banthang1 - this->banthang2) > abs (another.banthang1 - another.banthang2)) return true;
        else if (abs (this->banthang1 - this->banthang2) == abs (another.banthang1 - another.banthang2)) {
            if (this->banthang1 + this->banthang2 > another.banthang1 + another.banthang2) return true;
        }
        return false;
    }
};

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n; cin >> n;
    tiSo a[n];
    for (tiSo &i : a) cin >> i;
    tiSo res = a[0];
    for (int i = 1; i < n; i++) if (a[i] > res) res = a[i];
    cout << res;
    return 0;
}