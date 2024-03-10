#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
    int n; cin >> n;
    string str[n];
    int res[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        stringstream ss(str[i]);
        string tmp;
        vector<string> v;
        while (getline (ss, tmp, '-')) v.push_back (tmp);
        res[i] += stoi (v[0]);
        for (int j = 1; j < v.size (); j++) res[i] -= stoi (v[j]);
    }
    for (int i = 0; i < n; i++) cout << res[i] << endl;
    return 0;
}