// #include <iostream>

// using namespace std;

// int main () {
//     int n, m;
//     cin >> n >> m;
//     int cd[n], pos[n];
//     for (int i = 1; i <= n; i++) cd[i] = pos[i] = i;
//     for (int i = 1; i <= m; i++) {
//         int digit; cin >> digit;
//         for (int i = pos[digit]; i > 1; i--) {
//             cd[i] = cd[i - 1];
//             pos[cd[i]] = i;
//         }
//         cd[1] = digit;
//         pos[digit] = 1;
//     }
//     for (int i = 1; i <= n; i++) cout << cd[i] << " ";
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int cd[m];
    bool duyet[n] = {};
    vector<int> v;
    for (int i = m; i > 0; i--) cin >> cd[i];
    for (int i = 1; i <= m; i++) {
        if (!duyet[cd[i]]) {
            v.push_back (cd[i]);
            duyet[cd[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) if (!duyet[i]) v.push_back (i);
    for (auto x : v) cout << x << ' ';
    return 0;
}