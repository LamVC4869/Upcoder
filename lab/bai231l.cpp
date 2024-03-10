#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll PriceI (int i) {
    if (i < 101) return 1484 * i;
    else if (i < 201) {
        return 100 * 1484 + (i - 100) * 1786;
    } else return 100 * 1484 + 100 * 1786 + (i - 200) * 2503;
}

ll PriceH2O (int h2o) {
    if (h2o <= 10) return 5973 * h2o;
    else if (h2o <= 30) return 59730 + (h2o - 10) * 7052;
    else return 59730 + 20 * 7052 + (h2o - 30) * 15929; 
}

struct Apartment {
    string num;
    int I, H2O;
    friend istream& operator >> (istream &is, Apartment &a) {
        is >> a.num >> a.I >> a.H2O;

        return is;
    }
    friend ostream& operator << (ostream &os, Apartment a) {
        os << a.num << ' ' << PriceI (a.I) << ' ' << PriceH2O (a.H2O) << endl;
        return os;
    }
    ll tongTien () {
        return PriceI(I) + PriceH2O(H2O);
    }
    bool operator < (Apartment another) {
        return this->tongTien () < another.tongTien ();
    }
};

int main () {
    int n;
    string id;
    cin >> n >> id;
    vector<Apartment> v(n);
    vector<Apartment> Find;
    for (Apartment &i : v) {
        cin >> i;
        if (i.num == id) Find.push_back (i);
    }
    if (Find.empty ()) cout << "NOT FOUND\n";
    else cout << "FOUND " << Find[0];
    sort (v.rbegin (), v.rend ());
    for (Apartment i : v) cout << i;
    return 0;
}