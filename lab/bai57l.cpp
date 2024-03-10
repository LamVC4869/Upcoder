#include <iostream>
#include <cmath>

using namespace std;

struct point {
    float x, y;
};

float Distance (point a, point b) {
    return sqrt (pow((a.x - b.x), 2) + pow ((a.y - b.y), 2));
}

int main () {
    point a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    
    cout << roundf (Distance (a, b) * 100) / 100;

    return 0;
}