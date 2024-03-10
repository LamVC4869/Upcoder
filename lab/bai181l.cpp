#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n; cin >> n;
    cin.ignore ();
    while (n--) {
        string str, tmp;
        getline (cin, str);
        for (char &i : str) if (isdigit (i)) i = ' ';
        stringstream ss (str);
        vector<string> v;
        while (ss >> tmp) if (!tmp.empty ()) v.push_back (tmp);
        int cnt[v.size ()] = {0};
        for (int i = 0; i < v.size (); i++) {
            cnt[i] = 1;
            for (int j = i + 1; j < v.size (); j++) {
                if (v[i].size () == v[j].size ()) cnt[i]++;
                if (v[i].size () != v[j].size ()) break;
            }
        }
        cout << *max_element(cnt, cnt + v.size ()) << endl;
    }
    return 0;
}