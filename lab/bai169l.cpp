#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

class Student {
    private:
    string name;
    double GPA;
    public:
    void setName (string name) {
        this->name = name;
    }
    void setGPA (double point) {
        this->GPA = point;
    }
    string getName () {
        return name;
    }
    double getGPA () {
        return GPA;
    }
    Student () {}
    Student (string name, double GPA) : name(name), GPA(GPA) {}
    ~Student () {}
    friend istream& operator >> (istream &is, Student &student) {
        getline (is, student.name);
        is >> student.GPA;
        is.ignore ();
        return is;
    }
    friend ostream& operator << (ostream &os, Student student) {
        os << student.name;
        return os << endl;
    }
};

class LOPHOC : public Student {
    private:
    string ClassName;
    int size;
    vector<Student> student;
    public:
    LOPHOC () {}
    LOPHOC (string ClassName, int size, vector<Student> student) : ClassName(ClassName), size(size), student(student) {}
    ~LOPHOC () {}
    friend istream& operator >> (istream &is, LOPHOC &lophoc) {
        is >> lophoc.ClassName >> lophoc.size;
        lophoc.student.resize(lophoc.size);
        is.ignore ();
        for (int i = 0; i < lophoc.size; i++) {
            is >> lophoc.student[i];
        }
        return is;
    }
    friend ostream& operator << (ostream &os, LOPHOC lophoc) {
        os << lophoc.ClassName << endl;
        for (int i = 0; i < lophoc.size; i++) os << lophoc.student[i];
        return os << endl;
    }
    int getSize () {
        return size;
    }
    string getClassName () {
        return ClassName;
    }
    static string GPALargest (vector<LOPHOC> lophoc) {
        Student max = lophoc[0].student[0];
        for (int i = 0; i < lophoc.size (); i++) {
            for (int j = 0; j < lophoc[i].size; j++) {
                if (lophoc[i].student[j].getGPA () > max.getGPA ()) max = lophoc[i].student[j];
            }
        }
        return max.getName ();
    }
};

string chiSoDongNhat (vector<LOPHOC> v) {
    LOPHOC max = v[0];
        for (int i = 1; i < v.size (); i++) {
            if (v[i].getSize () > max.getSize ()) max = v[i];
        }
    return max.getClassName ();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n; cin >> n;
    vector<LOPHOC> lophoc (n);
    for (int i = 0; i < n; i++) cin >> lophoc[i];
    for (int i = 0; i < n; i++) {
        cout << lophoc[i];
    }
    cout << chiSoDongNhat (lophoc) << endl << LOPHOC::GPALargest(lophoc) << endl;
    return 0;
}