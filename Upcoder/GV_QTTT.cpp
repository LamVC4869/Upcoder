#include <iostream>
#include <iomanip>

using namespace std;

struct Giang_Vien {
    string name, hoc_vi;
    int years;
    double he_so;
};

double Luong (Giang_Vien a) {
    double res = 0;
    if (a.hoc_vi == "CN") {
        res = a.he_so * 3600;
    } else if (a.hoc_vi == "Ths" || a.hoc_vi == "ThS") {
        res = a.he_so * 4500;
    } else {
        res = a.he_so * 6000;
    }
    return res;
}

void Sort (Giang_Vien a[], int n) {
    for (int k = 0; k < n; k++) {
        for (int j = k + 1; j < n; j++) {
            if (Luong (a[k]) < Luong (a[j])) {
                Giang_Vien temp = a[k];
                a[k] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main () {
    Giang_Vien arr[100];
    for (int i = 0; i < 2; i++) {
        cin >> arr[i].name >> arr[i].years >> arr[i].hoc_vi >> arr[i].he_so;
    }

    for (int j = 0; j < 2; j++) {
        cout << Luong (arr[j]) << endl;
    }
    Sort (arr, 2);
    cout << arr[0].name << endl << arr[0].years << endl << arr[0].hoc_vi << endl << fixed << setprecision (1) << arr[0].he_so;

    return 0;
}