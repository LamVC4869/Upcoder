#include <iostream>

using namespace std;

const int total[] = {9, 1, 4, 9, 7, 7, 9, 4, 1};

int main () {
    string str; cin >> str;
    long long value = 0;
    for (char i : str) value = (value * 10 + i - '0') % 9;
    cout << total[value];
    return 0;
}