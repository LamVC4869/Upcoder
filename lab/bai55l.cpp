#include <iostream>
#include <string>

using namespace std;

void Output (string a) {
    int pos;
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            pos = i;
            break;
        }
    }

    for (int j = 0; j < pos; j++) {
        if (a[j] >= 'A' && a[j] <= 'Z') {
            cout << (char)(a[j] + 32);
        }
    }

    for (int k = pos; k < a.length(); k++) {
        cout << a[k];
    }

}

int main () {
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline (cin, str);
        Output (str);
        cout << "\n";
    }
    return 0;
}