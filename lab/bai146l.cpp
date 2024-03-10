#include <iostream>

using namespace std;

class Person {
    private:
    int id;
    string name;
    int year;
    string gender;
    public:
    Person () : id (0), name (""), year (0), gender ("") {}
    Person (int id, string name, int year, string gender) {
        this->id = id;
        this->name = name;
        this->year = year;
        this->gender = gender;
    }
    Person (const Person &person) {
        this->id = person.id;
        this->name = person.name;
        this->year = person.year;
        this->gender = person.gender;
    }
    int getYearOld () {
        return 2020 - year;
    }
    friend istream& operator >> (istream &is, Person &person) {
        is >> person.id;
        is.ignore ();
        getline (is, person.name);
        is >> person.year >> person.gender;
        return is;
    }
    friend ostream& operator << (ostream &os, Person person) {
        os << person.id << '-' << person.name << '-';
        os << person.getYearOld () << '-' << person.gender << endl;
        return os;
    }
    friend bool operator > (Person p1, Person p2) {
        return p1.getYearOld () > p2.getYearOld () ||
               (p1.getYearOld () == p2.getYearOld () && p1.id > p2.id);
    }
    friend bool operator < (Person p1, Person p2) {
        return p1.getYearOld () < p2.getYearOld () ||
               (p1.getYearOld () == p2.getYearOld () && p1.id < p2.id);
    }
};

void sort_0 (Person person[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (person[i] > person[j]) swap (person[i], person[j]);
        }
    }
}

void sort_1 (Person person[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (person[i] < person[j]) swap (person[i], person[j]);
        }
    }
}

int main () {
    int n; cin >> n;
    Person person[n];
    for (Person &i : person) cin >> i;
    int flag; cin >> flag;
    switch (flag) {
    case 0:
    sort_0 (person, n); break;
    default:
    sort_1 (person, n);
    }
    for (Person i : person) cout << i;
    return 0;
}