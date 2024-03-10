#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> initList (int n) {
    list<int> result;
    for (int i = 1; i <= n; i++) result.push_back (i);
    return result;
}

vector<int> verifyFunction (int n) {
    list<int> l = initList (n);
    vector<int> res (l.begin (), l.end ());
    return res;
}

int main () {
    int n; cin >> n;
    vector<int> v = verifyFunction (n);
    for (auto it = v.begin (); it != v.end (); it++) cout << *it << ' ';
    return 0;
}