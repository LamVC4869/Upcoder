#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    string duoi = "@gmail.com";
    char c;
    ifs >> c;
    c = tolower (c);
    ifs.ignore ();
    string str[1000];
    string gmail[1000];
    int size[1000];
    int i = 0, cnt[1000] = {0};
    while (getline (ifs, str[i])) {
        while (str[i][0] == ' ') {
            str[i].erase (0, 1);
        }
        while (str[i][str[i].length() - 1] == ' ') {
            str[i].erase (str[i].length() - 1, 1);
        }
        int x = 0;
        while (x < str[i].length()) {
            if (str[i][x] == ' ' && str[i][x + 1] == ' ') {
                str[i].erase (x, 1);
            } else {
                x++;
            }
        }
        for (int j = 0; j < str[i].length (); j++) {
            str[i][j] = tolower (str[i][j]);
            if (str[i][j] == c) cnt[i]++;
        }
        i++;
    }
    for (int j = 0; j < i; j++) {
        stringstream ss (str[j]);
        string tmp;
        vector<string> v;
        while (getline (ss, tmp, ' ')) v.push_back (tmp);
        string phan_sau = "";
        for (int k = 0; k < v.size () - 1; k++) {
            phan_sau += v[k][0];
        }
        gmail[j] = v.back () + phan_sau;
        size[j] = gmail[j].size ();
        gmail[j] += duoi;
    }
    bool duyet[1000] = {};
    int dem_so_luong_email_trung = 0;
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (gmail[j].substr (0, size[j]) == gmail[k].substr (0, size[k])) duyet[k] = true;
        }
    }
    for (int j = 0; j < i; j++) {
        int them = 1;
        for (int k = j + 1; k < i; k++) {
            if (gmail[j].substr (0, size[j]) == gmail[k].substr (0, size[k]) && !duyet[j]) {
                them++;
                string b = to_string (them);
                gmail[k].insert (size[k], b);
            }
        }
    }
    for (int j = 0; j < i; j++) {
        ofs << cnt[j] << '-' << gmail[j] << endl;
    }
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (gmail[j].substr (0, size[j]) == gmail[k].substr (0, size[k]) && duyet[k]) duyet[j] = true;
        }
    }
    for (int j = 0; j < i; j++) if (duyet[j]) dem_so_luong_email_trung++;
    ofs << dem_so_luong_email_trung;
    return 0;
}