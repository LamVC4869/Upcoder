#include <iostream>

using namespace std;

class SoPhuc {
    private:
    int a;
    int b;
    public:
    void setA (int a) {
        this->a = a;
    }  
    void setB (int b) {
        this->b = b;
    }
    int getA () {
        return a;
    }
    int getB () {
        return b;
    }
    SoPhuc (int a, int b) {
        this->a = a;
        this->b = b;
    }
    SoPhuc (int k = 1) {
        this->a = this->b = k;
    }
    friend istream& operator>>(istream &is, SoPhuc &sp) {
        is >> sp.a >> sp.b;
        return is;
    }
    friend ostream& operator<<(ostream &os, SoPhuc sp) {
        os << sp.a << '+' << sp.b << 'i';
        return os;
    }
    friend SoPhuc operator+(SoPhuc A, SoPhuc B) {
        SoPhuc C (A.a + B.a, A.b + B.b);
        return C;
    }
    friend SoPhuc operator-(SoPhuc A, SoPhuc B) {
        SoPhuc C (A.a - B.a, A.b - B.b);
        return C;
    }
};

int main () {
    SoPhuc p1, p2;
    cin >> p1 >> p2;
    cout << p1 << endl << p2 << endl;
    cout << p1 + p2 << endl << p1 - p2;
    return 0;
}