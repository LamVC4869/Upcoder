#include <iostream>
#include <vector>

using namespace std;

struct Thisinh {
    char code[6];
    string name;
    double toan, ly, hoa;
    double avg () {
        return (toan + ly + hoa) / 3;
    }
};

bool Pass (Thisinh a) {
    return a.avg () * 3 > 15 && a.toan != 0 && a.ly != 0 && a.hoa != 0;
}

void Xuat_Mang (Thisinh a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].code << '-' << a[i].name << '-' << a[i].toan << '-' << a[i].ly << '-' << a[i].hoa << endl;
    }
}

void Sort (Thisinh a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].avg () < a[j].avg ()) {
                Thisinh tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int n; cin >> n;
    Thisinh thisinh [n];
    for (int i = 0; i < n; i++) {
        cin >> thisinh[i].code;
        cin.ignore ();
        getline (cin, thisinh[i].name);
        cin >> thisinh[i].toan >> thisinh[i].ly >> thisinh[i].hoa;
    }
    Xuat_Mang (thisinh, n);
    vector<string> v;
    for (int i = 0; i < n; i++) if (Pass (thisinh[i])) v.push_back (thisinh[i].name);
    if (v.empty ()) {
        cout << -1 << endl;
    } else {
        cout << v[0];
        for (int i = 1; i < v.size (); i++) cout << '-' << v[i];
        cout << endl;
    }
    Sort (thisinh, n);
    cout << thisinh[0].name;
    for (int i = 1; i < n; i++) cout << '-' << thisinh[i].name;
    return 0;
}