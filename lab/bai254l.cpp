#include <iostream>
#include <stack>

using namespace std;

string convert (int n, int T) {
    stack<char> st;
    while (n) {
        int tmp = n % T;
        char c;
        c =  (tmp < 10) ? '0' + tmp : 'A' + tmp - 10;
        st.push (c);
        n /= T;
    }
    string result;
    while (!st.empty ()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    int n, t; cin >> n >> t;
    cout << convert (n, t);
    return 0;
}
