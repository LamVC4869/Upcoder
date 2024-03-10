#include <iostream>
#include <iomanip>

using namespace std;

struct Cow {
  int code;
  string name, dob, gioi_tinh;
  double weight;  
};

bool BoDatChuan (Cow a) {
    return a.weight > 20;
}

void Print_Infor_Cow (Cow a) {
    string s = a.dob.substr (0, 2) + "/" + a.dob.substr (2, 2) + "/" + a.dob.substr (4, 4);
    cout << "[BoSua] = ";
    cout << "\"Mã Bò: " << a.code << "\",";
    cout << "\"Tên Bò: " << a.name << "\",";
    cout << "\"Ngày Sinh: "<< s <<"\",";
    cout << "\"Giới tính: " << a.gioi_tinh << "\",";
    cout << "\"Cân nặng: " << fixed << setprecision (1) << a.weight << "kg\"" << endl;
}

int main () {
    int n; cin >> n;

    Cow arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].code >> arr[i].name >> arr[i].dob >> arr[i].gioi_tinh >> arr[i].weight;
    }

    for (int i = 0; i < n; i++) {
        if (BoDatChuan (arr[i])) {
            Print_Infor_Cow (arr[i]);
        }
    }

    return 0;
}