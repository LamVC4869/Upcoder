#include <iostream>
#include <algorithm>

using namespace std;

long long f[10001];

void solve (long long f[]) {
    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0) f[i]++;
        }
    }
}

bool kt (int x, int y) {
    return f[x] < f[y] || f[x] == f[y] && x < y;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    solve (f);
    int n; cin >> n;
    int a[n], b[10000], cnt = 0;
    long long res = 0;
    for (int &i : a) {
        cin >> i;
        if (f[i] > res) res = f[i];
    }
    for (int i = 0; i < n; i++) if (f[a[i]] == res) b[cnt++] = a[i];
    sort (a, a + n, kt);
    for (int i = 0; i < cnt; i++) cout << b[i] << ' ';
    cout << '\n';
    for (int i : a) cout << i << ' '; 
    return 0;
}