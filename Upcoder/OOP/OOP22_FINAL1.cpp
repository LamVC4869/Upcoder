#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Set {
    private:
    vector<int> vt;
    public:
    Set () {}
    Set (int n) {
        for (int i = 1; i <= n; i++) vt.push_back (i);
    }
    Set (int a, int b) {
        if (a <= b) {
            for (int i = a; i <= b; i++) vt.push_back (i);
        }
    }
    friend ostream& operator << (ostream &os, Set s) {
        if (!s.vt.empty ()) {
            sort (s.vt.begin (), s.vt.end ());
            for (int i = 0; i < s.vt.size (); i++) os << s.vt[i] << ' ';
        } else os << "NULL";
        return os;
    }
    bool daTonTai (int index) {
        for (int i = 0; i < this->vt.size (); i++) if (index == this->vt[i]) return true;
        return false;
    }
    bool Push (int index) {
        if (!daTonTai (index)) {
            this->vt.push_back (index);
            return true;
        } else return false;
    }
    Set operator + (const Set other) {
        Set result;
        for (int i = 0; i < this->vt.size (); i++) result.Push (vt[i]);
        for (int i = 0; i < other.vt.size (); i++) if (!daTonTai(other.vt[i])) result.Push (other.vt[i]);
        return result;
    }
    Set operator - (const Set other) {
        Set result;
        for (int i = 0; i < other.vt.size (); i++) if (daTonTai(other.vt[i])) result.Push (other.vt[i]);
        return result;
    }
};

int main () {
    int n, a, b; cin >> n >> a >> b;
    Set s1(n), s2(a, b);
    cout << s1 + s2 << endl << s1 - s2;
    return 0;
}