#include <iostream>

using namespace std;

int main () {
    int ngayDen, ngayDi;
    cin >> ngayDen >> ngayDi;
    
    if (ngayDen < 1 || ngayDi > 7 || ngayDi < 1 || ngayDen > 7) {
        cout << "NHAP SAI";
        return 0;
    }
    long long phi = 0;
    if (ngayDen < ngayDi) {
        for (int i = ngayDen; i < ngayDi; i++) {
            phi += (i == 1) ? 400000 : 300000;
        }
    } else {
        for (int i = ngayDen; i <= 7; i++) {
            phi += (i == 1) ? 400000 : 300000;
        }
        if (ngayDi > 1) {
            for (int i = 1; i < ngayDi; i++) {
                phi += (i == 1) ? 400000 : 300000;
            }
        }
    }
    cout << phi;
    return 0;
}
