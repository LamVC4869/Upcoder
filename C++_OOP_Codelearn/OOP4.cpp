#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Transport {
    private:
    string manufacturer;
    string name;
    int year;
    int speed;
    public:
    Transport () {}
    Transport (string manufacturer, string name, int year, int speed) {
        this->manufacturer = manufacturer;
        this->name = name;
        this->year = year;
        this->speed = speed;
    }
    string getmanufacturer () {
        return manufacturer;
    }
    string getName () {
        return name;
    }
    int getYear () {
        return year;
    }
    int getSpeed () {
        return speed;
    }
    void display () {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Name: " << name << endl;
        cout << "Year Of Manufacturer: " << year << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Transport {
    private:
    int numberSeat;
    string engineType;
    public:
    Car () {}
    Car (string manufacturer, string name, int year, int speed, int numberSeat, string engineType) : Transport (manufacturer, name, year, speed) {
        this->numberSeat = numberSeat;
        this->engineType = engineType;
    }
    int getNumberSeat () {
        return numberSeat;
    }
    string getEngineType () {
        return engineType;
    }
    double getSpeedBasic () {
        return getSpeed () / numberSeat;
    }
    void display () {
        Transport::display ();
        cout << "Number Seat: " << numberSeat << endl;
        cout << "Engine Type: " << engineType << endl;
        cout << "Speed Basic: " << getSpeedBasic () << endl;
    }
    static vector<Car> getCarHaveMaxSpeedBasic (vector<Car> vt) {
        vector<Car> v;
        double max = vt[0].getSpeedBasic ();
        for (int i = 1; i < vt.size (); i++) if (vt[i].getSpeedBasic () > max) max = vt[i].getSpeedBasic ();
        for (int i = 0; i < vt.size (); i++) if (vt[i].getSpeedBasic () == max) v.push_back (vt[i]);
        return v;
    }
    static vector<Car> getCarHaveMaxSeat (vector<Car> vt) {
        vector<Car> v;
        int max = vt[0].numberSeat;
        for (int i = 1; i < vt.size (); i++) if (vt[i].numberSeat > max) max = vt[i].numberSeat;
        for (int i = 0; i < vt.size (); i++) if (vt[i].numberSeat == max) v.push_back (vt[i]);
        return v;
    }
};