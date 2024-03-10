#include <iostream>
#include <string>

using namespace std;

bool namNhuan (int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int Ngay[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int SoNgayTrongNam (int year) {
    return (namNhuan (year)) ? 366 : 365;
}
string NgayTrongTuan[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

struct Date {
    int ngay, thang, nam;
    string day, month;
    friend istream& operator >> (istream &is, Date &d) {
        is >> d.ngay >> d.thang >> d.nam;
        return is;
    }
    friend ostream& operator << (ostream &os, Date &d) {
        d.day = (d.ngay < 10) ? "0" + to_string (d.ngay) : to_string (d.ngay);
        d.month = (d.thang < 10) ? "0" + to_string (d.thang) : to_string (d.thang);
        os << d.day << '/' << d.month << '/' << d.nam;
        return os;
    }
    string ThuTrongNam (Date d) {
        Ngay[2] = namNhuan (d.nam) ? 29 : 28;
        if (d.thang < 3) {
            d.thang += 12;
            d.nam -= 1;
        }
        int n = (d.ngay + 2 * d.thang + (3 * (d.thang + 1))/5 + d.nam + (d.nam / 4)) % 7;
        return NgayTrongTuan[n];
    }
    int NgayThuTrongNam (Date d) {
        Date tmp = d;
        Ngay[2] = namNhuan (tmp.nam) ? 29 : 28;
        int res = tmp.ngay;
        for (int i = tmp.thang - 1; i > 0; i--) res += Ngay[i];
        return res; 
    }
    Date NgayKeTiep (Date d) {
        Date tmp = d;
        Ngay[2] = namNhuan (tmp.nam) ? 29 : 28;
        if (tmp.ngay < Ngay[tmp.thang]) {
            tmp.ngay += 1;
        } else if (tmp.ngay == Ngay[tmp.thang]) {
            if (tmp.thang < 12) {
                tmp.ngay = 1;
                tmp.thang += 1;
            } else if (tmp.thang == 12) {
                tmp.ngay = 1;
                tmp.thang = 1;
                tmp.nam += 1;
            }
        }
        return tmp;
    }
    bool operator == (Date d) {
        return this->ngay == d.ngay && this->thang == d.thang && this->nam == d.nam;
    }
    bool trungThu (Date d) {
        return this->ThuTrongNam (*this) == d.ThuTrongNam (d);
    }
    friend bool operator < (Date d1, Date d2) {
        if (d1.nam < d2.nam) return true;
        else if (d1.nam == d2.nam) {
            if (d1.thang < d2.thang) return true;
            else if (d1.thang == d2.thang) {
                if (d1.ngay < d2.ngay) return true;
            }
        }
        return false;
    }
    int TongNgayCacThang (Date d) {
        int n = d.ngay;
        Ngay[2] = namNhuan (d.nam) ? 29 : 28;
        for (int i = 1; i < d.thang; i++) n += Ngay[i];
        return n;
    }
    friend int operator - (Date d1, Date d2) {
        if (d2 < d1) swap (d1, d2);
        int result = 0;
        // int result = d2.TongNgayCacThang(d2) - d1.TongNgayCacThang(d1);
        // for (int i = d1.nam + 1; i <= d2.nam; i++) result += SoNgayTrongNam (i);
        if (d1.nam == d2.nam) {
            Ngay[2] = (namNhuan (d1.nam)) ? 29 : 28;
            for (int i = d1.thang + 1; i <= d2.thang; i++) {
                if (i == d2.thang) {
                    result += d2.ngay;
                    break;
                } else result += Ngay[i];
            }
            result += Ngay[d1.thang] - d1.ngay;
        } else {
            for (int i = d1.nam; i <= d2.nam; i++) {
                Ngay[2] = (namNhuan(i)) ? 29 : 28;
                if (i == d2.nam) {
                    for (int j = 1; j <= d2.thang - 1; j++) {
                        result += Ngay[j];
                    }
                    break;
                } else if (i == d1.nam) {
                    for (int j = d1.thang + 1; j <= 12; j++) {
                        result += Ngay[j];
                    }
                } else if (i > d1.nam && i < d2.nam) {
                    for (int j = 1; j <= 12; j++) {
                        result += Ngay[j];
                    }
                }
            }
            result += d2.ngay + Ngay[d1.thang] - d1.ngay;
        }
        return result;
    }
};

int main () {
    Date d1, d2; cin >> d1 >> d2;
    cout << d1 << ' ' << d1.ThuTrongNam (d1) << ' ' << d1.NgayThuTrongNam (d1) << ' ';
    Date nextD1 = d1.NgayKeTiep (d1);
    cout << nextD1 << ' ';
    cout << ((namNhuan (d1.nam) ? "TRUE" : "FALSE")) << endl;
    cout << d2 << ' ' << d2.ThuTrongNam (d2) << ' ' << d2.NgayThuTrongNam (d2) << ' ';
    Date nextD2 = d2.NgayKeTiep (d2);
    cout << nextD2 << ' ';
    cout << ((namNhuan (d2.nam) ? "TRUE" : "FALSE")) << endl;
    cout << ((d1.trungThu (d2) ? "TRUE" : "FALSE")) << endl;
    if (d1 < d2) cout << "1 < 2" << endl;
    else if (d1 == d2) cout << "1 = 2" << endl;
    else cout << "1 > 2" << endl;
    cout << d1 - d2;
    return 0;
}