#include <iostream>

using namespace std;

struct hcn {
    float chieudai, chieurong;
};

float chuvi (hcn a) {
    return (a.chieudai + a.chieurong) * 2;
}

bool sosanh (hcn a, hcn b) {
    return chuvi (a) < chuvi (b);
}

int main () {
    hcn a, b;
    cin >> a.chieudai >> a.chieurong;
    cin >> b.chieudai >> b.chieurong;

    cout << "[HCN] " << a.chieudai << "," << a.chieurong << endl;
    cout << "[HCN] " << b.chieudai << "," << b.chieurong << endl;

    if (sosanh (a, b)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
