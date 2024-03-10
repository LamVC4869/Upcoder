#include <iostream>

using namespace std;

int DayOfMonth[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap_Year (int years) {
    return (years % 400 == 0) || (years % 4 == 0 && years % 100 != 0);
}

int main () {
    int days, months, years;
    cin >> days >> months >> years;
    DayOfMonth[2] = isLeap_Year (years) ? 29 : 28;
    if (days > DayOfMonth[months] || days <= 0 || months <= 0 || months > 12 || years <= 0) {
        cout << "KHONG HOP LE";
    } else {
        if (months < 12) {
            if (days == DayOfMonth[months]) {
                days = 1;
                months += 1;
            } else {
                days += 1;
            }
        } else {
            if (days == DayOfMonth[months]) {
                days = 1;
                months = 1;
                years += 1;
            } else {
                days += 1;
            }
        }
        if (days < 10) {
            cout << 0 << days << " ";
        } else {
            cout << days << " ";
        }
        if (months < 10) {
            cout << 0 << months << " ";
        } else {
            cout << months << " ";
        }
        cout << years;
    }
    return 0;
}