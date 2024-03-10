#include <iostream>

using namespace std;

int main () {
    char a = 'a', z = 'z';
    int arr[100];
    for (int i = a; i <= z; i++) {
        arr[i] = 0;
    }
    char c;
    while (cin >> c) {
        arr[(int)c]++;
    }
    for (int i = a; i <= z; i++) {
        if (arr[i] != 0) {
            cout << (char) i << ":" << arr[i] << endl;
        }
    }
    return 0;
}