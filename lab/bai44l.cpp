#include <iostream>
#include <string>

using namespace std;

int main () {
    string a; getline (cin, a);
    char c; cin >> c;
    a += c;
    cout << a;
    return 0;
}