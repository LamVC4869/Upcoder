#include <iostream>

using namespace std;

void chuyenCoSo (long soHe10, int heCoSoMoi) {
    string res = "";
    while (soHe10) {
        int element = soHe10 % heCoSoMoi;
        res += (element < 10) ? (element + '0') : char ('A' + element - 10);
        soHe10 /= heCoSoMoi;
    }
    for (int i = res.length () - 1; i > -1; i--) cout << res[i];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long soHe10;
    int heCoSoMoi;
    cin >> soHe10 >> heCoSoMoi;
    if (heCoSoMoi == 0) heCoSoMoi = 2;
    else if (heCoSoMoi == 1) heCoSoMoi = 8;
    else if (heCoSoMoi = 2) heCoSoMoi = 16;
    chuyenCoSo (soHe10, heCoSoMoi);
    return 0;
}