#include <iostream>

using namespace std;

int main () {
    string t = "Happy new year 2017";
    string rep = "Happy new year 2016";
    int l = t.length();
    
    int n;
    cin >> n;
    cin.ignore();
    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        int giftExp = 0;
        while (str.find (t) != -1) {
            giftExp++;
            str.replace (str.find (t), l, rep);
        }
        cout << giftExp << endl;
    }
    return 0;
}