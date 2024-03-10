#include <iostream>
#include <iomanip>

using namespace std;

class Thu {
    private:
    string id;
    string species;
    bool gender;
    float weight;
    string times;
    public:
    Thu () {}
    Thu (string id, string species, bool gender, float weight, string times) : id(id), species(species), gender(gender), weight(weight), times(times) {}
    void setID (string id) {
        this->id = id;
    }
    void setSpecies (string species) {
        this->species = species;
    }
    void setTimes (string times) {
        this->times = times;
    }
    void setGender (bool gender) {
        this->gender = gender;
    }
    void setWeight (float weight) {
        this->weight = weight;
    }
    string getID () {
        return id;
    }
    string getSpecies () {
        return species;
    }
    string getTimes () {
        return times;
    }
    string getGender () {
        return gender ? "Duc" : "Cai";
    }
    float getWeight () {
        return weight;
    }
    float WeigthOfFoodPerDay () {
        return gender ? 0.1 * weight : 0.05 * weight;
    }
    friend ostream& operator << (ostream &os, Thu animal) {
        os << animal.id << " | " << animal.species << " | " << animal.getGender () << " | ";
        os << fixed << setprecision (2) << animal.weight << " | " << animal.times;
        return os << endl;
    }
};

int main () {
    int n; cin >> n;
    Thu *animals = new Thu [n];
    for (int i = 0; i < n; i++) {
        string str; getline (cin, str);
        string id, species, times;
        bool gender;
        float weight;
        animals[i].setID (str.substr (0, str.find ('_')));
        str.erase (0, str.find('_') + 1);
        animals[i].setSpecies (str.substr (0, str.find ('_')));
        str.erase (0, str.find ('_') + 1);
        animals[i].setGender (stoi (str.substr (0, str.find ('_'))));
        str.erase (0, str.find ('_') + 1);
        animals[i].setWeight (stof(str.substr (0, str.find ('_'))));
        str.erase (0, str.find ('_') + 1);
        animals[i].setTimes (str);
    }
    for (int i = 0; i < n; i++) cout << animals[i];
    int max = animals[0].WeigthOfFoodPerDay ();
    Thu result = animals[0];
    for (int i = 1; i < n; i++) {
        if (animals[i].WeigthOfFoodPerDay () > max) {
            max = animals[i].WeigthOfFoodPerDay ();
            result = animals[i];
        }
    }
    cout << max << result;
    delete []animals;
    return 0;
}