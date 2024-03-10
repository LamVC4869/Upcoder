#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct HonKai {
    string name;
    int speed;
    friend istream& operator >> (istream &is, HonKai &a) {
        is >> a.name >> a.speed;
        return is;
    }
    friend ostream& operator << (ostream &os, HonKai a) {
        os << a.name;
        return os << endl;
    } 
};

void sort (HonKai arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i].speed <= arr[i].speed) swap (arr[i], arr[j]);
            }
        }
    }

int main () {
    int n; cin >> n;
    HonKai a[n]; for (HonKai &i : a) cin >> i;
    sort (a, n);
    for (HonKai i : a) cout << i;
    return 0;
}