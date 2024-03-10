#include <iostream>

using namespace std;

struct hop_sua {
    string Nhan_hieu, Han_Su_Dung;
    double Trong_luong;
};

void Xuat_Mang (hop_sua a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "HOPSUA #" << i + 1 << ": " << a[i].Nhan_hieu << " " << a[i].Trong_luong << " " << a[i].Han_Su_Dung << endl;
    }
}

bool Kt_Het_Han (hop_sua a, string c) {
    string years = a.Han_Su_Dung.substr(0, 4);
    string months = a.Han_Su_Dung.substr (5, 2);
    string days = a.Han_Su_Dung.substr (8, 2);
    int year = stoi (years);
    int month = stoi (months);
    int day = stoi (days);
    string years_hsd = c.substr(0, 4);
    string months_hsd = c.substr (5, 2);
    string days_hsd = c.substr (8, 2);
    int year_hsd = stoi (years_hsd);
    int month_hsd = stoi (months_hsd);
    int day_hsd = stoi (days_hsd);
    if (year < year_hsd) {
        return true;
    } else if (year == year_hsd) {
        if (month < month_hsd) {
            return true;
        } else if (month == month_hsd) {
            if (day < day_hsd) {
                return true;
            }
        }
    }
    return false;
}

int main () {
    hop_sua arr[1000];
    int so_luong; 
    cin >> so_luong;
    cin.ignore();
        for (int i = 0; i < so_luong; i++) {
        cin >> arr[i].Nhan_hieu;
        cin >> arr[i].Trong_luong;
        cin.ignore();
        getline(cin, arr[i].Han_Su_Dung);
    }
    string date_x;
    getline (cin, date_x);

    Xuat_Mang (arr, so_luong);
    int count = 0;
    for (int i = 0; i < so_luong; i++) {
        if (Kt_Het_Han (arr[i], date_x)) {
            count++;
        }
    }
    cout << count << endl;

    double max = arr[0].Trong_luong;
    for (int i = 1; i < so_luong; i++) {
        if (arr[i].Trong_luong > max) {
            max = arr[i].Trong_luong;
        }
    }

    for (int i = 0; i < so_luong; i++) {
        if (arr[i].Trong_luong == max) {
            cout << arr[i].Nhan_hieu << " " << arr[i].Trong_luong;
            break;
        }
    }

    return 0;
}