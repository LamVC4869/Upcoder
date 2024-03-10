#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Food {
    private:
    string name;
    double price;
    public:
    Food () {}
    Food (string name, double price) {
        this->name = name;
        this->price = price;
    }
    void setName (string name) {
        this->name = name;
    }
    void setPrice (double price) {
        this->price = price;
    }
    string getName () {
        return name;
    }
    double getPrice () {
        return price;
    }
    void display () {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

class CannedFood : public Food{
    private:
    int numberBox;
    public:
    CannedFood () {}
    CannedFood (string name, double price, int numberBox) : Food (name, price) {
        this->numberBox = numberBox;
    }
    void setNumberBox (int numberBox) {
        this->numberBox = numberBox;
    }
    int getNumberBox () {
        return numberBox;
    }
    void display () {
        Food::display ();
        cout << "Number box: " << numberBox << endl; 
    }
    static void sortNumberBox (vector<CannedFood> &vt) {
        for (int i = 0; i < vt.size () - 1; i++) {
            for (int j = i + 1; j < vt.size (); j++) if (vt[i].numberBox > vt[j].numberBox) swap (vt[i], vt[j]);
        }
    }
};

class NonCFood : public Food {
    private:
    double weight;
    public:
    NonCFood () {}
    NonCFood (string name, double price, double weight) : Food (name, price) {
        this->weight = weight;
    }
    void setWeight (double weight) {
        this->weight = weight;
    }
    double getWeight () {
        return weight;
    }
    void display () {
        Food::display ();
        cout << "Weight: " << weight << endl;
    }
    static void sortWeight (vector<NonCFood> &vt) {
        for (int i = 0; i < vt.size () - 1; i++) {
            for (int j = i + 1; j < vt.size (); j++) if (vt[i].weight > vt[j].weight) swap (vt[i], vt[j]);
        }
    }
};