#include <iostream>

using namespace std;

struct Sach {
    string code, name;
    int quantity;
};

void Find (string ma_sach, Sach arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ma_sach == arr[i].code) {
            count++;
            cout << i;
            break;
        }
    }
    if (count == 0) cout << -1;
}

int main () {
    string ma_sach;
    cin >> ma_sach;
    int so_luong_sach;
    cin >> so_luong_sach;
    cin.ignore ();
    Sach arr[100];
    for (int i= 0; i < so_luong_sach; i++) {
        cin >> arr[i].code >> arr[i].name >> arr[i].quantity;
        cin.ignore ();
    }

    Find (ma_sach, arr, so_luong_sach);

    return 0;
}