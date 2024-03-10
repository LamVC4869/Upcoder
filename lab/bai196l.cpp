#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main () {
    string a, tmp; cin >> a;
    for (char &c : a) c = tolower (c);
    for (int i = 0; i < a.length () - 1; i++) {
        for (int j = i + 1; j < a.length (); j++) {
            if (a[i] == a[j]) a[j] = ' ';
            else if (a[i] != a[j]) continue;
        }
    }
    while (a[0] == ' ') {
        a.erase (0, 1);
    }
    while (a[a.length() - 1] == ' ') {
        a.erase (a.length() - 1, 1);
    }
    int i = 0;
    while (i < a.length()) {
        if (a[i] == ' ' && a[i + 1] == ' ') {
            a.erase (i, 1);
        } else {
            i++;
        }
    }
    set<string> s;
    stringstream ss (a);
    while (getline (ss, tmp, ' ')) {
        if (!tmp.empty ()) s.insert (tmp);
    }
    cout << s.size ();
    return 0;
}