#include <iostream>

using namespace std;

struct bacnhat {
    int a, b;
};

void print (bacnhat a) {
    cout << a.a << "x+" << a.b;
}

void sum (bacnhat a, bacnhat b) {
    print (a);
    cout << "+";
    print (b);
    cout << "=" << a.a + b.a << "x+" << a.b + b.b << endl;
}

int value (bacnhat a, int &x) {
    return a.a * x + a.b;
}

bool compare (bacnhat a, bacnhat b) {
    return a.a + a.b == b.a + b.b;
}

int main () {
    bacnhat a, b;
    cin >> a.a >> a.b;
    cin >> b.a >> b.b;
    int x; cin >> x;

    print (a);
    cout << endl;
    print (b);
    cout << endl;
    sum (a, b);
    cout << value (a) << endl << value (b) << endl;
    compare (a, b) ? cout << "TRUE" : cout << "FALSE";

    return 0;
}