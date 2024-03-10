#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool checkSDT (string &str) {
    if (str[0] != '0') return false;
    for (int i = 0; i < str.length (); i++) if (isdigit (str[i])) return true;
    return false;
}

string sdt (string &str) {
    while (!isdigit(str[str.length () - 1])) str.erase (str.length () - 1);
    return str;
}

bool checkLengthSDT (string &str) {
    return str.length () >= 9 && str.length () <= 10;
}

int main () {
    freopen("BINHLUAN.TXT", "r", stdin);
    freopen("SDT.TXT", "w", stdout);
    string cmt;
    getline (cin, cmt);
    vector<string> v;
    stringstream ss (cmt);
    string tmp;
    while (getline (ss, tmp, ' ')) if (checkSDT (tmp)) {
        tmp = sdt (tmp);
        if (checkLengthSDT (tmp)) v.push_back (tmp);
    }
    if (v.empty ()) cout << "HANG FAKE NEN KHONG AI MUA !";
    else {
        for (string x : v) cout << x << endl;
    }
    return 0;
}