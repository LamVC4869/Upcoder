#include <iostream>
#include <vector>

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

class Television : public Device {
    private:
    int size;
    int width;
    int height;
    public:
    Television () : size (0), width (0), height (0), Device () {}
    Television (string model, string manufactory, int power, double cost, int size, int width, int height) : Device (model, manufactory, power, cost) {
        this->size = size;
        this->width = width;
        this->height = height;
    }
    Television (const Television &telv) {
        this->size = telv.size;
        this->width = telv.width;
        this->height = telv.height;
    }
    friend istream& operator >> (istream &is, Television &tel) {
        string model, manufactory, power, cost;
        is.ignore ();
        is >> model >> manufactory >> power >> cost >> tel.size >> tel.width >> tel.height;
        Television tel (model, manufactory, power, cost, tel.size, tel.width, tel.height);
        
    }
};

class Refrigerator : public Device {
    private:
    int capacity;
    double weigth;
    public:
    Refrigerator () : capacity (0), weigth (0), Device () {}
    Refrigerator (string model, string manufactory, int power, double cost, int capacity, double weigth) : Device (model, manufactory, power, cost) {
        this->capacity = capacity;
        this->weigth = weigth;
    }
    Refrigerator (const Refrigerator &ref) {
        this->capacity = ref.capacity;
        this->weigth = ref.weigth;
    }
};

int main () {
    int n; cin >> n;
    vector <
    while (n--) {

    }
    return 0;
}