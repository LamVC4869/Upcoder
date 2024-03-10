#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    string str[n];
    for (int i = 0; i < n; i++) cin >> str[i];
    int Q;
    cin >> Q;
    string tmp[Q];
    for (int i = 0; i < Q; i++) cin >> tmp[i];
    for (int i = 0; i < Q; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (tmp[i] == str[j]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}