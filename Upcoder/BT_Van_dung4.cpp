#include <iostream>

using namespace std;

struct DuongThang {
    int a, b;
};

bool SongSong (DuongThang &d1, DuongThang &d2) {
    return d1.a == d2.a && d1.b != d2.b;
}

int main () {
    int n; cin >> n;
    DuongThang a[n];
    for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (SongSong (a[i], a[j])) cnt++;
        }
    }
    cout << cnt;
    return 0;
}