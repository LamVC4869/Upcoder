#include <iostream>

using namespace std;

struct Ngay {
    int ngay, thang, nam;
    friend istream& operator >> (istream &is, Ngay& t) {
        is >> t.ngay >> t.thang >> t.nam;
        return is;
    }
    friend ostream& operator << (ostream &os, Ngay t) {
        if (t.ngay < 10) os << 0;
        os << t.ngay << '/';
        if (t.thang < 10) os << 0;
        os << t.thang << '/';
        os << t.nam;
        return os;
    }
    bool operator == (Ngay another) {
        return this->ngay == another.ngay && this->thang == another.thang && this->nam == another.nam;
    }
};

struct Time {
    int gio, phut;
    friend istream& operator >> (istream &is, Time &t) {
        is >> t.gio >> t.phut;
        return is;
    }
    friend ostream& operator << (ostream &os, Time t) {
        os << t.gio << ':';
        if (t.phut < 10) os << 0;
        os << t.phut;
        return os;
    }
};

struct ChuyenBay {
    string id;
    Ngay ngaybay;
    Time giobay;
    string noiden;
    friend istream& operator >> (istream &is, ChuyenBay &cb) {
        is >> cb.id >> cb.ngaybay >> cb.giobay;
        is.ignore ();
        getline (is, cb.noiden);
        return is;
    }
    friend ostream& operator << (ostream &os, ChuyenBay cb) {
        os << cb.id << endl << cb.ngaybay << endl;
        os << cb.giobay << endl << cb.noiden;
        return os << endl;
    }
    static Ngay ngayNhieuChuyenBayNhat (ChuyenBay arr[], int n) {
        Ngay res = arr[0].ngaybay;
        int cnt[n], index;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i].ngaybay == arr[j].ngaybay) cnt[i]++;
            }
        }
        int max = cnt[0];
        for (int i = 1; i < n; i++) {
            if (cnt[i] > max) {
                max = cnt[i];
                res = arr[i].ngaybay;
            }
        }
        return res;
    }
};

int main () {
    int n; cin >> n;
    ChuyenBay chuyenbay[n];
    for (int i = 0; i < n; i++) cin >> chuyenbay[i];
    string maChuyenBay; cin >> maChuyenBay;
    for (int i = 0; i < n; i++) cout << chuyenbay[i];
    cout << ChuyenBay::ngayNhieuChuyenBayNhat (chuyenbay, n) << endl;
    for (int i = 0; i < n; i++) {
        if (chuyenbay[i].id == maChuyenBay) {
            cout << chuyenbay[i];
            break;
        }
    }
    return 0;
}