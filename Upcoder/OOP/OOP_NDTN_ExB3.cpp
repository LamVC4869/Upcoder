#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ARRINT2 {
    private:
    int length;
    vector<int> a;
    public:
    void setLength (int length) {
        this->length = length;
        this->a.resize(this->length);
    }
    friend istream& operator >> (istream &is, ARRINT2 &arr) {
        for (int i = arr.length - 1; i >= 0; i--) is >> arr.a[i];
        return is;
    }
    friend ostream& operator << (ostream &os, ARRINT2 arr) {
        os << arr.length << ": ";
        for (int i = 0; i < arr.length; i++) os << arr.a[i];
        return os;
    }
    ARRINT2 operator - (ARRINT2 another) {
        int l = max(this->length, another.length);
        if (this->length < l) this->setLength(l);
        else if (another.length < l) another.setLength(l);
        ARRINT2 result;
        result.setLength (l);
        for (int i = 0; i < l; i++) {
            result.a[i] = this->a[i] - another.a[i];
            result.a[i] = abs (result.a[i]);
        }
        return result;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    ARRINT2 p, q;
    p.setLength (n);
    q.setLength (m);
    cin >> p >> q;
    cout << p - q;
    return 0;
}