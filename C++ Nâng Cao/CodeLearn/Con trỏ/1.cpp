#include <iostream>

using namespace std;

int main () {
    int a = 1;
    int *p = &a;
    *p = 7;
    cout << "Value of a: " << a << endl;
    return 0;
}