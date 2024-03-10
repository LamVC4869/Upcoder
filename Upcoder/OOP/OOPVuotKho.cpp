#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Resident {
    private:
    string name;
    int age;
    int apartmentNumber;
    string phoneNumber;
    string email;
    public:
    Resident () : name(""), age(0), apartmentNumber(0), phoneNumber(""), email("") {}
    Resident (string name, int age, int apartmentNumber, string phoneNumber, string email) : name(name), age(age), apartmentNumber(apartmentNumber), phoneNumber(phoneNumber), email(email) {}
    ~Resident () {}
    friend istream& operator >> (istream &is, Resident &res) {
        getline (is, res.name);
        is >> res.age >> res.apartmentNumber;
        is >> res.phoneNumber >> res.email;
        is.ignore ();
        return is;
    }
    void setName (string name) {
        this->name = name;
    }
    void setAge (int age) {
        this->age = age;
    }
    void setApartmentNumber (int apartmentNumber) {
        this->apartmentNumber = apartmentNumber;
    }
    void setPhoneNumber (string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    void setEmail (string email) {
        this->email = email;
    }
    string getName () {
        return name;
    }
    int getAge () {
        return age;
    }
    int getAparyMentNumber () {
        return apartmentNumber;
    }
    string getPhoneNumber () {
        return phoneNumber;
    }
    string getEmail () {
        return email;
    }
    virtual void display () {
        cout << "Ten      : " << name << endl;
        cout << "Tuoi     : " << age << endl;
        cout << "So nha   : " << apartmentNumber << endl;
        cout << "SDT      : " << phoneNumber << endl;
        cout << "Email    : " << email << endl;
    }
};

class Owner : public Resident {
    private:
    int purchaseYear;
    public:
    bool operator <= (int year) {
        return this->purchaseYear <= year;
    }
    Owner () : Resident (), purchaseYear(0) {}
    Owner (string name, int age, int apartmentNumber, string phoneNumber, string email, int purchaseYear) : Resident (name, age, apartmentNumber, phoneNumber, email), purchaseYear(purchaseYear) {}
    ~Owner () {}
    friend istream& operator >> (istream &is, Owner &o) {
        string name;
        int age;
        int apartmentNumber;
        string phoneNumber;
        string email;
        getline (is, name);
        is >> age >> apartmentNumber;
        is >> phoneNumber >> email;
        is >> o.purchaseYear;
        is.ignore ();
        o.setName(name), o.setAge(age), o.setApartmentNumber(apartmentNumber), o.setPhoneNumber(phoneNumber), o.setEmail(email);
        return is;
    }
    void display () {
        Resident::display ();
        cout << "Nam mua  : " << purchaseYear << endl;
    }
    void setPurchaseYear (int purchaseYear) {
        this->purchaseYear = purchaseYear;
    }
    int getPurchaseYear () {
        return this->purchaseYear;
    }
};

class Renter : public Resident {
    private:
    double price;
    public:
    bool operator >= (double money) {
        return this->price >= money;
    }
    Renter () : Resident (), price(0) {}
    Renter (string name, int age, int apartmentNumber, string phoneNumber, string email, double price) : Resident (name, age, apartmentNumber, phoneNumber, email), price(price) {}
    ~Renter () {}
    friend istream& operator >> (istream &is, Renter &r) {
        string name;
        int age;
        int apartmentNumber;
        string phoneNumber;
        string email;
        getline (is, name);
        is >> age >> apartmentNumber;
        is >> phoneNumber >> email;
        is >> r.price;
        is.ignore ();
        r.setName(name), r.setAge(age), r.setApartmentNumber(apartmentNumber), r.setPhoneNumber(phoneNumber), r.setEmail(email);
        return is;
    }
    void setPrice (double price) {
        this->price = price;
    }
    double getPrice () {
        return this->price;
    }
    void display () {
        Resident::display ();
        cout << "Gia thue : " << price << " trieu" << endl;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int requestType, year, m, n;
    double money;
    cin >> m >> n;
    cin.ignore ();
    vector<Owner> o(m);
    vector<Renter> r(n);
    if (!o.empty ()) {
        for (Owner &i : o) cin >> i;
    }
    if (!r.empty ()) {
        for (Renter &i : r) cin >> i;
    }
    cin >> requestType;
    (requestType == 0) ? cin >> year : cin >> money;
    if (requestType == 0) {
        cout << "Cac can ho da ban den nam " << year << ": " << endl;
        vector<Owner> res;
        for (int i = 0; i < m; i++) if (o[i] <= year) res.push_back (o[i]);
        for (int i = 0; i < res.size (); i++) {
            cout << '#' << i + 1 << endl;
            res[i].display ();
        }
        if (res.empty ()) cout << "Khong tim thay!";
    } else {
        cout << "Cac can ho co gia tu " << money << " trieu: " << endl;
        vector<Renter> res;
        for (int i = 0; i < n; i++) if (r[i] >= money) res.push_back (r[i]);
        for (int i = 0; i < res.size (); i++) {
            cout << '#' << i + 1 << endl;
            res[i].display ();
        }
        if (res.empty ()) cout << "Khong tim thay!";
    }
    return 0;
}