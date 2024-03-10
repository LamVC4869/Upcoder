#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> even, odd;

void Printf () {
    int digit;
    while (cin >> digit) {
        if (digit & 1) odd.push_back (digit);
        else even.push_back (digit);
    }
    sort (even.begin (), even.end ());
    sort (odd.rbegin (), odd.rend ());
}

void Scanf () {
    vector<int>::iterator it, rit;
    for (it = even.begin (); it != even.end (); it++) cout << *it << ' ';
    cout << "\n";
    for (rit = odd.begin (); rit != odd.end (); rit++) cout << *rit << ' ';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    Printf ();
    Scanf ();
    return 0;
}