#include <iostream>
#include <sstream>
#define ll long long

using namespace std;

ll point (ll n) {
    return n * (n + 1) / 2;
}

int main () {
    string str, tmp;
    cin >> str;
    for (char &i : str) i = toupper (i);
    int j = 1;
    while (j < str.length ()) {
        if (str[j] == 'S' && str[j - 1] == 'S') str.erase (j - 1, 1);
        else j++;
    }
    stringstream ss (str);
    ll res = 0;
    while (getline (ss, tmp, 'S')) res += point (tmp.length ());
    cout << res;
    return 0;
}