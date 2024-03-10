#include <iostream>
#include <vector>

using namespace std;

class Device {
    private:
    int soLuong;
    string model;
    string manufactory;
    int power;
    double cost;
    public:
    Device () {
        soLuong = 0;
        model = "";
        manufactory = "";
        power = 0;
        cost = 0;
    }
    Device (string model, string manufactory, int power, double cost) {
        this->model = model;
        this->manufactory = manufactory;
        this->power = power;
        this->cost = cost;
    }
    Device (Device &d) {
        this->model = d.model;
        this->manufactory = d.manufactory;
        this->power = d.power;
        this->cost = d.cost;
    }
    string getModel () {
        return model;
    }
    double getTotalCost () {
        return cost + cost * 0.1;
    }
    double TongTien () {
        return getTotalCost () * this->soLuong;
    }
    friend istream& operator>>(istream &is, Device &d) {
        is.ignore ();
        is >> d.model; 
        is >> d.manufactory;
        is  >> d.power >> d.cost >> d.soLuong;
        return is;
    }
    friend ostream& operator<<(ostream &os, Device d) {
        os << d.model << '-' << d.manufactory << '-' << d.power << "W-" << d.getTotalCost () << endl;
        return os;
    }
    friend bool operator > (Device d1, Device d2) {
        return d1.power > d2.power || (d1.power == d2.power && d1.cost > d2.cost);
    }
    friend bool operator < (Device d1, Device d2) {
        return d1.power < d2.power || (d1.power == d2.power && d1.cost < d2.cost);
    }
    friend bool operator == (Device d1, Device d2) {
        return d1.power == d2.power && d1.cost == d2.cost;
    }
};

int main () {
    int n; cin >> n;
    Device d[n];
    double sum = 0.0;
    for(Device &a : d) {
        cin >> a;
        sum += a.TongTien ();
    }
    cout << sum << endl;
    string x, y; cin >> x >> y;
    Device a, b;
    for (Device &i : d) {
        if (i.getModel () == x) a = i;
        if (i.getModel () == y) b = i;
    }
    if (a > b) cout << '>';
    else if (a < b) cout << '<';
    else cout << '=';
    return 0;
}