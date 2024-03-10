#include <iostream>

using namespace std;

int main () {
    char top[6], bottom [6];
    cin >> top >> bottom;
    string res;
    if (top[0] != 6 && top[1] != 7) {
        res = "Khong tim thay";
    }
    if (top[4] == '1') {
        if (top[3] == 'D') {
            res = "Huyen Chau Phu";
        } else if (top[3] == 'C') {
            res = "Huyen Chau Thanh";
        } else if (top[3] == 'B') {
            res = "Thanh Pho Long Xuyen";
        } else if (top[3] == 'E') {
            res = "Thanh Pho Chau Doc";
        } else if (top[3] == 'F') {
            res = "Huyen Tinh Bien";
        } else {
            res = "Khong tim thay";
        }
    }

    if (top[3] == 'B' && top[4] == '2' || top[3] == 'A' && top[4] == 'A') {
        res = "Thanh Pho Long Xuyen";
    } else if (top[3] == 'A') {
        if (top[4] == 'C') {
            res = "Huyen Chau Phu";
        } else if (top[4] == 'B') {
            res = "Huyen Chau Thanh";
        } else if (top[4] == 'E') {
            res = "Thanh Pho Chau Doc";
        } else if (top[4] == 'F') {
            res = "Huyen Tinh Bien";
        } else {
            res = "Khong tim thay";
        }
    }

    cout << res << endl;
    cout << top << endl << bottom;

    
    return 0;
}