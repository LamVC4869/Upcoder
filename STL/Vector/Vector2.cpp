#include <iostream>
#include <vector>

using namespace std;

int Sum (vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size (); i++) {
        sum += v[i];
    }
    return sum;
}

int main () {
    int n;
    vector<int> v;
    while (cin >> n) {
        v.push_back (n);
    }
    cout << Sum (v);
    return 0;
}