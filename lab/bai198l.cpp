#include <iostream>

using namespace std;

int main () {
    int m, n, k;
    cin >> m >> n >> k;
    int arr[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }
    // pair<int, int> pos[100];
    // int x = 0;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (arr[i][j] == k) {
    //             pos[x++] = make_pair (i, j);
    //         } 
    //     }
    // }
    // for (int k = 0; k < x; k++) {
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (i == pos[k].first || j == pos[k].second) arr[i][j] = 0;
    //         }
    //     }
    // }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == k) {
                for (int x = 0; x < n; x++) arr[i][x] = 0;
                for (int y = 0; y < m; y++) arr[y][j] = 0;
            }
        }
    }
    bool null = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                null = true;
                break;
            }
        }
    }
    if (!null) cout << "Null";
    else {
        for (int i = 0; i < m; i++) {
            bool xuongdong = false;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 0) {
                    cout << arr[i][j] << ' ';
                    xuongdong = true;
                }
            }
            if (xuongdong) cout << endl;
            // if (arr[i][0] != 0) cout << endl;
        }
    }
    return 0;
}