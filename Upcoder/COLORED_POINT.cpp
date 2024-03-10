#include <iostream>

using namespace std;

struct COLORED_POINT {
    int x, y;
    string colorId;
    friend istream& operator >> (istream &is, COLORED_POINT &point) {
        is >> point.x >> point.y >> point.colorId;
        return is;
    }
    friend ostream& operator << (ostream &os, COLORED_POINT point) {
        os << "(" << point.x << ',' << point.y << ",#" << point.colorId << ")";
        return os;
    }
    int Count_5DC3A8 (COLORED_POINT* &arr, int size) {
        int cnt = 0;
        for (int i = 0; i < size; i++) if (arr[i].colorId == "5DC3A8") cnt++;
        return cnt;
    }
    void Change_color () {
        if (this->x > this->y) this->colorId = "1F00F3";
    }
};

int main () {
    int n; cin >> n;
    COLORED_POINT *a = new COLORED_POINT [n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl << a->Count_5DC3A8 (a, n) << endl;
    for (int i = 0; i < n; i++) {
        a[i].Change_color ();
        cout << a[i] << ' ';
    }
    delete []a;
    return 0;
}