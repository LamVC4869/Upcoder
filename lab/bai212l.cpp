#include <iostream>
#include <stack>

using namespace std;

int main () {
    string str; cin >> str;
    stack<char> a;
    for (char x : str) {
        if (x != '*') a.push (x);
        else {
            cout << a.top ();
            a.pop ();
        }
    }
    return 0;
}