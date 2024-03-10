#include <iostream>
#define ll long long
#define endl '\n'

using namespace std;

ll Price (string nameBook) {
    ll price;
    if (nameBook == "TC") price = 18000;
    else if (nameBook == "SGK") price = 23000;
    else if (nameBook == "DNA") price = 15000;
    else if (nameBook == "TT") price = 45000;
    else if (nameBook == "TN") price = 12000;
    return price;
}

struct Book {
    string name;
    int quantity;
};

int main () {
    Book book;
    ll tienTra, res = 0;
    while (cin >> book.name) {
        if (isdigit (book.name[0])) {
            tienTra = stoll (book.name);
            break;
        }
        cin >> book.quantity;
        res += book.quantity * Price (book.name);
        cin.ignore ();
    }
    cin >> tienTra;
    cout << res << " VND" << endl;
    cout << tienTra - res << " VND";
    return 0;
}