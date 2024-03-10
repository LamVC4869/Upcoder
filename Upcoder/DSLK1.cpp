#include <iostream>
#include <vector>

using namespace std;

int main () {
    char c;
    vector<char> v;
    while (cin >> c) v.push_back (c);
    c = '1';
    for (auto i = v.begin (); i != v.end (); ++i) {
        if (*i > c) {
            cout << *i << ' ';
            c = *i;
        }
    }
    return 0;
}