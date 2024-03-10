#include <iostream>
#include <iomanip>
#include <sstream>
#define endl "\n"

using namespace std;

class BankAccount {
    private:
    string ID;
    string CustomerName;
    string IDCardNumber;
    double Balance;
    public:
    void setBalance (double Money) {
        this->Balance = Money;
    }
    double getBalance () {
        return Balance;
    }
    virtual double WithdrawLimit () = 0;
    BankAccount () : ID("000000"), CustomerName("No name"), IDCardNumber("xxx"), Balance(0) {}
    BankAccount (string id, string customerName, string idCardNumber, double Money) : ID(id), CustomerName(customerName), IDCardNumber(idCardNumber), Balance(Money) {}
    virtual bool Withdraw (double withdrawmoney) {
        if (withdrawmoney <= WithdrawLimit ()) {
            this->Balance -= withdrawmoney;
            return true;
        }
        return false;
    }
    virtual double Deposit (double depositmoney) {
        Balance += depositmoney;
        return Balance;
    }
    void setID (string id) {
        this->ID = id;
    }
    void setCustomerName (string CustomerName) {
        this->CustomerName = CustomerName;
    }
    void setIDCard (string IDCard) {
        this->IDCardNumber = IDCard;
    }
    string toString () {
        string result;
        stringstream ss;
        ss << "{" << this->ID << "}:{" << this->CustomerName << "}:{" << to_string (int(this->Balance)) << "}"; 
        return ss.str ();
    }
};

class CheckingAccount : public BankAccount {
    private:
    double OverDraftLimit;
    public:
    double WithdrawLimit () {
        return getBalance () + this->OverDraftLimit;
    }
    CheckingAccount () : BankAccount () {
        this->OverDraftLimit = 50000;
    }
    CheckingAccount (string id, string customerName, string idCardNumber, double Money, double OverDraftLimit) : BankAccount(id, customerName, idCardNumber, Money), OverDraftLimit(OverDraftLimit) {}
    bool Withdraw (double depositmoney) {
        if (depositmoney <= WithdrawLimit ()) {
            this->setBalance (this->getBalance() - depositmoney);
            return true;
        }
        return false;
    }
    void setOverDraftLimit (double OverDraftLimit) {
        this->OverDraftLimit = OverDraftLimit;
    }
};

class SavingAccount : public BankAccount {
    private:
    double InterestRate;
    double InterestMoney;
    public:
    double WithdrawLimit () {
        return this->getBalance ();
    }
    SavingAccount (string id, string customerName, string idCardNumber, double Money) : BankAccount(id, customerName, idCardNumber, Money) {}
    SavingAccount () : BankAccount () {}
    bool Withdraw (double depositmoney) {
        if (depositmoney <= WithdrawLimit ()) {
            this->setBalance (this->getBalance() - depositmoney);
            return true;
        }
        return false;
    }
    double Deposit (double depositmoney) {
        this->setBalance(this->getBalance() + depositmoney);
        if (this->getBalance() < 1000000) this->InterestRate = 0.1;
        else if (this->getBalance() < 50000000) this->InterestRate = 0.3;
        else if (this->getBalance() < 200000000) this->InterestRate = 0.5;
        else if (this->getBalance() < 1000000000) this->InterestRate = 1;
        else this->InterestRate = 1.94;
        this->InterestMoney = this->InterestRate * this->getBalance();
        this->setBalance((this->InterestRate + 1) * this->getBalance());
        return getBalance ();
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    CheckingAccount a;
    SavingAccount b;
    char typeAccount; cin >> typeAccount;
    double soTienCanRut;
    if (typeAccount == 'C') {
        string str;
        cin >> str;
        a.setID (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        a.setCustomerName (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        a.setIDCard (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        a.setBalance (stod (str.substr (0, str.find ('/'))));
        str = str.substr (str.find ('/') + 1);
        a.setOverDraftLimit (stod (str));
        cin >> soTienCanRut;
        cout << a.toString () << endl;
        if (a.Withdraw (soTienCanRut)) {
            cout << "Yes " << a.toString () << endl;
        } else cout << "No" << endl;
        cout << "Checking Account";
    } else {
        string str;
        cin >> str;
        b.setID (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        b.setCustomerName (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        b.setIDCard (str.substr (0, str.find ('/')));
        str = str.substr (str.find ('/') + 1);
        b.setBalance (stod (str));
        cin >> soTienCanRut;
        cout << b.toString () << endl;
        if (b.Withdraw (soTienCanRut)) {
            cout << "Yes " << b.toString () << endl;
        } else cout << "No" << endl;
        b.setBalance (b.Deposit (0));
        cout << b.toString ();
    }
    return 0;
}