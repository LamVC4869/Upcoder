#include <iostream>

using namespace std;

struct Student {
    string name;
    int age;
    void display () {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    void getInformation () {
        cin >> name;
        cin >> age;
    }
};

int main () {
    int n; cin >> n;
    Student *student = new Student [n];
    for (int i = 0; i < n; i++) {
        student[i].getInformation ();
        student[i].display ();
    }
    delete []student;
    return 0;
}