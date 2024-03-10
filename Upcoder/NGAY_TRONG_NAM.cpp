#include <iostream>

using namespace std;

int DayOfMonth[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Nam_Nhuan (int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main () {
    int ngay, thang, nam;
    cin >> ngay >> thang >> nam;
    DayOfMonth[2] = Nam_Nhuan (nam) ? 29 : 28;
    int tongngay = 0;
    for (int i = 1; i < thang; i++) tongngay += DayOfMonth[i];
    tongngay += ngay;
    int n = nam + ((nam - 1) / 4) - ((nam - 1) / 100) + ((nam - 1) / 400) + tongngay - 1;
    int res = n % 7;
    switch (res) {
        case 0:
        cout << "Chu Nhat"; break;
        case 1:
        cout << "Thu Hai"; break;
        case 2:
        cout << "Thu Ba"; break;
        case 3:
        cout << "Thu Tu"; break;
        case 4:
        cout << "Thu Nam"; break;
        case 5:
        cout << "Thu Sau"; break;
        default:
        cout << "Thu Bay";
    }
    return 0;
}