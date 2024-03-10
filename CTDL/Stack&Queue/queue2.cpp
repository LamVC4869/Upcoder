#include <iostream>
#include <queue>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return n > 1;
}

int main () {
    queue<int> q;
    int n; cin >> n;
    for (int i = 2; i <= 7 && i <= n; i++) if (isPrime (i)) q.push (i);
    while (!q.empty ()) {
        for (int i = 1; i <= 9; i++) {
            int k = q.front () * 10 + i;
            if (isPrime (k) && k <= n) q.push (k);
        }
        cout << q.front () << " ";
        q.pop ();
    }
    return 0;
}