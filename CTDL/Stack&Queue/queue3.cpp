#include <iostream>
#include <queue>

using namespace std;

bool kt[1000010] = {};

int main () {
    queue<int> q;
    int n, k; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    cin >> k;
    for (int i : a) {
        if (!kt[i]) {
            if (q.size () < k) {
                q.push (i);
                kt[i] = true;
            } else if (q.size () == k) {
                q.push (i);
                kt[i] = true;
                kt[q.front ()] = false;
                q.pop ();
            }
        }
    }
    while (!q.empty ()) {
        cout << q.front () << ' ';
        q.pop ();
    }
    return 0;
}