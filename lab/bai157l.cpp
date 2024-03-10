#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Person {
    private:
    string name;
    public:
    friend istream& operator >> (istream &is, Person &p1) {
        getline (is, p1.name);
        return is;
    }
    friend ostream& operator << (ostream &os, Person p1) {
        os << "Ho Ten: " << p1.name << endl;
        return os;
    }
    void setName (string name) {
        this->name = name;
    }
    string getName () {
        return name;
    }
    
    Person () {}
    Person (string name) {
        this->name = name;
    }
    ~Person () {}
};

class Student : public Person {
    private:
    string id;
    int score;
    vector<double> list_score;
    public:
    void setId (string id) {
        this->id = id;
    }
    string getId () {
        return id;
    }
    friend istream& operator >> (istream &is, Student& student) {
        string name;
        getline (is, name);
        student.setName(name);
        is >> student.id;
        while (is >> student.score) {
            student.list_score.push_back (student.score);
        }
        is.ignore ();
        return is;
    }
    friend ostream& operator << (ostream &os, Student student) {
        os << "Ho Ten: " << student.getName () << endl;
        os << "Ma Sinh Vien: " << student.getId () << endl;
        os << "DTB: " << fixed << setprecision (1) << student.average_score () << endl;
        return os;
    }
    double average_score () {
        double result = 0.0;
        for (vector<double>::iterator it = list_score.begin (); it != list_score.end (); it++) result += *it;
        return result * 1.0 / list_score.size ();
    }
    void setScore (vector<double> v) {
        for (vector<double>::iterator it = v.begin (); it != v.end (); it++) list_score.push_back (*it);
    }
    vector<double> getList_score () {
        return list_score;
    }
    Student () {}
    Student (string name, string id, vector<double> list_score) : Person (name) {
        this->id = id;
        this->list_score = list_score;
    }
    ~Student () {}
};

class MangSinhVien {
    private:
    int size;
    vector<Student> v;
    public:
    friend istream& operator >> (istream &is, MangSinhVien &m) {
        is >> m.size;
        m.v.resize (m.size);
        is.ignore ();
        for (Student &i : m.v) {
            is >> i;
            is.clear ();
        }
        return is;
    }
    friend ostream& operator << (ostream &os, MangSinhVien m) {
        for (int i = 0; i < m.size; i++) os << m.v[i];
        return os;
    }
    Student& operator [] (int index) {
        return this->v[index];
    }
    MangSinhVien& operator = (const MangSinhVien another) {
        this->size = another.size;
        this->v.resize (this->size);
        for (int i = 0; i < this->size; i++) this->v[i] = another.v[i];
        return *this;
    }
    MangSinhVien () {}
    MangSinhVien (int size, vector<Student> v) : size(size), v(v) {}
    ~MangSinhVien () {}
    void setSize (int size) {
        this->size = size;
    }
    void setV (vector<Student> v) {
        this->v = v;
    }
    int getSize () {
        return size;
    }
    vector<Student> getV () {
        return v;
    }
    double diemTrungBinhMang () {
        double res = 0.0;
        for (int i = 0; i < this->size; i++) res += v[i].average_score ();
        return res / this->size;
    }
    Student Max_Avg () {
        Student max = this->v[0];
        for (int i = 1; i < this->size; i++) {
            if (v[i].average_score () > max.average_score ()) max = v[i];
        }
        return max;
    }
};

int main () {
    MangSinhVien a;
    cin >> a;
    cout << a.Max_Avg ();
    return 0;
}