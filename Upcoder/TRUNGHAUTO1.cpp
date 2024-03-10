#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int doUuTien (char x) {
    if (x == '^') return 5;
    else if (x == '*' || x == '/') return 4;
    else if (x == '+' || x == '-') return 3;
    return 2;
}

bool isToanTu (char x) {
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}

int main () {
    string trungTo;
    getline (cin, trungTo);
    int i = 0;
    while (i < trungTo.length ()) {
        if (trungTo[i] == ' ') trungTo.erase (i, 1);
        else i++;
    }
    stack<char> s;
    queue<char> q;
    for (char x : trungTo) {
        if (isalpha (x)) q.push (x);
        else if (x == '(') s.push (x);
        else if (isToanTu (x)) {
            while (!s.empty () && doUuTien (x) <= doUuTien (s.top ())) {
                q.push (s.top ());
                s.pop ();
            }
            s.push (x);
        } else if (x == ')') {
            while (!s.empty () && s.top () != '(') {
                q.push (s.top ());
                s.pop ();
            }
            s.pop ();
        }
    }
    while (!q.empty ()) {
        cout << q.front ();
        q.pop ();
    }
    while (!s.empty ()) {
        cout << s.top ();
        s.pop ();
    }
    return 0;
}