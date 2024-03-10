#include <iostream>

using namespace std;

struct Test {
    int n, k;
    string str;
    friend istream& operator >> (istream &is, Test &t) {
        is >> t.n >> t.k;
        is >> t.str;
        return is;
    }
    bool kiemTra () {
        int len = 0;
        bool kt = false;
        for (int i = 0; i < str.length (); i++) {
            if (str[i] == 'V' || str[i] == 'X') {
                for (int x = i + k; x < str.length (); x += k) {
                    if (str[x] == '#') return false;
                }
                for (int j = i + 1; j < str.length (); j++) {
                    if (str[j] == 'V' || str[j] == 'X') {
                        len = j - i;
                        kt = true;
                        break;
                    }
                }
            } 
            if (kt) break;
        }
        return len % k == 0;
    }
    friend ostream& operator << (ostream &os, Test t) {
        os << (t.kiemTra () ? "YES\n" : "NO\n");
        return os;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n; cin >> n;
    while (n--) {
        Test t; 
        cin >> t;
        cout << t;
    }
    return 0;
}