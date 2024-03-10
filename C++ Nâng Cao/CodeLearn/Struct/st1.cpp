#include <iostream>

using namespace std;

struct Student {
    string name;
    int age;
    void display () {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main () {
    int n; cin >> n;
    Student *student = new Student [n];
    for (int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].age;
        student[i].display ();
    }
    delete []student;
    return 0;
}