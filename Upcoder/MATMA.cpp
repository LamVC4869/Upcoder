#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string inp, demo; cin >> inp;
    stringstream s (inp);
    vector<string> t;
    while (getline (s, demo, '#')) t.push_back (demo);
    int n = stoi (t[0]);
    int k = stoi (t[1]);
    string str[n];
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        stringstream ss (str[i]);
        string tmp;
        vector<string> v;
        while (getline (ss, tmp, '#')) v.push_back (tmp);
        int b = stoi (v[1]);
        arr[i] = stoi (v[b + 2]);
    }
    for (int i = 0; i < n; i++) cout << alphabet[(arr[i] - k - 1 + 26) % 26];
    return 0;
}