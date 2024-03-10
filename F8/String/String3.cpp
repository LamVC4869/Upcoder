#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    cout << "Nhap chuoi: ";
    getline (cin, a);

    //chuyen het ki tu thanh chu viet thuong
    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }

    if (a[0] != ' ') {
        a[0] = toupper(a[0]);
    }
    
    for (int j = 0; j < a.length(); j++) {
            if (a[j] == ' ' && a[j + 1] != ' ') {
                a[j + 1] = toupper (a[j + 1]);
            }
        }

    cout << "Ket qua: " << a;
    return 0;
}