#include <iostream>

using namespace std;

long long T[]={0, 1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156, 1223, 2446, 2489, 4789, 5789, 11578, 12356, 12247, 24449, 48889, 77789, 155578, 111356, 122227, 244445, 48889, 77789, 155578, 111356, 122227, 244445};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    long long n; cin >> n;
    if (n <= 25) cout << T[n];
    else cout << T[30 + n % 6];
    return 0;
}