#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void Sap_xep_chuoi (string &a) {
    for (int i = 0; i < a.length (); ++i) {
        for (int j = i + 1; j < a.length (); ++j) {
            if (a[i] > a[j]) {
                char c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
}

int main () {
    string str;
    getline (cin, str);
    string num, word; num = word = "";
    for (int i = 0; i < str.length (); ++i) {
        if (isalpha (str[i])) word += tolower (str[i]);
        else if (isdigit (str[i])) num += str[i];
    }
    Sap_xep_chuoi (num);
    Sap_xep_chuoi (word);
    string res = num + word;
    int l = res.length ();
    bool duyet[l] = {};
    for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; j++) {
            if (res[i] == res[j]) duyet[j] = true;
        }
    }
    for (int i = 0; i < l; ++i) {
        int cnt = 1;
        if (!duyet[i]) {
            cout << res[i] << ' ';
            for (int j = i + 1; j < l; ++j) {
                if (duyet[j] && res[i] == res[j]) cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}