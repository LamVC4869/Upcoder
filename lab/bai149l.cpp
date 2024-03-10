#include <iostream>
#define ll long long

using namespace std;

class TraSua {
    protected:
    string name;
    ll price;
    ll quantity;
    string tp;
    string hsd;
    public:
    virtual void display () {
        cout << "Ten: " << this->name << endl;
        cout << "Gia: " << this->price << endl;
        cout << "So luong: " << this->quantity << endl;
        cout << "Thanh phan: " << this->tp << endl;
        cout << "Han su dung: " << this->hsd << endl;
        cout << endl;
    }
    ll tongTien () {
        return this->price * this->quantity;
    }
};

class TraSuaChanChau : public TraSua {
    public:
    TraSuaChanChau () {}
    ~TraSuaChanChau () {}
    friend istream& operator >> (istream &is, TraSuaChanChau &tscc) {
        is.ignore ();
        getline (is, tscc.name);
        is >> tscc.price >> tscc.quantity;
        is.ignore ();
        getline (is, tscc.tp);
        is >> tscc.hsd;
        return is;
    }
    void display () {
        cout << "Thong tin cua tra sua chan chau:" << endl;
        TraSua::display ();
    }
    void TongTien () {
        cout << "Tong tien cua tra sua chan chau: " << tongTien () << endl;
    }
};

class TraSuaSocola : public TraSua {
    public:
    TraSuaSocola () {}
    ~TraSuaSocola () {}
    friend istream& operator >> (istream &is, TraSuaSocola &tsscl) {
        is.ignore ();
        getline (is, tsscl.name);
        is >> tsscl.price >> tsscl.quantity;
        is.ignore ();
        getline (is, tsscl.tp);
        is >> tsscl.hsd;
        return is;
    }
    void display () {
        cout << "Thong tin cua tra sua socola:" << endl;
        TraSua::display ();
    }
    void TongTien () {
        cout << "Tong tien cua tra sua socola: " << tongTien () << endl;
    }
};

class TraSuaDau : public TraSua {
    public:
    TraSuaDau () {}
    ~TraSuaDau () {}
    friend istream& operator >> (istream &is, TraSuaDau &tsd) {
        is.ignore ();
        getline (is, tsd.name);
        is >> tsd.price >> tsd.quantity;
        is.ignore ();
        getline (is, tsd.tp);
        is >> tsd.hsd;
        return is;
    }
    void display () {
        cout << "Thong tin cua tra sua dau:" << endl;
        TraSua::display ();
    }
    void TongTien () {
        cout << "Tong tien cua tra sua dau: " << tongTien () << endl;
    }
};

int main () {
    TraSuaChanChau a;
    TraSuaSocola b;
    TraSuaDau c;
    cin >> a >> b >> c;
    a.display ();
    b.display ();
    c.display ();
    a.TongTien ();
    b.TongTien ();
    c.TongTien ();
    return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class TraSua
{
	string ten;
	int gia;
	int soLuong;
	string thanhPhan;
	string HSD;
public:
	string getTen()
	{
		return ten;
	}
	int getGia()
	{
		return gia;
	}
	int getSoLuong()
	{
		return soLuong;
	}
	string getThanhPhan()
	{
		return thanhPhan;
	}
	string getHSD()
	{
		return HSD;
	}
	void setTen(string _ten)
	{
		ten = _ten;
	}
	void setGia(int _gia)
	{
		gia = _gia;
	}
	void setSoLuong(int _soLuong)
	{
		soLuong = _soLuong;
	}
	void setThanhPhan(string _thanhPhan)
	{
		thanhPhan = _thanhPhan;
	}
	void setHSD(string _HSD)
	{
		HSD = _HSD;
	}
	TraSua()
	{
		ten = "";
		gia = 0;
		soLuong = 0;
		thanhPhan = "";
		HSD = "00/00/0000";
	}
	TraSua(string _ten, int _gia, int _soLuong, string _thanhPhan, string _HSD)
	{
		ten = _ten;
		gia = _gia;
		soLuong = _soLuong;
		thanhPhan = _thanhPhan;
		HSD = _HSD;
	}
	TraSua(const TraSua& t)
	{
		ten = t.ten;
		gia = t.gia;
		soLuong = t.soLuong;
		thanhPhan = t.thanhPhan;
		HSD = t.HSD;
	}
	~TraSua() {};
	virtual void Nhap()
	{
		getline(cin, ten);
		cin >> gia >> soLuong;
		cin.ignore();
		getline(cin, thanhPhan);
		getline(cin, HSD);
	}
};

class TraSuaTranChau : public TraSua
{
public:
	friend istream& operator >>(istream& is, TraSuaTranChau& tc)
	{
		TraSua& t = tc;
		t.Nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os, TraSuaTranChau tc)
	{
		os << "Thong tin cua tra sua tran chau:" << endl;
		os << "Ten: " << tc.getTen() << endl;
		os << "Gia: " << tc.getGia() << endl;
		os << "So luong: " << tc.getSoLuong() << endl;
		os << "Thanh phan: " << tc.getThanhPhan() << endl;
		os << "Han su dung: " << tc.getHSD() << endl;
		return os;
	}
	int tongTien()
	{
		return getSoLuong() * getGia();
	}
};

class TraSuaSocola : public TraSua
{
public:
	friend istream& operator >>(istream& is, TraSuaSocola& s)
	{
		TraSua& t = s;
		t.Nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os, TraSuaSocola s)
	{
		os << "Thong tin cua tra sua socola:" << endl;
		os << "Ten: " << s.getTen() << endl;
		os << "Gia: " << s.getGia() << endl;
		os << "So luong: " << s.getSoLuong() << endl;
		os << "Thanh phan: " << s.getThanhPhan() << endl;
		os << "Han su dung: " << s.getHSD() << endl;
		return os;
	}
	int tongTien()
	{
		return getSoLuong() * getGia();
	}
};

class TraSuaDau : public TraSua
{
public:
	friend istream& operator >>(istream& is, TraSuaDau& d)
	{
		TraSua& t = d;
		t.Nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os, TraSuaDau d)
	{
		os << "Thong tin cua tra sua dau:" << endl;
		os << "Ten: " << d.getTen() << endl;
		os << "Gia: " << d.getGia() << endl;
		os << "So luong: " << d.getSoLuong() << endl;
		os << "Thanh phan: " << d.getThanhPhan() << endl;
		os << "Han su dung: " << d.getHSD() << endl;
		return os;
	}
	int tongTien()
	{
		return getSoLuong() * getGia();
	}
};

int main()
{
	TraSuaTranChau tc;
	TraSuaSocola s;
	TraSuaDau d;
	cin >> tc;
	cin >> s;
	cin >> d;
	cout << tc << endl;
	cout << s << endl;
	cout << d << endl;
	cout << "Tong tien cua tra sua tran chau: " << tc.tongTien() << endl;
	cout << "Tong tien cua tra sua socola: " << s.tongTien() << endl;
	cout << "Tong tien cua tra sua dau: " << d.tongTien() << endl;
	return 0;
}
*/