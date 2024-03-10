#include <iostream>
#define endl '\n'

using namespace std;

void Print (int dp[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    int dp[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> dp[i][j];
    }
    
    return 0;
}