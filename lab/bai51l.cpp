#include <iostream>
#include <string>

using namespace std;

int main () {
    string a, b;
    getline (cin, a);
    getline (cin, b);

    if (a > b) {
        cout << a;
    } else if (a < b) {
        cout << b;
    } else {
        cout << "Hai xau bang nhau";
    }

    return 0;
}