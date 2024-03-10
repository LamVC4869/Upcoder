#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1415926535897;

int main () {
    double h, alpha;
    cin >> h >> alpha;
    double alpha_radian = alpha * pi / 180;
    cout << (double) cos (alpha_radian) * h;
    return 0;
}