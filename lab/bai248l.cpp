#include <iostream>
#include <stack>

using namespace std;

int main () {
    stack<int> st;
    int q; cin >> q;
    while (cin >> q) {
        if (q == 1) {
            int x; cin >> x;
            st.push (x);
        } else if (q == 2) {
            st.pop ();
        } else if (q == 3) {
            int x = st.top ();
            st.pop ();
            cout << st.top () << endl;
            st.push (x);
        }
    }
    return 0;
}