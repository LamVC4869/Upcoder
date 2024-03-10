#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, maxHeight;
    cin >> n;
    vector<int> h(n);
    for (int &i : h) 
        cin >> i;
    cin >> maxHeight;

    sort(h.begin(), h.end());
    if (maxHeight < h.back()) {
        cout << -1;
        return 0;
    }

    int x = 0, y = n - 1, boats = 0;
    while (x <= y) {
        if (h[y] == maxHeight) {
            boats++;
            y--;
        } else if (h[y] + h[x] <= maxHeight) {
            boats++;
            y--;
            x++;
        } else if (h[y] + h[x] > maxHeight) {
            boats++;
            y--;
        }
    }

    cout << boats;
    return 0;
}
