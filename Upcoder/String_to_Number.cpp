#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

bool ktHopLe (string str) {
    bool dauCham = false;
    for (int i = 0; i < str.length (); i++) {
        if (str[i] == '-' && i == 0) continue;
        if (!isdigit (str[i]) && str[i] == '.') {
            if (dauCham) return false;
            dauCham = true;
        } else if (!isdigit (str[i]) && str[i] != '.') return false;
    }
    return true;
}

int main () {
    string n; cin >> n;
    if (!ktHopLe (n)) {
        cout << "Invalid";
        return 0;
    }
    double a = stod (n);
    cout << "Value: " << a << endl;
    cout << "Sign: ";
    if (a < 0) cout << "Negative" << endl;
    else if (a == 0) cout << "Neutral" << endl;
    else cout << "Positive" << endl;
    string h = to_string (a);
    cout << h;
    // cout << "Precision: " << soChuSo (a) << endl;
    // cout << "Scale: " << soChuSoSau (a);
    return 0;
}