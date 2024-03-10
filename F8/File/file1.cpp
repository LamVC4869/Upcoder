#include <iostream>
#include <fstream>

using namespace std;

struct Person {
    string name;
    int age;
    Person (){}
    Person (string _name, int _age) {
        name = _name;
        age = _age;
    }
};

int main () {
    fstream fs;
    fs.open ("input.txt");
    Person *persons = new Person [3];
    for (int i = 0; i < 3; i++) {
        getline (fs, persons[i].name);
        fs >> persons[i].age;
        fs.ignore ();
    }
    for (int i = 2; i > -1; i--) {
        fs << persons[i].name << " - " << persons[i].age << endl;
    }
    fs.close ();
    return 0;
}