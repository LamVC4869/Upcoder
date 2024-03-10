#include <iostream>
#include <string>

using namespace std;

bool inspect (string s, string t) {
    for (int i = 0; i <= t.length () - s.length (); i++) {
        if (t.substr (i, s.length ()) == s) return true;
    }
    return false;
}

int main () {
    string s, t;
    getline (cin, s);
    getline (cin, t);
    if (s.length () > t.length ()) {
        cout << "False";
        return 0;
    }

    inspect (s, t) ? cout << "True" : cout << "False";
    return 0;
}