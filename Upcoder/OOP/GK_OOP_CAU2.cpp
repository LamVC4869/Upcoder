#include <iostream>
#include <cmath>

using namespace std;

class String {
    private:
    string str;
    public:
    String () : str("") {}
    String (string str) : str(str) {}
    String (const String &str1) : str(str1.str) {}
    ~String () {}
    String& operator = (const String str1) {
        this->str = str1.str;
        return *this;
    }
    friend istream& operator >> (istream &is, String &st) {
        getline (is, st.str);
        while (st.str[0] == ' ') st.str.erase (0, 1);
        while (st.str[st.getStringLength () - 1] == ' ') st.str.erase (st.getStringLength () - 1, 1);
        return is;
    }
    friend ostream& operator << (ostream &os, const String st) {
        os << st.str << endl;
        return os;
    }
    friend bool operator > (String str1, String str2) {
        return str1.str.length () > str2.str.length ();
    }
    friend bool operator == (String str1, String str2) {
        return str1.str.length () == str2.str.length ();
    }
    int getStringLength () {
        return this->str.length ();
    }
    void setString (string str) {
        this->str = str;
    }
    string getStr () {
        return str;
    }
    string getUpperCase () {
        string upperStr = this->str;
        for (int i = 0; i < upperStr.length (); i++) upperStr[i] = toupper(upperStr[i]);
        return upperStr;
    }
    char& operator [] (int index) {
        return this->str[index]; 
    }
};

class ReverString : public String {
    private:
    string str;
    public:
    string getStringInverse () {
        string res = "";
        for (int i = 0; i < str.length (); i++) res = str[i] + res;
        return res;
    }
    ReverString () : String () {}
    ReverString (string str) : String (str) {}
    ~ReverString () {}
    ReverString& operator = (const ReverString& str) {
        this->str = str.str;
        return *this;
    }
    friend istream& operator >> (istream &is, ReverString &r) {
        getline (is, r.str);
        while (r.str[0] == ' ') r.str.erase (0, 1);
        while (r.str[r.getStringLength () - 1] == ' ') r.str.erase (r.getStringLength () - 1, 1);
        r.setString (r.str);
        return is;
    }
    friend ostream& operator << (ostream &os, ReverString r) {
        os << r.getStringInverse () << endl;
        return os;
    }
};

int main () {
    ReverString r[2];
    for (ReverString &i : r) cin >> i;
    char c; cin >> c;
    for (ReverString i : r) cout << i;
    if (r[0] > r[1]) cout << "LONHON\n";
    else if (r[0] == r[1]) cout << "BANG\n";
    else cout << "BEHON\n";
    if (c == '+') cout << r[0].getStringLength () + r[1].getStringLength ();
    else cout << abs (r[0].getStringLength () - r[1].getStringLength ());
    return 0;
}