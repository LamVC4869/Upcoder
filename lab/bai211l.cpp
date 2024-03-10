#include <iostream>
#include <stack>

using namespace std;

int main () {
    string s; cin >> s;
    stack<char> st;
    bool kt = true;
    for (char x : s) {
        if (x == '{' || x == '[' || x == '(') st.push (x);
        else {
            if (!st.empty ()) {
                if (x == ')') {
                    if (st.top () == '(') st.pop ();
                    else {
                        kt = false; break;
                    }
                } else if (x == ']') {
                    if (st.top () == '[') st.pop ();
                    else {
                        kt = false; break;
                    }
                } else if (x == '}') {
                    if (st.top () == '{') st.pop ();
                    else {
                        kt = false; break;
                    }
                }
            } else kt = false;
        }
    }
    if (!st.empty ()) kt = false;
    cout << (kt ? "yes" : "no");
    return 0;
}