#include <iostream>
#include <vector>

using namespace std;

class Student {
    private:
    string name;
    double math;
    double physic;
    double chemistry;
    public:
    Student () {}
    Student (string name, double math, double physic, double chemistry) {
        this->name = name;
        this->math = math;
        this->physic = physic;
        this->chemistry = chemistry;
    }
    double getMath () {
        return math;
    }
    double getPhysic () {
        return physic;
    }
    double getChemistry () {
        return chemistry;
    }
    void display () {
        cout << "Name: " << name << endl;
        cout << "Point math: " << math << endl;
        cout << "Point physic: " << physic << endl;
        cout << "Point chemistry: " << chemistry << endl;
        cout << "Average: " << avgPoint () << endl;
    }
    double avgPoint () {
        return (math + physic + chemistry) / 3;
    }
    static vector<Student> getStudentMaxAvg (vector<Student> vt) {
        vector<Student> v;
        double maxAvg = vt[0].avgPoint ();
        for (int i = 1; i < vt.size (); i++) if (vt[i].avgPoint () >= maxAvg) maxAvg = vt[i].avgPoint ();
        for (int i = 0; i < vt.size (); i++) if (vt[i].avgPoint () == maxAvg) v.push_back (vt[i]);
        return v;
    }
    static vector<Student> getStudentMaxMath (vector<Student> vt) {
        vector<Student> v;
        double maxMath = vt[0].getMath ();
        for (int i = 1; i < vt.size (); i++) if (vt[i].getMath () >= maxMath) maxMath = vt[i].getMath ();
        for (int i = 0; i < vt.size (); i++) if (vt[i].getMath () == maxMath) v.push_back (vt[i]);
        return v;
    }
    static vector<Student> getStudentMaxPhysic (vector<Student> vt) {
        vector<Student> v;
        double maxPhysic = vt[0].getPhysic ();
        for (int i = 1; i < vt.size (); i++) if (vt[i].getPhysic () >= maxPhysic) maxPhysic = vt[i].getPhysic ();
        for (int i = 0; i < vt.size (); i++) if (vt[i].getPhysic () == maxPhysic) v.push_back (vt[i]);
        return v;
    }
    static vector<Student> getStudentMaxChemistry (vector<Student> vt) {
        vector<Student> v;
        double maxChemistry = vt[0].getChemistry ();
        for (int i = 1; i < vt.size (); i++) if (vt[i].getChemistry () >= maxChemistry) maxChemistry = vt[i].getChemistry ();
        for (int i = 0; i < vt.size (); i++) if (vt[i].getChemistry () == maxChemistry) v.push_back (vt[i]);
        return v;
    }
};