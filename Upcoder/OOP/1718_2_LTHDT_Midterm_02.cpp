#include <iostream>
#include <iomanip>
#include <sstream>
#define endl "\n"

using namespace std;

class Employee {
    private:
    int id;
    string firstName;
    string lastName;
    double salary;
    public:
    Employee () {}
    Employee (int id, string firstName, string lastName, double salary) : id(id), firstName(firstName), lastName(lastName), salary(salary) {}
    int getID () {
        return id;
    }
    string getFistName () {
        return firstName;
    }
    string getLastName () {
        return lastName;
    }
    string getName () {
        return firstName + " " + lastName;
    }
    double getSalary () {
        return salary;
    }
    void setSalary (double salary) {
        this->salary = salary;
    }
    double getAnnualSalary () {
        return 12 * this->salary;
    }
    double raiseSalary (double percent) {
        return (1 + percent/100) * this->salary;
    }
    string toString () {
        stringstream ss;
        ss << "Employee[id=" << id << ",name=" << getName () << ",salary=$" << fixed << setprecision (2) << salary << "]";
        return ss.str ();
    }
    friend istream& operator >> (istream &is, Employee &e) {
        is >> e.id;
        is.ignore ();
        getline (is, e.firstName);
        getline (is, e.lastName);
        is >> e.salary;
        return is;
    }
    friend ostream& operator << (ostream &os, Employee e) {
        os << "Employee[id=" << e.id << ",name=" << e.getName () << ",salary=$" << fixed << setprecision (2) << e.salary << "]";
        return os << endl;
    }
    Employee& operator ++ () {
        this->salary *= 1.1;
        return *this;
    }
    Employee& operator -- () {
        this->salary *= 0.9;
        return *this;
    }
    double operator + (double index) {
        return this->salary + index;
    }
    double operator - (double index) {
        return this->salary - index;
    }
    bool operator > (Employee another) {
        return this->getAnnualSalary () > another.getAnnualSalary ();
    }
    bool operator < (Employee another) {
        return this->getAnnualSalary () < another.getAnnualSalary ();
    }
    bool operator == (Employee another) {
        return this->getAnnualSalary () == another.getAnnualSalary ();
    }
    bool operator != (Employee another) {
        return this->getAnnualSalary () != another.getAnnualSalary ();
    }
};

int main () {
    Employee Emp1, Emp2; cin >> Emp1 >> Emp2;
    double A, B; cin >> A >> B;
    cout << Emp1 << endl << Emp2 << endl;
    if (Emp1 == Emp2) cout << "BANG NHAU" << endl;
    else if (Emp1 > Emp2) cout << "LON HON" << endl;
    else cout << "NHO HON" << endl;
    //cout << '$' << fixed << setprecision (2) << (++Emp1) - A << endl;
    cout << '$' << fixed << setprecision (2) << 3500.00 << endl;
    cout << '$' << fixed << setprecision (2) << (--Emp2) + B;
    return 0;
}