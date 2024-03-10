#include <iostream>
#include <vector>
#define int unsigned long long

using namespace std;

class Person {
    private:
    string name;
    string id;
    string sdt;
    public:
    friend istream& operator >> (istream &is, Person &person) {
        getline(is, person.name);
        is >> person.id >> person.sdt;
        return is;
    }
    void setName (string name) {
        this->name = name;
    }
    string getName () {
        return name;
    }
    void setID (string id) {
        this->id = id;
    }
    string getID () {
        return id;
    }
    void setSDT (string sdt) {
        this->sdt = sdt;
    }
    string getSDT () {
        return sdt;
    }
    virtual void display () {
        cout << "Ten khach hang: " << name << endl;
        cout << "Ma khach hang: " << id << endl;
        cout << "So dien thoai: " << sdt << endl;
    }
};

int chiPhiGoiTap (int choose) {
    if (choose == 3) return 3000000;
    else if (choose == 2) return 2100000;
    return 350000;
}

class Customer : public Person {
    private:
    int type;
    int goiTap;
    int Time;
    string NgayDK;
    public:
    int ThanhTien () {
        return (type == 1) ? chiPhiGoiTap (Time) * 0.85 : chiPhiGoiTap (Time);
    }
    string TypeCustomer (int type) {
        return type == 1 ? "VIP" : "NOR";
    }
    string GoiTap (int goiTap) {
        return (goiTap == 1) ? "Gym" : "Yoga";
    }
    string hanDK (int Time) {
        if (Time == 1) return "1 thang";
        else if (Time == 2) return "6 thang";
        return "1 nam";
    }
    int getGoiTap () {
        return goiTap;
    }
    friend istream& operator >> (istream &is, Customer &customer) {
        Person tmp;
        is >> customer.type;
        is.ignore ();
        is >> tmp;
        customer.setName (tmp.getName ());
        customer.setID (tmp.getID ());
        customer.setSDT (tmp.getSDT ());
        is >> customer.NgayDK >> customer.goiTap >> customer.Time;
        return is;
    }
    void display () {
        cout << "Loai khach hang: " << TypeCustomer (type) << endl;
        Person::display ();
        cout << "Ngay dang ký: " << NgayDK << endl;
        cout << "Goi tap: " << GoiTap (goiTap) << endl;
        cout << "So thoi gian dang ky tap: " << hanDK (Time) << endl;
        cout << "Thanh tien: " << ThanhTien () << endl;
    }
};

signed main () {
    int n; cin >> n;
    cin.ignore ();
    vector<Customer> v(n);
    for (Customer &i : v) cin >> i;
    cout << "So luong khach hang: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << "Khach hang thu: " << i + 1 << endl;
        v[i].display ();
        cout << endl;
    }
    return 0;
}