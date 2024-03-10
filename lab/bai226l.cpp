#include <iostream>
#include <stack>

using namespace std;

bool kt (string &str, stack<char> st) {
    int l = str.length ();
    for (int i = 0; i < l; i++) {
        if (str[i] == ')') {
            if (st.empty ()) return false;
            else {
                st.pop ();
            }
        } else if (str[i] == '(') st.push (str[i]);
    }
    return st.empty ();
}

int main () {
    string n; cin >> n;
    stack<char> st;
    cout << (kt (n, st) ? "TRUE" : "FALSE");
    return 0;
}