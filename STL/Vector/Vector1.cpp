#include <iostream>
#include <vector>

using namespace std;

vector<int> initializeVector(int n)
{
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    return a;
}

int main () {
    int n; cin >> n;
    vector<int> b = initializeVector (n);
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}