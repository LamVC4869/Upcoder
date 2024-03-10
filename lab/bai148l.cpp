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
    friend bool operator < (String str1, String str2) {
        return str1.str.length () < str2.str.length ();
    }
    friend bool operator == (String str1, String str2) {
        return str1.str.length () == str2.str.length ();
    }
    int getStringLength () {
        return this->str.length ();
    }
    string getUpperCase () {
        string upperStr = this->str;
        for (int i = 0; i < upperStr.length (); i++) upperStr[i] = toupper(upperStr[i]);
        return upperStr;
    }
    char& operator [] (int index) {
        return this->str[index]; 
    }
    string getString () {
        return str;
    }
};

class RString : public String {
    private:
    string rst;
    public:
    string getStringInverse() {
        string Rstring = getString ();
        string res = "";
        for (int i = Rstring.length () - 1; i > -1; i--) res += Rstring[i];
        return res;
    }
    RString () : rst("") {}
    RString (string rst) {
        this->rst = rst;
        
    }
};