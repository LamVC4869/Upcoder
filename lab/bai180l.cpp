#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int cnt[1000010] = {0};

int main () {
    vector<int> v;
    set<int> s;
    int index;
    while (cin >> index) v.push_back (index);
    bool duyet[v.size ()] = {};
    for (int i = 0; i < v.size () - 1; i++) {
        for (int j = i + 1; j < v.size (); j++) {
            if (v[i] == v[j]) {
                cnt[v[i]]++;
                duyet[j] = true;
            }
        }
    }
    sort (v.begin (), v.end ());
    if (cnt[v.back ()] > 0) {
        
    } else {

    }
    return 0;
}