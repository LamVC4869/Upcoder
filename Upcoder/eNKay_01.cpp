#include <iostream>

using namespace std;

int main () {
    string number;
    cin >> number;
    if (number[0] == '-') {
        number.erase (0, 1);
    }
    cout << number.length ();
    return 0;
}