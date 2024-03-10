#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool scp (int n) {
    return int (sqrt (n)) == sqrt (n);
}

void ngayTruoc (int d, int m, int y);
void ngaySau (int d, int m, int y);

int main () {
    string str; cin >> str;
    string tmp;
    stringstream ss (str);
    vector<string> v;
    while (getline (ss, tmp, '/')) v.push_back (tmp);
    int day = stoi (v[0]);
    int month = stoi (v[1]);
    int year = stoi (v.back ());
    ngayTruoc (day, month, year);
    // ngaySau (day, month, year);
    return 0;
}

void ngayTruoc (int d, int m, int y) {
    int a = y;
    string s = to_string (y);
    int x = stoi (s.substr (2, 2));
    int num, cnt = 0;
    if (x >= 1 && x <= 81) {
        for (int i = x; i > 0; i--) {
            if (scp (i) && i == x) {
                if (sqrt (i) > m) continue;
                else {
                    if (sqrt (i) >= d) continue;
                    else {
                        cnt++;
                        num = sqrt (i);
                    }
                }
            } else if (scp (i) && i != x) {
                if (scp (i)) {
                    cnt++;
                    num = sqrt (i);
                    break;
                }
                a--;
            }
        }
    }
    string str;
    if (x == 0) {
        a--;
        str = to_string (a);
        int k = stoi (str.substr (2, 2));
        num = 9;
        for (int i = k; i > 0; i--) {
            if (scp (i)) break;
            a--;
        }
    }
    cout << '0' << num << '/' << '0' << num << '/' << a;
}