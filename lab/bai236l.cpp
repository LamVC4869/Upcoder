    #include <iostream>
    #include <cmath>

    using namespace std;

    struct Point {
        int x, y;
        double distance (Point a) {
            return 1.0 * sqrt (pow (a.x - this->x, 2) + pow (a.y - this->y, 2));
        }
        friend istream& operator >> (istream &is, Point &p) {
            is >> p.x >> p.y;
            return is;
        }
        friend ostream& operator << (ostream &os, Point p) {
            os << '(' << p.x << ", " << p.y << ')';
            return os;
        }
        void DoiXungTamO () {
            this->x *= -1;
            this->y *= -1;
        }
        void DoiXungOx () {
            this->y *= -1;
        }
        void DoiXungOy () {
            this->x *= -1;
        }
    };

    int main () {
        Point a, b; cin >> a >> b;
        int k; cin >> k;
        cout << a << endl << b << endl << a.distance (b) << endl;
        if (k == 0) a.DoiXungTamO ();
        else if (k == 1) a.DoiXungOx ();
        else a.DoiXungOy ();
        cout << a;
        return 0;
    }