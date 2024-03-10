#include <iostream>
#include <string>

using namespace std;

string reverseString(string a) {
    for (int i = 0; i < a.length() * 0.5; i++) {
        char c = a[i];
        a[i] = a[a.length() - i - 1];
        a[a.length() - i - 1] = c;
    }
    return a;
}

bool Check(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    string a;
    getline(cin, a);

    for (int i = 0; i < a.length(); ) {
        if (a[i] == ' ' || !Check(a[i])) {
            a.erase(i, 1);
        } else {
            i++;
        }
    }

    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }

    reverseString(a) == a ? cout << "YES" : cout << "NO";

    return 0;
}
