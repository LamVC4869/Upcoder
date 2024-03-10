#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
    int n; cin >> n;
    cin.ignore ();
    string name[n], email[n];
    string duoi = "@gmail.com";
    bool duyet[n] = {};
    for (int i = 0; i < n; i++) getline (cin, name[i]);
    for (int i = 0; i < n; i++) {
        for (char &c : name[i]) c = tolower (c);
        while (name[i][0] == ' ') name[i].erase (0, 1);
        while (name[i][name[i].length () - 1] == ' ') name[i].erase (name[i].length () - 1, 1);
        int j = 0;
        while (j < name[i].length ()) {
            if (name[i][j] == ' ' && name[i][j + 1] == ' ') {
                name[i].erase (j, 1);
            } else j++;
        }
        stringstream ss (name[i]);
        vector<string> v;
        string tmp;
        while (getline (ss, tmp, ' ')) v.push_back (tmp);
        email[i] = v.back ();
        for (int k = 0; k < v.size () - 1; k++) email[i] += v[k][0];
    }
    for (int i = 0; i < n; i++) {
        for (int x = i + 1; x < n; x++) {
            if (email[i] == email[x]) duyet[x] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        int them = 1;
        if (!duyet[i]) {
            for (int x = i + 1; x < n; x++) {
                if (duyet[x] && email[i] == email[x]) {
                    them++;
                    email[x] += to_string (them);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << email[i] << duoi;
        if (i < n - 1) cout << endl;
    }
    return 0;
}