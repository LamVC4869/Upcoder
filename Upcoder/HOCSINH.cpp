#include <iostream>
#include <iomanip>

using namespace std;

struct hoc_sinh {
    string name;
    int toan, van;
    double dtb;
};

void Xuat_mang (hoc_sinh arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " - Toan: " << arr[i].toan << " - Van: " << arr[i].van << " - DiemTB: " << fixed << setprecision (2) << arr[i].dtb << endl;
    }
}

bool KtHSG (hoc_sinh a) {
    return a.toan > 8 && a.van > 8;
}

int main () {
    int so_luong; cin >> so_luong;
    hoc_sinh arr[1000];
    for (int i = 0; i < so_luong; i++) {
        cin.ignore ();
        getline (cin, arr[i].name);
        cin >> arr[i].toan >> arr[i].van >> arr[i].dtb;
    }
    Xuat_mang (arr, so_luong);
    int count = 0;
    for (int i =0; i < so_luong; i++) {
        if (KtHSG (arr[i])) count++;
    }
    cout << count;
    return 0;
}