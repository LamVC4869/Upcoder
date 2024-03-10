#include <iostream>

using namespace std;

int main () {
    string name;
    getline (cin, name);
    int begin, end;
    for (int i = 0; i < name.length (); i++) {
        if (name[i] == ' ') {
            begin = i; break;
        }
    }
    for (int i = name.length () - 1; i > -1; i--) {
        if (name[i] == ' ') {
            end = i;
            break;
        }
    }
    if (begin != end) {
        for (int i = 0; i < begin; i++) cout << name[i];
        cout << endl;
        for (int i = begin + 1; i < end; i++) cout << name[i];
        cout << endl;
        for (int i = end + 1; i < name.length (); i++) cout << name[i];
    } else {
        for (int i = 0; i < name.length (); i++) {
            if (name[i] == ' ') cout << endl;
            else cout << name[i];
        }
    }
    return 0;
}