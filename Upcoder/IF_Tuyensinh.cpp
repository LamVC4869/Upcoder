#include <iostream>

using namespace std;

int main () {
    double diem_chuan, diem_mon_1, diem_mon_2, diem_mon_3, tong_diem;
    char khu_vuc;
    int doi_tuong;
    cin >> diem_chuan >> diem_mon_1 >> diem_mon_2 >> diem_mon_3 >> khu_vuc >> doi_tuong;
    double tong_diem = diem_mon_1 + diem_mon_2 + diem_mon_3;
    switch (khu_vuc) {
        case 'A':
        tong_diem += 2; break;
        case 'B':
        tong_diem += 1; break;
        default:
        tong_diem += 0.5;
    }
    switch (doi_tuong) {
        case 1: tong_diem += 2.5; break;
        case 2: tong_diem += 1.5; break;
        default: tong_diem += 1;
    }
    (tong_diem >= diem_chuan && diem_mon_1 != 0 && diem_mon_2 != 0 && diem_mon_3 != 0) ? cout << "PASS" : cout << "FAIL";
    return 0;
}