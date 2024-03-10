#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> b;
    int a[1001];
    for (int i = 0; i < n; i++) cin >> a[i];
    int count = 0;
    for (int i = a[0]; i < a[n - 1]; i++) {
        if (i != a[count]) b.push_back (i);
        else count++;
    }
    if (b.size ()) {
        cout << "Yes" << endl;
        for (int i : b) cout << i << " ";
    } else {
        cout << "No";
    }
    return 0;
}