#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
    string id, name;
    double GPA;
    friend istream& operator >> (istream &is, Student &student) {
        is >> student.id;
        getline (is, student.name);
        is >> student.GPA;
        is.ignore ();
        return is;
    }
    friend ostream& operator << (ostream &os, Student student) {
        os << student.id << '\n' << student.name << '\n' << fixed << setprecision (1) << student.GPA;
        return os << '\n';
    }
};

bool duTieuChuan (Student student) {
    return student.GPA >= 7.0;
}

int main () {
    int n; cin >> n;
    Student students[n];
    cin.ignore ();
    for (Student &i : students) cin >> i;
    for (int i = 0; i < n; i++) if (duTieuChuan (students[i])) cout << students[i];
    return 0;
}