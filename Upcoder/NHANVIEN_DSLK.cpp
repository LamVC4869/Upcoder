#include <iostream>

using namespace std;

typedef unsigned long long ull;
#define FOR(i, a, b) for (int i = a; i < b; i++)
const ull MAX = 1000;

struct Nhan_Vien {
    string code, name;
    ull wage;
};

void Danh_Sach_Nhan_Vien (Nhan_Vien a[], ull n) {
    FOR(i, 0, n) {
        cout << "{" << a[i].name << ", " << a[i].code << ", " << a[i].wage << "}" << endl;
    }
}

ull Tong_Luong (Nhan_Vien a[], ull n) {
    ull sum = 0;
    FOR(i, 0, n) {
        sum += a[i].wage;
    }
    return sum;
}

void Nhan_Vien_Luong_Max (Nhan_Vien a[], ull n) {
    ull max = a[0].wage;
    FOR(i, 1, n) {
        if (a[i].wage > max) max = a[i].wage;
    }
    FOR(i, 0, n) {
        if (a[i].wage == max) {
            cout << a[i].name;
            break;
        }
    }
    cout << endl;
}

void Sort_Luong_Nhan_Vien (Nhan_Vien a[], ull n) {
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            if (a[i].wage < a[j].wage) {
                Nhan_Vien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main () {
    Nhan_Vien arr[MAX];
    ull so_luong; cin >> so_luong;
    FOR(i, 0, so_luong) {
        cin >> arr[i].code;
        cin.ignore ();
        getline (cin, arr[i].name);
        cin >> arr[i].wage;
    }

    Danh_Sach_Nhan_Vien (arr, so_luong);
    Nhan_Vien_Luong_Max (arr, so_luong);
    cout << Tong_Luong (arr, so_luong) << endl;
    Sort_Luong_Nhan_Vien (arr, so_luong);
    cout << "{" << arr[so_luong - 1].name << ", " << arr[so_luong - 1].code << ", " << arr[so_luong - 1].wage << "}";
    return 0;
}