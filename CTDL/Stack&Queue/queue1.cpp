#include <iostream>
#include <queue>

using namespace std;

int main () {
    int n; cin >> n;
    queue<int> q;
    while (n--) {
        int x; cin >> x;
        q.push (x);
    }
    int k; cin >> k;
    while (k--) {
        q.push (q.front());
        q.pop ();
    }
    while (!q.empty ()) {
        cout << q.front () << ' ';
        q.pop ();
    }
    
    return 0;
}