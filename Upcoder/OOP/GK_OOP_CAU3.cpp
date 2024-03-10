#include <iostream>
#include <cmath>
#include <iomanip>

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
    void ChuanHoa (string &s) {
        while (s[0] == ' ') s.erase (0, 1);
        while (s[s.length () - 1] == ' ') s.erase (s.length () - 1, 1);
        int i = 0;
        while (i < s.length ()) {
            if (s[i] == ' ' && s[i - 1] != '.') s.erase (i, 1);
            else i++;
        }
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
        this->ChuanHoa (this->str);
        string res = "";
        for (int i = 0; i < str.length (); i++) res = str[i] + res;
        return res;
    }
    string connectString (string s) {
        this->ChuanHoa (this->str);
        return this->str + " " + s;
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
        r.setString (r.str);
        return is;
    }
    friend ostream& operator << (ostream &os, ReverString r) {
        os << r.getStr ();
        return os;
    }
    double operator / (ReverString &r) {
        this->ChuanHoa (this->str);
        r.ChuanHoa(r.str);
        return double (this->getStringLength () * 1.0 / r.getStringLength ());
    }
};

int main () {
    ReverString r1, r2;
    cin >> r1 >> r2;
    cout << r1.connectString (r2.getStr ()) << endl;
    cout << r1.getStringInverse () << endl;
    cout << r2.getStringInverse () << endl;
    cout << r1.getStringLength () << endl << r2.getStringLength () << endl;
    cout << fixed << setprecision (2) << r1 / r2 << endl;
    return 0;
}

/*
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MyString
{
protected:
    string data;

public:
    MyString()
    {
    }
    MyString(string data)
    {
        this->data = data;
    }

    MyString(const MyString &s)
    {
        this->data = s.data;
    }
    ~MyString()
    {
    }

    void setData(string data)
    {
        this->data = data;
    }
    string getData()
    {
        return this->data;
    }

    friend ostream &operator<<(ostream &os, MyString s)
    {
        os << s.data;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &s)
    {
        getline(cin, s.data);
        ;
        return is;
    }
    int getStringLength()
    {
        return this->data.length();
    }
    bool operator>(MyString &d)
    {
        return this->getStringLength() > d.getStringLength();
    }
    string stringUpperCase()
    {
        string res = "";
        for (int i = 0; i < this->getStringLength(); i++)
        {
            if (data[i] <= 'z' && data[i] >= 'a')
            {
                res += data[i] - 32;
            }
            else
                res += data[i];
        }
        return res;
    }
};

class AnotherString : public MyString
{
public:
    AnotherString()
    {
    }
    AnotherString(string data) : MyString(data) {}
    AnotherString(const AnotherString &s) : MyString(s) {}
    ~AnotherString() {}

    friend ostream &operator<<(ostream &os, AnotherString s)
    {
        os << s.data;
        return os;
    }

    friend istream &operator>>(istream &is, AnotherString &s)
    {
        getline(cin, s.data);
        ;
        return is;
    }

    string nomarlize(string data)
    {
        string res = data;
        string kq = "";
        // while (res[0] == ' ')
        // {
        //     res = res.erase(0, 1);
        // }

        // while (res[res.length() - 1] == ' ')
        // {
        //     int idx = res.length() - 1;
        //     res = res.erase(idx);
        // }
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] == ' ')
            {
                while (res[i + 1] == ' ')
                    i++;
            }
            kq += res[i];
        }
        return kq;
    }

    string getStringInverse()
    {
        string t = nomarlize(this->data);
        string s = "";
        for (int i = t.length() - 1; i >= 0; i--)
        {
            s += t[i];
        }
        return s;
    }
    string connectString(AnotherString s){
        string str = s.data;
        string s1 = this->nomarlize(str);
        string s2 = this->nomarlize(this->data);
        string res = "";
        for(int i = 0; i < s2.length(); i++){
            res += s2[i];
        }
        res += " ";
        for(int i = 0; i < s1.length(); i++){
            res += s1[i];
        }
        return res;
    }

    double operator/(AnotherString s){
        this->data = this->nomarlize(this->data);
        s.data = this->nomarlize(s.data);
        double len1 = this->getStringLength();
        double len2 = s.getStringLength();
        return len1 * 1.0 / len2;
    }
};

int main()
{
    AnotherString s1, s2;
    cin >> s1;
    cin >> s2;
    string s3 = s1.connectString(s2);
    cout << s3 << endl;
    cout << s1.getStringInverse() << endl;
    cout << s2.getStringInverse() << endl;

    cout << fixed << setprecision(2) << s1/s2 << endl;
    // system("pause");
    return 0;
}
*/