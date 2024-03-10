#include <iostream>

using namespace std;

struct Person {
    char code[11];
    string name, dob;
};

int main () {
    Person person1;
    cin >> person1.code;
    cin.ignore ();
    getline (cin, person1.name);
    getline (cin, person1.dob);
    cout << person1.code << endl << person1.name << endl;
    string day, month, year;
    if (person1.dob.length () == 10) {
        day = person1.dob.substr (0, 2);
        month = person1.dob.substr (3, 2);
        year = person1.dob.substr (6, 4);
    } else {
        day = person1.dob.substr (0, 2);
        month = person1.dob.substr (2, 2);
        year = person1.dob.substr (4, 4);
    }
    cout << day << "/" << month << "/" << year;
    return 0;
}