#include <iostream>
typedef unsigned long long ull;

using namespace std;

int soNgay[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear (int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

struct day {
    int ngay, thang, nam;
    friend istream& operator >> (istream &is, day &d) {
        char c;
        is >> d.ngay >> c >> d.thang >> c >> d.nam;
        return is;
    }
};

int soNam (int y) {
    return (leapYear (y)) ? 366 : 365;
}

bool ktHopLe (day d) {
    soNgay[2] = (leapYear (d.nam)) ? 29 : 28;
    if (d.ngay > soNgay[d.thang] || d.ngay <= 0 || d.thang <= 0 || d.thang > 12 || d.nam <= 0) return false;
    return true;
}

int tongNgaythang (day d) {
    int res = d.ngay;
    for (int i = 1; i < d.thang; i++) res += soNgay[i];
    return res - 1;
}

int main () {
    day d; cin >> d;
    if (!ktHopLe (d)) {
        cout << "None";
        return 0;
    }
    ull res = tongNgaythang (d);
    for (int i = 1; i < d.nam; i++) res += soNam (i);
    cout << res;
    return 0;
}