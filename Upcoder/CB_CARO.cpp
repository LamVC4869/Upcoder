#include <iostream>

using namespace std;

bool win (char a[][3]) {
    for (int i = 0; i < 3; i++) for (int j = 1; j < 3; j++) if (a[i][j - 1] != a[i][j]) return false;
    for (int i = 0; i < 3; i++) for (int j = 1; j < 3; j++) if (a[j - 1][i] != a[j][i]) return false;
    for (int i = 1; i < 3; i++) if (a[i - 1][i - 1] != a[i][i]) return false;
    for (int i = 1; i < 3; i++) if (a[2 - i - 1][i - 1] != a[2 - i][i]) return false;
    return true;
}

int main () {
    long long n; cin >> n;
    int i = 1;
    while (n--) {
        char caro[3][3];
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> caro[i][j];
        win (caro) ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}