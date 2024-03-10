#include <iostream>
#include <iomanip>

using namespace std;

struct SinhVien {
    char* hoTen;
    int namSinh;
    float diem[3];
};

void Nhap (SinhVien &a) {
    a.hoTen = new char [30];
    cin.ignore ();
    cin.getline (a.hoTen, 30);
    cin >> a.namSinh;
    for (int j = 0; j < 3; j++) cin >> a.diem[j];
}

void Sort (SinhVien a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            float tong1 = a[i].diem[1] + a[i].diem[2] + a[i].diem[0];
            float tong2 = a[j].diem[0] + a[j].diem[1] + a[j].diem[2];
            if (tong1 < tong2) swap (a[i], a[j]);
        }
    }
}

void Xuat (SinhVien a[], int size) {
    for (int i = 0; i < size; i++) {
        float tong = (a[i].diem[0] + a[i].diem[1] + a[i].diem[2]) / 3;
        cout << i + 1 << " - " << a[i].hoTen << " - " << a[i].namSinh << " - " << fixed << tong << endl;
    }
}

int main () {
    cout.precision (2);
    int n; cin >> n;
    SinhVien arr[n];
    for (int i = 0; i < n; i++) Nhap (arr[i]);
    Sort (arr, n);
    Xuat (arr, n);
    for (int i = 0; i < n; i++) delete []arr[i].hoTen;
}