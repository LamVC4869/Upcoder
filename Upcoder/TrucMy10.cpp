#include <iostream>

using namespace std;

int main () {
    int n, count_1 = 0, count_2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string number;
        cin >> number;
        if (number[0] == '-') {
            count_1++;
        } else if (number[0] != '0') {
            count_2++;
        }
    }
    cout << count_1 << " " << count_2;
    return 0;
}