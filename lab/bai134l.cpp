#include <iostream>
#include <vector>

using namespace std;

class Bank;

class Account {
    private:
    string name;
    int balance;
    public:
    string geName () {
        return name;
    }
    int getBalance () {
        return balance;
    }
    friend Bank;
};

class Bank {
    private:
    vector<Account> accounts;
    public:
    void add_accounts (string name, int balance) {
        Account new_account;
        new_account.name = name;
        new_account.balance = balance;
        accounts.push_back (new_account);
    }
    void get_account (string name) {
        int index = -1;
        for (int i = 0; i < accounts.size (); i++) {
            if (this->accounts[i].name == name) {
                index = i; break;
            }
        }
        if (index == -1) cout << "Not found!" << endl;
        else {
            cout << "Name: " << accounts[index].name << endl;
            cout << "Balance: " << accounts[index].balance << endl;
        }
    }
};

int main () {
    Bank b;
    b.add_accounts ("Lam", 10000);
    b.add_accounts ("Han", 3000);
    b.get_account ("Lam1");
    return 0;
}