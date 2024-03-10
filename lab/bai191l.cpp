#include <iostream>
#include <cmath>

using namespace std;

struct Oxy {
    int x, y;
    friend istream& operator >> (istream &is, Oxy &point) {
        is >> point.x >> point.y;
        return is;
    }
    friend ostream& operator << (ostream &os, Oxy point) {
        os << '(' << point.x << ", " << point.y << ')';
        return os;
    }
    double operator - (Oxy another) {
        return sqrt (pow (another.x - this->x, 2) + pow (another.y - this->y, 2));
    }
    bool operator < (Oxy another) {
        return (this->x < another.x) || (this->x == another.x && this->y < another.y);
    }
    bool operator == (Oxy another) {
        return (this->x == another.x && this->y == another.y);
    }
};

struct Oxyz {
    Oxy oxy;
    int z;
    friend istream& operator >> (istream &is, Oxyz &oxyz) {
        is >> oxyz.oxy >> oxyz.z;
        return is;
    }
    friend ostream& operator << (ostream &os, Oxyz oxyz) {
        os << '(' << oxyz.oxy.x << ", " << oxyz.oxy.y << ", " << oxyz.z << ')';
        return os;
    }
    double operator - (Oxyz another) {
        return sqrt (pow (another.z - this->z, 2) + pow (another.oxy.y - this->oxy.y, 2) + pow (another.oxy.x - this->oxy.x, 2));
    }
    bool operator < (Oxyz another) {
        return (this->oxy < another.oxy) || (this->oxy == another.oxy && this->z < another.z);
    }
};

template <typename T>
struct Arr {
    int size = 0;
    T arr[1000];
    friend istream& operator >> (istream &is, Arr<T> &a) {
        T tmp; is >> tmp;
        a.arr[a.size++] = tmp;
        return is;
    }
    friend ostream& operator << (ostream &os, Arr<T> a) {
        for (int i = 0; i < a.size; i++) {
            os << a.arr[i] << ' ';
        }
        return os << endl;
    }
    double d_max () {
        double max = arr[0] - arr[1];
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] - arr[j] > max) max = arr[i] - arr[j];
            }
        }
        return max;
    }
    void sort () {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (!(arr[i] < arr[j])) {
                    swap (arr[i], arr[j]);
                }
            }
        }
    }
    void r_sort () {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if ((arr[i] < arr[j])) {
                    swap (arr[i], arr[j]);
                }
            }
        }
    }
};

int main () {
    Arr<Oxy> a;
    Arr<Oxyz> b;
    string str;
    while (cin >> str) {
        if (str == "Oxy") cin >> a;
        else if (str == "Oxyz") cin >> b;
    }
    a.sort ();
    cout << a;
    b.r_sort ();
    cout << b;
    cout << roundf (a.d_max () * 1000) / 1000 << endl;
    cout << roundf (b.d_max () * 1000) / 1000;
    return 0;
}