#include <iostream>
#define endl '\n'

using namespace std;

void push (string &str) {
    char tmp = str[0];
    str.insert (str.length (), 1, tmp);
    str.erase (0, 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.tie (NULL);
    string str; getline (cin, str);
    str.insert (0, 21, ' ');
    for (int i = 0; i < str.length (); i++) {
        push (str);
        cout << "++++++++++++++++++++++" << endl << '+';
        for (int j = 0; j < 20; j++) cout << str[j];
        cout << '+' << endl << "++++++++++++++++++++++";
        if (i != str.length () - 1) cout << endl;
    }
    return 0;
}