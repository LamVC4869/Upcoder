#include <iostream>
#include <string>

using namespace std;

int main () {
    string str;
    cout << "Nhap chuoi: ";
    getline (cin, str);

    // xoa khoang trang o dau chuoi
    while (str[0] == ' ') {
        str.erase(0, 1);
    }

    //xoa khoang trang o cuoi chuoi
    while (str[str.size() - 1] == ' ') {
        str.erase(str.size() - 1, 1);
    }

    cout << "Ket qua: " << str;
    return 0;
}