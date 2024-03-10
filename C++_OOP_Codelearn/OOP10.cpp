#pragma once
#include <iostream>
#include <vector>

using namespace std;

class People {
    private:
    string name;
    int age;
    string job;
    string id;
    public:
    People () {}
    People (string name, int age, string job, string id) {
        this->name = name;
        this->age = age;
        this->job = job;
        this->id = id;
    }
    string getName () {
        return name;
    }
    int getAge () {
        return age;
    }
    string getJob () {
        return job;
    }
    string getId () {
        return id;
    }
    void display () {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Job: " << job << endl;
        cout << "Id: " << id << endl;
    }
};

class Family {
    private:
    string nameF;
    string status;
    string add;
    vector<People> p;
    public:
    Family () {}
    Family (string nameF, string status, string add, vector<People> p) {
        this->nameF = nameF;
        this->status = status;
        this->add = add;
        this->p = p;
    }
    string getNameF () {
        return nameF;
    }
    string getStatus () {
        return status;
    }
    string getAdd () {
        return add;
    }
    vector<People> getP () {
        return p;
    }
    void display () {
        cout << "householder's name: " << nameF << endl;
		cout << "Number Member: " << p.size() << endl;
		cout << "Address: " << add << endl;
		cout << "Status: " << status << endl;
		cout << "List Information Member" << endl;
        for (int i = 0; i < p.size (); i++) p[i].display ();
    }
    static vector<Family> getPoorHousehold (vector<Family> fa) {
        vector<Family> v;
        for (int i = 0; i < fa.size (); i++) if (fa[i].getStatus () == "poor") v.push_back (fa[i]);
        return v;
    }
    static vector<Family> findFamilySurname (vector<Family> fa, string surename) {
        vector<Family> v;
        for (int i = 0; i < fa.size (); i++) if (fa[i].getNameF () == surename) v.push_back (fa[i]);
        return v;
    }
};

class Group {
    private:
    string nameGr;
    vector<Family> f;
    public:
    Group () {}
    Group (string nameGr, vector<Family> f) {
        this->nameGr = nameGr;
        this->f = f;
    }
    string getNameGr () {
        return nameGr;
    }
    vector<Family> getF () {
        return f;
    }
    int getNumberFamily () {
        return f.size ();
    }
    static double avgAgeGroup (Group v) {
        vector<Family> F = v.getF ();
        int sum = 0;
        int n = 0;
        for (int i = 0; i < F.size (); i++) {
            vector<People> P = F[i].getP ();
            for (int j = 0; j < P.size (); i++) {
                sum += P[i].getAge ();
            }
            n += P.size ();
        }
        return sum / n;
    }
    static vector<People> getPeopleHaveNotJob (Group g) {
        vector<Family> F = g.getF ();
        vector<People> v;
        for (int i = 0; i < F.size (); i++) {
            vector<People> P = F[i].getP ();
            for (int j = 0; j < P.size (); j++) if (P[j].getJob ().empty ()) v.push_back (P[j]);
        }
        return v;
    }
};