#include <iostream>

using namespace std;

int Dayofmonth[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool ktNamNhuan (int years) {
    return (years % 400 == 0) || (years % 4 == 0 && years % 100 != 0);
}

void Print_Day (int year, int month) {
    Dayofmonth[2] = !ktNamNhuan (year) ? 28 : 29;
    cout << Dayofmonth[month];
}

int main () {
    int years, months;
    cin >> years >> months;
    Print_Day (years, months);
    return 0;
}