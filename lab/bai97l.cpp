#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    string np;
    cin >> np;
    int count0 = 0, count1 = 0;
    for (int i = 0; i < np.length (); i++) {
        if (np[i] == '0') {
            count0++;
        } else if (np[i] == '1') {
            count1++;
        }
    }
    cout << count0 << " " << count1 << endl;
    int count = 0, max = 0;
    for (int i = 0; i < np.length (); i++) {
        if (np[i] == '1') {
            ++count;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
    }
    cout << max;
    return 0;
}