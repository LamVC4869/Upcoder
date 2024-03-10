#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n, digit, i = 0;
    cin >> n;
    vector<int> v;
    while (cin >> digit) {
        v.push_back (digit);
        i++;
        if (i == n) break;
    }
    cin.ignore ();
    string pos;
    getline (cin, pos);
    if (pos == "-1") {
        cout << "empty";
    } else if (pos[1] == ' ') {
        int x = pos[0] - '0';
        int y = pos[2] - '0';
        int i = x;
        while (i < y) {
            v.erase (v.begin () + x);
            i++;
        }
        for (auto it = v.begin (); it != v.end (); it++) cout << *it << " ";
        if (!v.size ()) cout << "empty";
    } else if (pos.size () == 1) {
        int x = stoi (pos);
        v.erase (v.begin () + x);
        for (auto it = v.begin (); it != v.end (); it++) cout << *it << " ";
        if (!v.size ()) cout << "empty";
    }
    return 0;
}