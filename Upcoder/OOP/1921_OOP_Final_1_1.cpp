#include <iostream>

using namespace std;

class Device {
    private:
    string model;
    string manufactory;
    int power;
    double cost;
    public:
    Device () {
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
    double getTotalCost () {
        return cost + cost * 0.1;
    }
    friend istream& operator>>(istream &is, Device &d) {
        is >> d.model; 
        is >> d.manufactory;
        is  >> d.power >> d.cost;
        return is;
    }
    friend ostream& operator<<(ostream &os, Device d) {
        os << d.model << '-' << d.manufactory << '-' << d.power << "W-" << d.getTotalCost () << endl;
        return os;
    }
};

int main () {
    int n; cin >> n;
    Device d[n];
    for(Device &a : d) cin >> a;
    for (Device a : d) cout << a;
    return 0;
}