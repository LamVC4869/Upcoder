#include <iostream>
#include <cmath>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i <= sqrt (n); ++i) if (n % i == 0) return false;
    return n > 1;
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int m, M, i = 0;
    cin >> m >> M;
    int *a = new int [M - m];
    for (int j = m; j <= M; j++) if (isPrime (j)) a[i++] = j;
    for (int j = 0; j < i; j++) cout << a[j] << " ";
    delete []a;
    return 0;
}