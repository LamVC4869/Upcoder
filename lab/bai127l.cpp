#include <iostream>
#include <vector>

using namespace std;

string Add (string n1, string n2) {
    string res = "";
    int total = 0;
    int i = n1.size() - 1;
    int j = n2.size() - 1;

    while (i >= 0 || j >= 0 || total > 0) {
        int digit1 = (i >= 0) ? n1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j--] - '0' : 0;
        int currentSum = digit1 + digit2 + total;
        res = to_string(currentSum % 10) + res;
        total = currentSum / 10;
    }
    return res;
}

string fibonacci (int n) {
    vector<string> fib;
    fib.push_back("0");
    fib.push_back("1");
    for (int i = 2; i <= n; ++i) fib.push_back(Add(fib[i - 1], fib[i - 2]));
    return fib[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci (n);
    return 0;
}
