#include <iostream>

using namespace std;

struct sach {
    string code, name;
    int so_to_giay;
};

void Sap_xep_sach (sach a[], int so_luong_sach) {
    for (int i = so_luong_sach - 1; i > 0; i--) {
        for (int j = 0; j < so_luong_sach - 1; j++) {
            if (a[j].so_to_giay > a[j + 1].so_to_giay) {
                sach temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main () {
    sach arr[1000];
    int so_luong_sach;
    cin >> so_luong_sach;
    for (int i = 0; i < so_luong_sach; i++) {
        cin >> arr[i].code >> arr[i].name >> arr[i].so_to_giay;
    }
    Sap_xep_sach (arr, so_luong_sach);
    for (int i = 0; i < so_luong_sach; i++) {
        cout << arr[i].code << "-" << arr[i].name << "-" << arr[i].so_to_giay << endl;
    }
    return 0;
}