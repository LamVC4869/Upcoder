#include <iostream>
#include <vector>

using namespace std;

class Customer {
    private:
    string name;
    int times;
    int numbers;
    int price;
    public:
    Customer () {}
    Customer (string name, int times, int numbers, int price) {
        this->name = name;
        this->times = times;
        this->numbers = numbers;
        this->price = price;
    }
    Customer (const Customer& another) {
        this->name = another.name;
        this->times = another.times;
        this->numbers = another.numbers;
        this->price = another.price;
    }
    void setName (string name) {
        this->name = name;
    }
    void setTimes (int times) {
        this->times = times;
    }
    void setNumbers (int numbers) {
        this->numbers = numbers;
    }
    void setPrice (int price) {
        this->price = price;
    }
    int getTimes () {
        return times;
    }
    int getPrice () {
        return price;
    }
    virtual int tongTien () = 0;
    virtual void display () {
        cout << "Ho Ten: " << name << endl;
        cout << "Thoi gian su dung: " << times << endl;
        cout << "So may: " << numbers << endl;
        cout << "So tien phai tra: " << tongTien () << endl;
    }
};
//Vip
class VIP_Customer : public Customer {
    private:
    int VIP_price;
    public:
    void setVIP_Price (int VIP_price) {
        this->VIP_price = VIP_price;
    }
    VIP_Customer () {}
    VIP_Customer (string name, int times, int numbers, int price) : Customer (name, times, numbers, price) {}
    VIP_Customer (const VIP_Customer& another) : Customer (another) {}
    int tongTien () {
        return (Customer::getTimes () >= 4) ? VIP_price * 4 : Customer::getPrice () * Customer::getTimes ();
    }
};

//Thường xuyên
class Regular_Customers : public Customer {
    private:
    int heSoKhuyenMai;
    public:
    void setHeSoKhuyenMai (int heSoKhuyenMai) {
        this->heSoKhuyenMai = heSoKhuyenMai;
    }
    Regular_Customers () {}
    Regular_Customers (string name, int times, int numbers, int price) : Customer (name, times, numbers, price) {}
    Regular_Customers (const Regular_Customers& another) : Customer (another) {}
    int tongTien () {
        return Customer::getTimes () * (Customer::getPrice () - heSoKhuyenMai);
    }
};
//Không thường xuyên
class Occasional_Customers : public Customer {
    private:
    int donGiaDownload;
    int dungLuongDownLoad;
    public:
    void setDungLuongDownLoad (int dungLuongDownLoad) {
        this->dungLuongDownLoad = dungLuongDownLoad;
    }
    void setDonGiaDownLoad (int donGiaDownload) {
        this->donGiaDownload = donGiaDownload;
    }
    Occasional_Customers () {}
    Occasional_Customers (string name, int times, int numbers, int price) : Customer (name, times, numbers, price) {}
    Occasional_Customers (const Occasional_Customers& another) : Customer (another) {}
    int tongTien () {
        return Customer::getTimes () * Customer::getPrice () + dungLuongDownLoad * donGiaDownload;  
    }
};

int main() {
    int n, donGia, donGiaVip, donGiaDownload, heSoKhuyenMai, dungLuongDownLoad;
    cin >> n >> donGia >> donGiaVip >> donGiaDownload;
    string Type[n];
    vector<Customer*> customers;
    for (int i = 0; i < n; i++) {
        cin >> Type[i];
        cin.ignore ();
        string name; getline (cin, name);
        int times, numbers;
        cin >> times >> numbers;
        if (Type[i] == "VIP") {
            VIP_Customer* vip = new VIP_Customer (name, times, numbers, donGia);
            vip->setVIP_Price (donGiaVip);
            customers.push_back (vip);
        } else if (Type[i] == "TX") {
            cin >> heSoKhuyenMai;
            Regular_Customers* reg = new Regular_Customers (name, times, numbers, donGia);
            reg->setHeSoKhuyenMai (heSoKhuyenMai);
            customers.push_back (reg);
        } else {
            cin >> dungLuongDownLoad;
            Occasional_Customers* occ = new Occasional_Customers (name, times, numbers, donGia);
            occ->setDonGiaDownLoad (donGiaDownload);
            occ->setDungLuongDownLoad (dungLuongDownLoad);
            customers.push_back (occ);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << '.' << " Loai khach: " << Type[i] << endl;
        customers[i]->display();
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        delete customers[i];
    }
    return 0;
}
