#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Employee {
    private:
    int id;
    string firstName;
    string lastName;
    double salary;
    public:
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
};

int main () {
    int id;
    string firstName, lastName;
    double salary, percent;
    cin >> id;
    cin.ignore ();
    getline (cin, firstName);
    getline (cin, lastName);
    cin >> salary >> percent;
    Employee e(id, firstName, lastName, salary);
    cout << e.toString () << endl;
    e.setSalary (e.raiseSalary (percent));
    cout << '$' << fixed << setprecision (2) << e.getSalary () << endl;
    cout << '$' << fixed << setprecision (2) << e.getAnnualSalary ();
    return 0;
}