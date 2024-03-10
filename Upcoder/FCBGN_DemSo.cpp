#include <iostream>

using namespace std;

int main () {
    int n, dem1 = 0, dem2 = 0; cin >> n;
    while (n--) {
        string digit;
        cin >> digit;
        if (digit[0] == '-') dem1++;
        else if (digit[0] == '0') continue;
        else dem2++;
    }
    cout << dem1 << " " << dem2;
    return 0;
}