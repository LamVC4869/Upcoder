#include <iostream>
#include <vector>

using namespace std;

class ARRINT1 {
    private:
    int length;
    vector<int> a;
    public:
    ARRINT1 () : length (1) {
        a.resize (length);
        a[0] = 0;
    }
    ARRINT1 (int length) : length (length) {
        a.resize (length);
        a = vector<int> (length, 1);
    }
    ARRINT1 (int length, vector<int> a) : length (length), a(a) {}
    int getLength () {
        return length;
    }
    void setLength (int length) {
        this->length = length;
    }
    void Input () {
        cin >> length;
        a.resize (length);
        for (int i = length - 1; i > -1; i--) cin >> a[i];
    }
    void Output () {
        cout << length << ": ";
        for (int i = length - 1; i > -1; i--) cout << a[i];
    }
};

int main () {
    int n, len; cin >> n;
    len = n;
    char c;
    ARRINT1 arr;
    while (n--) {
        cin >> c;
        if (c == '#') {
            arr = ARRINT1 (len);
            break;
        } else if (isdigit (c)) {
            vector<int> a;
            a.push_back (c - '0');
            while (n--) {
                cin >> c;
                a.push_back (c - '0');
            }
            arr = ARRINT1 (len, a);
            break;
        }
    }
    arr.Output ();
    return 0;
}