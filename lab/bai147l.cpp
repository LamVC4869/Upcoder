#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PhanSo {
    int a, b;
    friend istream& operator >> (istream &is, PhanSo &ps) {
        char c;
        is >> ps.a >> c >> ps.b;
        return is;
    }
    static int gcd (int a, int b) {
        int x = a, y = b;
        while (y) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    } 
    friend ostream& operator << (ostream &os, PhanSo ps) {
        if (ps.a == 0) os << 0;
        else {
            int ucln = gcd (ps.a, ps.b);
            ps.a /= ucln, ps.b /= ucln;
            if (ps.b == 1) os << ps.a;
            else os << ps.a << '/' << ps.b;
        }
        return os;
    }
    friend bool operator == (PhanSo p1, PhanSo p2) {
        return p1.a * p2.b == p1.b * p2.a;
    }
    friend bool operator > (PhanSo p1, PhanSo p2) {
        return p1.a * p2.b > p1.b * p2.a;
    }
    friend bool operator < (PhanSo p1, PhanSo p2) {
        return p1.a * p2.b < p1.b * p2.a;
    }
    friend PhanSo operator + (PhanSo p1, PhanSo p2) {
        PhanSo p3;
        p3.a = p1.a * p2.b + p1.b * p2.a;
        p3.b = p1.b * p2.b;
        int ucln = gcd (p3.a, p3.b);
        p3.a /= ucln, p3.b /= ucln;
        return p3;
    }
};

template<typename T>
struct Arr {
    int size;
    T arr[1010];
    friend istream& operator >> (istream &is, Arr<T> &temp) {
        is >> temp.size;
        for (int i = 0; i < temp.size; i++) is >> temp.arr[i];
        return is;
    }
    friend ostream& operator << (ostream &os, Arr<T> temp) {
        for (int i = 0; i < temp.size; i++) os << temp.arr[i] << ' ';
        return os;
    }
    T tongPhanTu () {
        T sum = this->arr[0];
        for (int i = 1; i < this->size; i++) sum = sum + this->arr[i];
        return sum;
    }
    T phanTuMax () {
        T max = this->arr[0];
        for (int i = 1; i < this->size; i++) if (this->arr[i] > max) max = this->arr[i];
        return max;
    }
    friend Arr<T> operator + (Arr<T> t1, Arr<T> t2) {
        Arr<T> t3;
        t3.size = max(t1.size, t2.size);
        for (int i = 0; i < t3.size; i++) {
            t3.arr[i] = t1.arr[i] + t2.arr[i];
        }
        return t3;
    }
    void sapXep (char Type) {
        if (Type == '<') {
            for (int i = 0; i < this->size - 1; i++) {
                for (int j = i + 1; j < this->size; j++) {
                    if (this->arr[i] > this->arr[j]) swap (this->arr[i], this->arr[j]);
                }
            }
        } else if (Type == '>'){
            for (int i = 0; i < this->size - 1; i++) {
                for (int j = i + 1; j < this->size; j++) {
                    if (this->arr[i] < this->arr[j]) swap (this->arr[i], this->arr[j]);
                }
            }
        }
    }
};

void Cout (vector<int> vec) {
    for (int i : vec) cout << i << ' ';
    cout << endl;
}

vector<int> operator + (vector<int> v1, vector<int> v2) {
    vector<int> v3 = v1;
    for (int i : v2) v3.push_back (i);
    return v3;
}

int main () {
    char Type; cin >> Type;
    if (Type == 'I') {
        Arr<int> m1, m2, Sum;
        vector<int> m1_even, m1_odd, m2_even, m2_odd;
        cin >> m1 >> m2;
        for (int i = 0; i < m1.size; i++) {
            if (m1.arr[i] % 2 == 0) m1_even.push_back (m1.arr[i]);
            else m1_odd.push_back (m1.arr[i]);
        }
        for (int i = 0; i < m2.size; i++) {
            if (m2.arr[i] % 2 == 0) m2_even.push_back (m2.arr[i]);
            else m2_odd.push_back (m2.arr[i]);
        }
        Sum = m1 + m2;
        cout << m1 << endl;
        cout << "MAX 1 = " << m1.phanTuMax () << endl;
        cout << "SUM 1 = " << m1.tongPhanTu () << endl;
        sort(m1_even.begin (), m1_even.end ()), sort(m1_odd.begin (), m1_odd.end ());
        vector<int> v1, v2;
        v1.resize (m1_even.size() + m1_odd.size ());
        v1 = m1_even + m1_odd;
        Cout (v1);
        cout << m2 << endl;
        cout << "MAX 2 = " << m2.phanTuMax () << endl;
        cout << "SUM 2 = " << m2.tongPhanTu () << endl;
        sort(m2_odd.rbegin (), m2_odd.rend ()), sort(m2_even.rbegin (), m2_even.rend ());
        v2.resize (m2_odd.size () + m2_even.size ());
        v2 = m2_odd + m2_even;
        Cout (v2);
        cout << Sum;
    } else if (Type == 'F') {
        Arr<PhanSo> p1, p2;
        cin >> p1 >> p2;
        vector<PhanSo> v;
        v.resize (min (p1.size, p2.size));
        for (int i = 0; i < v.size (); i++) v[i] = p1.arr[i] + p2.arr[i];
        if (p1.size < p2.size) v.push_back (p2.arr[p2.size - 1]);
        else if (p1.size > p2.size) v.push_back (p1.arr[p1.size - 1]);
        cout << p1 << endl;
        cout << "MAX 1 = " << p1.phanTuMax () << endl;
        cout << "SUM 1 = " << p1.tongPhanTu () << endl;
        p1.sapXep ('<');
        cout << p1 << endl << p2 << endl;
        cout << "MAX 2 = " << p2.phanTuMax () << endl;
        cout << "SUM 2 = " << p2.tongPhanTu () << endl;
        p2.sapXep ('>');
        cout << p2 << endl;
        for (PhanSo i : v) cout << i << ' ';
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    int t, m;
    PhanSo(int _t=0, int _m=1) : t(_t), m(_m){};
    void operator=(int _t) {
        t = _t;
        m = 1;
    }
    friend istream& operator>>(istream& is, PhanSo& ps) {
        string phanso;
        is >> phanso;
        stringstream ss(phanso);
        ss >> ps.t;
        ss.ignore();
        ss >> ps.m;
        int ucln = __gcd(ps.t, ps.m);
        ps.t = ps.t/ucln;
        ps.m = ps.m/ucln;
        return is;
    }
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        return os << ps.t << (ps.t != 0 && ps.m != 1 ? "/" + to_string(ps.m): "");
    }
    bool operator==(const PhanSo& other) {
        return (double) t/m == (double) other.t/other.m;
    }
    bool operator<(const PhanSo& other) {
        return (double) t/m < (double) other.t/other.m;
    }
    bool operator>(const PhanSo& other) {
        return (double) t/m > (double) other.t/other.m;
    }
    PhanSo operator+(const PhanSo& other) {
        int tuNew = t*other.m + m*other.t;
        int mauNew = m*other.m;
        int ucln = __gcd(tuNew,mauNew);
        return PhanSo(tuNew/ucln, mauNew/ucln);
    }
};
template<typename T>
bool cmd(T x,T y) {
    return x>y;
}

bool cmdI(int x1, int x2) {
    return ((x1%2 == 0 & x2%2 == 0 ) || (x1%2 == 0 & x2%2 != 0) || (x1%2 != 0 & x2%2 != 0)) && (x1 < x2); 
}
bool cmdI_(int x1, int x2) {
    return !cmdI(x1, x2); 
}
template<typename T>
struct ArrayList {
    vector<T> myV;
    ~ArrayList() {
        myV.clear();
    }
    friend istream& operator>>(istream& is, ArrayList<T>& A) {
        int n;
        is >> n;
        while(n--) {
            T val;
            is >> val;
            A.myV.push_back(val);
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const ArrayList<T>& A) {
        for(const auto& it : A.myV) 
            os << it << " ";
        return os << "\n";
    }
    void operator+(const ArrayList<T>& other) {
        for(int i = 0; i < min(myV.size(),other.myV.size()); ++i) {
            myV[i] = myV[i] + other.myV[i];
        }
        if(myV.size() < other.myV.size()) {
            for(int i = myV.size(); i < other.myV.size(); ++i)
                myV.push_back(other.myV[i]);
        }
    }
    T tongPhantu() {
        T sum = 0;
        for(const auto& val : myV)  
            sum = sum + val;
        return sum;
    }
    void sapXepPS(string type) {
        if (type == "<")
            sort(myV.begin(), myV.end());
        else if(type == ">")
            sort(myV.begin(), myV.end(), cmd<T>);
    }
    void sapXepInt(string type) {
        if (type == "<")
            sort(myV.begin(), myV.end(), cmdI);
        else if(type == ">")
            sort(myV.begin(), myV.end(), cmdI_);
    }
    T phanTuMax() {
        sort(myV.begin(), myV.end(), cmd<T>);
        return myV[0];
    }
    void _clear() {
        myV.clear();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char typeArray;
    int i = 1;
    cin >> typeArray;
    if(typeArray == 'I') {
        ArrayList<int> myArray;
        ArrayList<int> SUM;
        for(int i = 1; i <= 2; i++) {
            cin >> myArray;
            if(i == 2) {
                SUM + myArray;
            } else if(i == 1) {
                SUM = myArray;
            }
            cout << myArray;
            cout << "MAX " << i << " = " << myArray.phanTuMax() << "\n";
            cout << "SUM " << i << " = " << myArray.tongPhantu() << "\n";
            if(i == 2)  
                myArray.sapXepInt(">");
            else 
                myArray.sapXepInt("<");
            cout << myArray;
            myArray._clear();
        }
        cout << SUM;
    } else if(typeArray == 'F') {
        ArrayList<PhanSo> myArray;
        ArrayList<PhanSo> SUM;
        for(int i = 1; i <= 2; i++) {
            cin >> myArray;
            if(i == 2) 
                SUM + myArray;
            else if(i==1) 
                SUM = myArray;
            cout << myArray;
            cout << "MAX " << i << " = " << myArray.phanTuMax() << "\n";
            cout << "SUM " << i << " = " << myArray.tongPhantu() << "\n";
            if(i == 2)  
                myArray.sapXepPS(">");
            else 
                myArray.sapXepPS("<");
            cout << myArray;
            myArray._clear();
        }
        cout << SUM;
    }
    return 0;
}   
*/