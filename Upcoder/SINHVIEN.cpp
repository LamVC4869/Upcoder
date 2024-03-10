#include <iostream>

using namespace std;

struct SINHVIEN {
    string HoTen;
    int NamSinh;
    double DTB;
};

int main () {
    SINHVIEN arr[1000];
    int i = 0;
    while (cin >> arr[i].HoTen) {
        cin >> arr[i].NamSinh >> arr[i].DTB;
        i++;
    }

    double max = - 1.00;
    for (int j = 0; j < i; j++) {
        if (arr[j].DTB > max) {
            max = arr[j].DTB;
        }
    }

    int count = 1;
    cout << "Diem cao nhat lop:" << endl;
    for (int j = 0; j < i; j++) {
        if (arr[j].DTB == max) {
            cout << "#" << count << endl;
            count++;
            cout << arr[j].HoTen << " " << arr[j].NamSinh << " " << arr[j].DTB << endl;
        }
    }

    for (int j = 0; j < i; j++) {
        if (arr[j].DTB <= max) max = arr[j].DTB;
    }

    int res = 1;
    cout << "Diem thap nhat lop:" << endl;
    for (int j = 0; j < i; j++) {
        if (arr[j].DTB == max) {
            cout << "#" << res << endl;
            res++;
            cout << arr[j].HoTen << " " << arr[j].NamSinh << " " << arr[j].DTB << endl;
        }
    }

    return 0;
}