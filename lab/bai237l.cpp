#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char phim1[] = {' ', ',', '.', '?', '!', '\'', '\"', '-', '@', ':', ';', '/', '_'};
char phim2[] = {' ', 'a', 'b', 'c'};
char phim3[] = {' ', 'd', 'e', 'f'};
char phim4[] = {' ', 'g', 'h', 'i'};
char phim5[] = {' ', 'j', 'k', 'l'};
char phim6[] = {' ', 'm', 'n', 'o'};
char phim7[] = {' ', 'p', 'q', 'r', 's'};
char phim8[] = {' ', 't', 'u', 'v'};
char phim9[] = {' ', 'w', 'x', 'y', 'z'};

int main () {
    string str, tmp;
    getline (cin, str);
    string result = "";
    stringstream ss (str);
    while (ss >> tmp) {
        if (tmp[0] == '#') {
            int x = tmp[1] - '0', y = tmp[2] - '0';
            if (x == 1) {
                result += toupper(phim1[y]);
            } else if (x == 2) {
                result += toupper(phim2[y]);
            } else if (x == 3) {
                result += toupper(phim3[y]);
            } else if (x == 4) {
                result += toupper(phim4[y]);
            } else if (x == 5) {
                result += toupper(phim5[y]);
            } else if (x == 6) {
                result += toupper(phim6[y]);
            } else if (x == 7) {
                result += toupper(phim7[y]);
            } else if (x == 8) {
                result += toupper(phim8[y]);
            } else if (x == 9) {
                result += toupper(phim9[y]);
            }
        } else if (tmp[0] == '0') {
            result += ' ';
        } else if (isdigit (tmp[0]) && tmp[0] != '0') {
            int x = tmp[0] - '0', y = tmp[1] - '0';
            if (x == 1) {
                result += phim1[y];
            } else if (x == 2) {
                result += phim2[y];
            } else if (x == 3) {
                result += phim3[y];
            } else if (x == 4) {
                result += phim4[y];
            } else if (x == 5) {
                result += phim5[y];
            } else if (x == 6) {
                result += phim6[y];
            } else if (x == 7) {
                result += phim7[y];
            } else if (x == 8) {
                result += phim8[y];
            } else if (x == 9) {
                result += phim9[y];
            }
        }
    }
    cout << result;
    return 0;
}