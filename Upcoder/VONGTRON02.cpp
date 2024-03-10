#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n, k; cin >> n >> k;
    int pos[k], cnt = 0;
    for (int i = 0; i < k; i++) cin >> pos[i];
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back (i);
    vector<int>::iterator it = v.begin ();
    while (!v.empty ()) {
        int index = pos[cnt];
        while (--index) {
            it++;
            if (it == v.end ()) it = v.begin ();
        }
        cout << *it << ' ';
        v.erase (it);
        if (it == v.end ()) it = v.begin ();
        cnt++;
        if (cnt == k) cnt = 0;
    }
    return 0;
}