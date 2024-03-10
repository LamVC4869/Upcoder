#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n, m, pos; cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back (i);
    vector<int>::iterator it = v.begin ();
    while (!v.empty ()) {
        pos = m;
        while (--pos) {
            it++;
            if (it == v.end ()) it = v.begin ();
        }
        cout << *it << ' ';
        v.erase (it);
        if (it == v.end ()) it = v.begin ();
    }
    return 0;
}