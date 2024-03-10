#include <iostream>
#include <vector>

using namespace std;

int main () {
    string str;
    cin >> str;
    vector<string> v;
    int pos = 1;
    for (int i = pos; i < str.length (); i++) {
        string tmp = "";
        if (str[i - 1] == '-') {
            for (int j = i; j < str.length (); j++) {
                if (!isdigit (str[j])) break;
                tmp += str[j];
                pos = j + 1;
            }
            v.push_back (tmp);
        }
    }
    for (string x : v) cout << '-' << x << ' ';
    return 0;
}