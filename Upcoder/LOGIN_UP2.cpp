#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n; cin >> n;
    string str = "upcoder";
    int count = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        string a, res = "";
        cin >> a;
        int pos = 0;
        for (int i = 0; i < str.length (); i++) {
            for (int j = pos; j < a.length (); j++) {
                if (str[i] == a[j]) {
                    res += a[j];
                    pos = j;
                    break;
                }
            }
        }
        if (res == str) {
            v.push_back (i);
            count++;
        }
    }
    cout << count << endl;
    for (auto it = v.begin (); it != v.end (); it++) cout << *it << " ";
    return 0;
}