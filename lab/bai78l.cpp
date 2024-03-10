#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    getline (cin, a);
    int i = 0;
    while (i < a.length ()) {
        if (a[i] == 'A' || a[i] == 'a') {
            a.erase (i, 1);
        } else {
            i++;
        }
    }

    int j = 0;
    while (j < a.length ()) {
        if (a[j] == 'u') {
            a.replace (i, 1, "o");
        } else {
            j++;
        }
    }

    cout << a;
    
    return 0;
}