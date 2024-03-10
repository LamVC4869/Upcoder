#include <iostream>

using namespace std;

struct Hocsinh {
    string name;
    unsigned int toan, van;
    double avg;
};

void Input_Output (int n) {
    int count = 0;
        Hocsinh a;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline (cin, a.name);
            cin >> a.toan >> a.van >> a.avg;
            cin.ignore();
            if (a.toan >= 8 && a.van >= 8) {
            count++;
        }
        cout << a.name << " - " << "Toan: " << a.toan << " - " << "Van: " << a.van << " - " << "DiemTB: " << a.avg << endl;
        }
    cout << "So luong HSG: " << count;
}

int main () {
    Hocsinh a;
    int n; cin >> n;
    Input_Output (n);
    return 0;   
}