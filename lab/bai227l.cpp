#include <iostream>

using namespace std;

string chuoi[4] = {"dream", "erase", "eraser", "dreamer"};

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    string str; cin >> str;
    while (str[0] == 'd' || str[0] == 'e') {
        if (str.substr (0, 5) == chuoi[1]) {
            if (str[5] == 'r') str.erase (0, 6);
            else str.erase (0, 5);
        } else if (str.substr (0, 5) == chuoi[0]) {
            str.erase (0, 5);
            if (str.substr (0, 6) == chuoi[2]) str.erase (0, 6);
            else if (str.substr (0, 5) == chuoi[1]) str.erase (0, 5);
            else if (str.substr (0, 2) == "er") str.erase (0, 2);
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << (str.empty () ? "YES" : "NO");
    return 0;
}

/*

#include <iostream>
#include <string>

using namespace std;
string s, t1 = "dream", t2 = "dreamer", t3 = "erase", t4 = "eraser";

string Check(string s) {
	
	while (s[0] == 'd' || s[0] == 'e') {
		if (s.substr(0, 5) == t3) {
			if (s[5] == 'r') s.erase(0,6); else s.erase(0,5);
		}
		else if (s.substr(0, 5) == t1) {
			s.erase(0, 5);
			if (s.substr(0, 6) == t4) s.erase(0, 6);
			else if (s.substr(0, 5) == t3) s.erase(0, 5);
			else if (s.substr(0, 2) == "er") s.erase(0, 2);
		}
		else return "NO";
	}
	if (s == "") return "YES"; 
	else return "NO";
}

int main() {
	while (cin >> s) cout << Check(s);

	return 0;
}

*/