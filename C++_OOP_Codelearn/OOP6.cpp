#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Person {
    private:
    string name;
    int age;
    string add;
    string tel;
    string sex;
    public:
    Person () {} 
    Person (string name, int age, string add, string tel, string sex) {
        this->name = name;
        this->age = age;
        this->add = add;
        this->tel = tel;
        this->sex = sex;
    }
    string getName () {
        return name;
    }
    int getAge () {
        return age;
    }
    string getAdd () {
        return add;
    }
    string getTel () {
        return tel;
    }
    string getSex () {
        return sex;
    }
    void display () {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Add: " << add << endl;
        cout << "Tel: " << tel << endl;
    }
    virtual long salary () = 0;
    static vector<Person*> findPerson (vector<Person*> p) {
        vector<Person*> v;
        for (int i = 0; i < p.size (); i++) if (p[i]->getAdd () == "HN") v.push_back (p[i]);
        return v;
    }
};

class EmployeePT : public Person {
    private:
    int hour;
    long money;
    public:
    EmployeePT () {}
    EmployeePT (string name, int age, string add, string tel, string sex, int hour, long money) : Person (name, age, add, tel, sex) {
        this->hour = hour;
        this->money = money;
    }
    int getHour () {
        return hour;
    }
    long getMoney () {
        return money;
    }
    virtual void display () {
        cout << "Employee Prt Time" << endl;
        Person::display ();
        cout << "Hour: " << hour << endl;
        cout << "Money: " << money << endl;
        cout << "Salary: " << salary () << endl;
    }
    long salary () {
        return hour * money;
    }
    static vector<EmployeePT> getMaxSalary (vector<EmployeePT> pt) {
        vector<EmployeePT> v;
        long max = pt[0].salary ();
        for (int i = 1; i < pt.size (); i++) if (pt[i].salary () > max) max = pt[i].salary ();
        for (int i = 0; i < pt.size (); i++) if (pt[i].salary () == max) v.push_back (pt[i]);
        return v;
    }
};

class EmployeeFT : public Person {
    private:
    int day;
    long money;
    public:
    EmployeeFT () {}
    EmployeeFT (string name, int age, string add, string tel, string sex, int day, long money) : Person (name, age, add, tel, sex) {
        this->day = day;
        this->money = money;
    }
    int getDay () {
        return day;
    }
    long getMoney () {
        return money;
    }
    long salary () {
        return day * money;
    }
    virtual void display () {
        cout << "Employee Full Time" << endl;
        Person::display ();
        cout << "Day: " << day << endl;
        cout << "Money: " << money << endl;
        cout << "Salary: " << salary () << endl;
    }
    static vector<EmployeeFT> getMaxSalary (vector<EmployeeFT> ft) {
        long max = ft[0].salary ();
        vector<EmployeeFT> v;
        for (int i = 1; i < ft.size (); i++) if (ft[i].salary () > max) max = ft[i].salary ();
        for (int i = 0; i < ft.size (); i++) if (ft[i].salary () == max) v.push_back (ft[i]);
        return v;
    }
};