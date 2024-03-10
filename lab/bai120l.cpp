#include <iostream>
#include <vector>
#include <string>

#define ull unsigned long long

using namespace std;

vector<string> v;

string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int x = (i >= 0) ? (num1[i--] - '0') : 0;
        int y = (j >= 0) ? (num2[j--] - '0') : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        result = char('0' + sum % 10) + result;
    }

    return result;
}

string Fibonacci(ull n) {
    if (n < 2) return "1";
    if (!v[n].empty()) return v[n];
    v[n] = addStrings(Fibonacci(n - 1), Fibonacci(n - 2));
    return v[n];
}

int main() {
    ull n;
    cin >> n;
    v.resize(n + 1, "");

    cout << Fibonacci(n - 1) << endl;

    return 0;
}
