#include <iostream>
#include <stack>

using namespace std;

int main () {
    string str, res = ""; cin >> str;
    stack<char> st;
    str += ' ';
    for (int i = 0; i < str.length (); i++) {
        if (st.empty () || st.top () == str[i]) {
            st.push (str[i]);
        } else {
            res += st.top () + to_string (st.size ());
            while (!st.empty ()) st.pop ();
            st.push (str[i]);
        }
    }
    cout << res;
    return 0;
}