#include <iostream>

using namespace std;

#define ull unsigned long long

int main () {
    ull k, pos, i;
    cin >> k;
    pos = i = 1;
    while (pos < k) pos += i++;
    pos == k ? cout << 1 : cout << 0;
    return 0;
}