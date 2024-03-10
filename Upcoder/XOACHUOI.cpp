#include <iostream>

using namespace std;

int main () {
    string str1, str2;
    getline (cin, str1);
    getline (cin, str2);
    if (str1.length () > str2.length ()) swap (str1, str2);
    int pos, cnt;
    cnt = pos = 0;
    for (int i = 0; i < str1.length (); i++) {
        for (int j = pos; j < str2.length (); j++) {
            if (str1[i] == str2[j]) {
                pos = j + 1;
                cnt++;
                break;
            }
        }
    }
    cnt == str1.length () ? cout << "YES" << endl << str2.length () - str1.length () : cout << "NO";
    return 0;
}