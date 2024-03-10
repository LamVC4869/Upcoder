#include <iostream>

using namespace std;

class Animal {
    protected:
    string name = "Bo";
    float weight = 30;
    public:
    void run () {
        cout << name << " is running..." << endl;
    }
};

class Cat : public Animal {
    public:
    void eat () {
        cout << this->name << " is eating..." << endl;
        cout << "Weight: " << this->weight << endl;
    }
};

int main () {
    Cat cat;
    cat.eat ();
    return 0;
}