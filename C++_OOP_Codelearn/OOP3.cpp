#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Subject {
    private:
    string nameSub;
    double point;
    int numberCredit;
    long money;
    public:
    Subject () {}
    Subject (string nameSub, double point, int numberCredit, long money) {
        this->nameSub = nameSub;
        this->point = point;
        this->numberCredit = numberCredit;
        this->money = money;
    }
    string getNameSub () {
        return nameSub;
    }
    int getNumberCredit () {
        return numberCredit;
    }
    long getMoney () {
        return money;
    }
    double getPoint () {
        return point;
    }
    void display () {
        cout << "Name Subject: " << nameSub << endl;
        cout << "Number Credit: " << numberCredit << endl;
        cout << "Money Of One Credit: " << money << endl;
    }
};

class Student {
    private:
    string id;
    string name;
    vector<Subject> s;
    public:
    Student () {}
    Student (string id, string name, vector<Subject> s) {
        this->id = id;
        this->name = name;
        this->s = s;
    }
    string getId () {
        return id;
    }
    string getName () {
        return name;
    }
    vector<Subject> getS () {
        return s;
    }
    long getSumMoney () {
        long sum = 0;
        for (int i = 0; i < s.size (); i++) sum += s[i].getMoney () * s[i].getNumberCredit ();
        return sum; 
    }
    double avgPoint () {
        double result = 0.0;
        int sum = 0;
        for (int i = 0; i < s.size (); i++) {
            result += (s[i].getPoint () + s[i].getNumberCredit ());
            sum += s[i].getNumberCredit ();
        }
        return result / sum;
    }
    void display () {
        cout << "Id: " << id << endl;
        cout << "Name Student: " << name << endl; 
        cout << "List Subject" << endl;
        for (int i = 0; i < s.size (); i++) s[i].display ();
        cout << "Sum Money Have To Pay: " << getSumMoney () << endl;
        cout << "Average Point: " << avgPoint () << endl;
    }
};