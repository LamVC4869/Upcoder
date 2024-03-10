#include <iostream>
#define endl '\n'

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n, q, cnt;
    cin >> n >> q;
    cnt = n;
    string str[n]; for (string &i : str) cin >> i;
    char kt[q]; for (char &c : kt) cin >> c;
    int duyet[100];
     for (int j = 0; j < q; j++) {
        if (duyet[kt[j] - 97] == 1) {
            cout << cnt << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (str[i].find(kt[j]) != -1) {
                cnt--;
                str[i] = "";
            }
            duyet[kt[j] - 97] = 1;
        }
        cout << cnt << endl;
    }
    return 0;
}