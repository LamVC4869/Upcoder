#include <iostream>

using namespace std;

string Add (string a, string b) {
    string result = "";
    int nho = 0;
    while (a.length () < b.length ()) a = "0" + a;
    while (a.length () > b.length ()) b = "0" + b;
    int length = a.length () - 1;
    for (int i = length; i > -1; i--) {
        int number = (a[i] - '0') + (b[i] - '0') + nho;
        result = char (number % 10 + '0') + result;
        nho = number / 10;
    }
    if (nho) result = char (nho + '0') + result;
    return result;
}

int main () {
    string a, b;
    cin >> a >> b;
    cout << Add (a, b);
    return 0;
}