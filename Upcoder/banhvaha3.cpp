#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    cin.ignore ();
    string str[n];
    for (int i = 0; i < n; i++) getline (cin, str[i]);
    for (int i = 0; i < n; i++) if (str[i].substr (0, 3) == "mrb") {
        for (int j = 4; j < str[i].length (); j++) cout << str[i][j];
        cout << endl;
    }
    return 0;
}