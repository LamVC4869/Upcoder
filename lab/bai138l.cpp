#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Person {
    private:
    string name;
    int yob;
    string add;
    public:
    friend istream& operator>> (istream &is, Person &p1) {
        getline (is, p1.name);
        is >> p1.yob;
        is.ignore ();
        getline (is, p1.add);
        return is;
    }
    void setName (string name) {
        this->name = name;
    }
    void setYob (int yob) {
        this->yob = yob;
    }
    void setAdd (string add) {
        this->add = add;
    }
    string getName () {
        return name;
    }
    int getYob () {
        return yob;
    }
    string getAdd () {
        return add;
    }
    Person () {}
    Person (string name, int yob, string add) {
        this->name = name;
        this->yob = yob;
        this->add = add;
    }
    ~Person () {}
    virtual void display () {
        cout << "Ho Ten: " << name << endl;
        cout << "Nam Sinh: " << yob << endl;
        cout << "Que quan: " << add << endl;
    }
};

class Student : public Person {
    private:
    string department;
    int score;
    vector<double> list_score;
    public:
    friend istream& operator>> (istream &is, Student& student) {
        string name;
        int yob;
        string add;
        getline (is, name);
        is >> yob;
        is.ignore ();
        getline (is, add);
        student.setName(name);
        student.setYob(yob);
        student.setAdd (add);
        getline (is, student.department);
        while (is >> student.score) {
            student.list_score.push_back (student.score);
        }
        return is;
    }
    double average_score () {
        double result = 0.0;
        for (vector<double>::iterator it = list_score.begin (); it != list_score.end (); it++) result += *it;
        return result * 1.0 / list_score.size ();
    }
    void setDepartment (string department) {
        this->department = department;
    }
    void setScore (vector<double> v) {
        for (vector<double>::iterator it = v.begin (); it != v.end (); it++) list_score.push_back (*it);
    }
    string getDepartment () {
        return department;
    }
    vector<double> getList_score () {
        return list_score;
    }
    Student () {}
    Student (string name, int yob, string add, string department, vector<double> list_score) : Person (name, yob, add) {
        this->department = department;
        this->list_score = list_score;
    }
    ~Student () {}
    void display () {
        Person::display ();
        cout << "Khoa: " << department << endl;
        cout << "Diem cac mon: ";
        for (vector<double>::iterator it = list_score.begin (); it != list_score.end (); it++) cout << *it << ' ';
        cout << endl;
        cout << "Diem trung binh: " << fixed << setprecision (2) << average_score ();
    }
};

int main () {
    Student a;
    cin >> a;
    a.display ();
    return 0;
}