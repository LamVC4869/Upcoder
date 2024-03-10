#include <iostream>

using namespace std;

void Xuat_Mang_Xoan_Oc (int a[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int rows, cols;
    cin >> rows >> cols;
    int value = 1;
    int arr[100][100];
    int RowStart = 0, ColStart = 0;
    int RowEnd = rows - 1, ColEnd = cols - 1;
    while (RowStart <= RowEnd && ColStart <= ColEnd) {
        for (int i = ColStart; i <= ColEnd; i++) {
            arr[RowStart][i] = value++;
        }
        RowStart++;
        for (int i = RowStart; i <= RowEnd; i++) {
            arr[i][ColEnd] = value++;
        }
        ColEnd--;
        for (int i = ColEnd; i >= ColStart; i--) {
            arr[RowEnd][i] = value++;
        }
        RowEnd--;
        for (int i = RowEnd; i >= RowStart; i--) {
            arr[i][ColStart] = value++;
        }
        ColStart++;
    }
    Xuat_Mang_Xoan_Oc (arr, rows, cols);
    return 0;
}