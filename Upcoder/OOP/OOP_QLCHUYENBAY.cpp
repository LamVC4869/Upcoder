#include <iostream>
#include <algorithm>

using namespace std;

string List[9] = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
bool hetGhe[9] = {};

class Nguoi {
    private:
    string hoTen;
    string gioiTinh;
    int namSinh;
    public:
    Nguoi () {}
    Nguoi (string name, string gender, int yob) : hoTen(name), gioiTinh(gender), namSinh(yob) {}
    void setName (string name) {
        this->hoTen = name;
    }
    string getName () {
        return hoTen;
    }
    void setGender (string gender) {
        this->gioiTinh = gender;
    }
    string getGender () {
        return gioiTinh;
    }
    void setYearOfBirth (int yearOfBirth) {
        this->namSinh = yearOfBirth;
    }
    int getYearOfBirth () {
        return namSinh;
    }
    virtual void display () {
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Gioi Tinh: " << gioiTinh << endl;
        cout << "Nam Sinh: " << namSinh << endl;
    }
};

class HanhKhach : public Nguoi {
    private:
    string viTri;
    public:
    void setPos (string pos) {
        this->viTri = pos;
    }
    string getPos () {
        return viTri;
    }
    HanhKhach () {}
    HanhKhach (string name, string gender, int yob, string pos) : Nguoi(name, gender, yob), viTri(pos) {}
    virtual void display () {
        Nguoi::display ();
        cout << "Vi tri: " << viTri;
    }
};

bool sapXep (HanhKhach p1, HanhKhach p2) {
    return p1.getPos () < p2.getPos ();
}

class ChuyenBay {
    private:
    string tenChuyenBay;
    string maChuyenBay;
    string noiDi;
    string noiDen;
    string thoiGian;
    HanhKhach hanhkhach[1000];
    int tongHanhKhach;
    public:
    friend istream& operator >> (istream &is, ChuyenBay &cb) {
        cb.tongHanhKhach = 0;
        getline (is, cb.tenChuyenBay);
        getline (is, cb.maChuyenBay);
        getline (is, cb.noiDi);
        getline (is, cb.noiDen);
        getline (is, cb.thoiGian);
        string name, gender, pos;
        int yob;
        while (getline (is, name)) {
            if (name == "-1") break;
            is >> gender >> yob >> pos;
            is.ignore ();
            cb.hanhkhach[cb.tongHanhKhach++] = HanhKhach (name, gender, yob, pos);
            for (int i = 0; i < 9; i++) if (List[i] == pos) hetGhe[i] = true;
        }
        return is;
    }
    void Find (string position) {
        bool found = false;
        for (int i = 0; i < tongHanhKhach; i++) {
            if (hanhkhach[i].getPos () == position) {
                found = true;
                hanhkhach[i].display ();
                break;
            }
        }
        if (!found) cout << 0;
    }
    void display () {
        cout << "Ten Chuyen Bay: " << tenChuyenBay << endl;
        cout << "Ma Chuyen Bay: " << maChuyenBay << endl;
        cout << "Ngay Bay: " << thoiGian << endl;
        cout << "Noi Di: " << noiDi << endl;
        cout << "Noi Den: " << noiDen << endl;
        if (tongHanhKhach == 0) cout << 0 << endl;
        else {
            sort (hanhkhach, hanhkhach + tongHanhKhach, sapXep);
            for (int i = 0; i < tongHanhKhach; i++) {
                hanhkhach[i].display ();
                cout << endl;
            }
        }
        bool dahetGhe = true;
        for (int i = 0; i < 9; i++) {
            if (!hetGhe[i]) {
                cout << List[i] << ' ';
                dahetGhe = false;
            }
        }
        if (dahetGhe) cout << "0\n";
        else cout << endl;
    }
};

int main () {
    ChuyenBay tmp;
    cin >> tmp;
    string position; cin >> position;
    tmp.display ();
    cout << position << endl;
    tmp.Find (position);
    return 0;
}