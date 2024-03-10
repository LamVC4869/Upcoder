#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Circle {
    Point temp;
    unsigned int r;
};

double Distance (Circle a, Circle b) {
    return sqrt (pow ((a.temp.x - b.temp.x), 2) + pow ((a.temp.y - b.temp.y), 2));
}

bool Intersect (Circle a, Circle b) {
    int R1 = a.r - b.r;
    int R2 = a.r + b.r;
    return Distance (a, b) > abs (R1) && Distance (a, b) < abs (R2);
}

int main () {
    Circle arr[100];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].temp.x >> arr[i].temp.y >> arr[i].r;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Intersect (arr[i], arr[j])) count++;
        }
    }

    cout << count;

    return 0;
}