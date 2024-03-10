#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Diem {
    private:
    vector<double> list_score;
    double score;
    public:
    friend istream& operator>> (istream &is, Diem &s) {
        while (is >> s.score) s.list_score.push_back (s.score);
        return is;
    }
    friend ostream& operator<< (ostream &os, Diem s) {
        for (vector<double>::iterator it = s.list_score.begin (); it != s.list_score.end (); it++) os << *it << ' ';
        return os;
    }
    double& operator[] (int i) {
        return list_score[i];
    }
    Diem& operator= (const Diem &a) {
        this->list_score = a.list_score;
        return *this;
    }
    double Average_score () {
        double result = 0.0;
        for (vector<double>::iterator it = list_score.begin (); it != list_score.end (); it++) result += *it;
        return result / list_score.size ();
    }
    Diem () {}
    Diem (vector<double> list_score) : list_score(list_score) {}
    Diem (const Diem &s) {
        this->list_score = s.list_score;
    }
    ~Diem () {}
    void setList_Score (vector<double> list_score) {
        this->list_score = list_score;
    }
    vector<double> getList_Score () {
        return list_score;
    }
    void setScore (double score) {
        this->score = score;
    }
    double getScore () {
        return score;
    }
};

class SinhVien {
    private:
    string name;
    string id;
    Diem s;
    public:
    SinhVien () {}
    SinhVien (string name, string id, Diem s) {
        this->name = name;
        this->id = id;
        this->s = s;
    }
    SinhVien (const SinhVien &st) {
        this->name = st.name;
        this->id = st.id;
        this->s = st.s;
    }
    ~SinhVien () {}
    friend istream& operator>> (istream &is, SinhVien &student) {
        getline (is, student.name);
        is >> student.id;
        is >> student.s;
        return is;
    }
    friend ostream& operator<< (ostream& os, SinhVien student) {
        os << "Ho Ten: " << student.name << endl;
        os << "Ma Sinh Vien: " << student.id << endl;
        os << "DTB: " << fixed << setprecision (1) << student.s.Average_score () << endl;
        return os;
    }
    SinhVien& operator= (const SinhVien &st) {
        this->name = st.name;
        this->id = st.id;
        this->s = st.s;
        return *this;
    }
    friend bool operator < (SinhVien s1, SinhVien s2) {
        return s1.s.Average_score () < s2.s.Average_score ();
    }
    void setName (string name) {
        this->name = name;
    }
    void setId (string id) {
        this->id = id;
    }
    void setS (Diem s) {
        this->s = s;
    }
    string getName () {
        return name;
    }
    string getId () {
        return id;
    }
    Diem getS () {
        return s;
    }
};

int main () {
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}