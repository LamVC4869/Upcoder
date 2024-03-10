#include <iostream>

using namespace std;

int main () {
    int a; cin >> a;
    cout << "a is an " << (a & 1 ? "odd number" : "even number");
    return 0;
}