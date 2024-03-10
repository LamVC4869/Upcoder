#include <iostream>
#include <queue>

using namespace std;

int main () {
    string str; cin >> str;
    queue<char> q;
    for (char x : str) {
        if (x != '*') q.push (x);
        else {
            if (!q.empty ()) {
                cout << q.front ();
                q.pop ();
            }
        }
    }
    return 0;
}