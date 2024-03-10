#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
    private:    
    string nameBook;
    string nameAuthor;
    int numberBook;
    public:
    Book () {}
    Book (string nameBook, string nameAuthor, int numberBook) {
        this->nameBook = nameBook;
        this->nameAuthor = nameAuthor;
        this->numberBook = numberBook;
    } 
    string getNameBook () {
        return nameBook;
    }
    string getNameAuthor () {
        return nameAuthor;
    }
    int getNumberBook () {
        return numberBook;
    }
    void display () {
        cout << "Name Book: " << nameBook << endl;
        cout << "Name Author: " << nameAuthor << endl;
        cout << "Number Book: " << numberBook << endl;
    }
};

class Person {
    private:
    string name;
    int age;
    string add;
    vector<Book> vb;
    public:
    Person () {}
    Person (string name, int age, string add, vector<Book> vb) {
        this->name = name;
        this->age = age;
        this->add = add;
        this->vb = vb;
    }
    string getName () {
        return name;
    }
    int getAge () {
        return age;
    }
    string getAdd () {
        return add;
    }
    vector<Book> getVB () {
        return vb;
    }
    virtual long moneyPay () = 0;
    virtual void display () {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << add << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++) vb[i].display ();
		cout << "Money Pay: " << moneyPay() << endl;
    }
    static void sortPersonAge (vector<Person*> &vt) {
        for (int i = 0; i < vt.size () - 1; i++) {
            for (int j = i + 1; j < vt.size (); j++) {
                if (vt[i]->age > vt[j]->age) swap (vt[i], vt[j]);
            }
        }
    }
    static vector<int> getListAge (vector<Person*> vt) {
        vector<int> v;
        for (int i = 0; i < vt.size (); i++) {
            if (!(find(v.begin (), v.end (), vt[i]->getAge ()) != v.end ())) v.push_back (vt[i]->getAge());
        }
        return v;
    }
    static vector<Book> getMaxBookBorrowed(vector<Person*>vp, vector<Book> vB)
	{
		vector<int> count(vB.size(), 0);
		for (int i = 0; i < vB.size(); i++)
		{
			for (int j = 0; j < vp.size(); j++)
			{
				vector<Book> b(vp[j]->getVB());
				for (int k = 0; k < b.size(); k++)
				{
					if (vB[i].getNameBook() == b[k].getNameBook())
					{
						count[i]++;
					}
				}
			}
		}
		int max = *max_element(count.begin(), count.end());
		vector<Book> res;
		for (int i = 0; i < vB.size(); i++)
		{
			if (count[i] == max)
			{
				res.push_back(vB[i]);
			}
		}
		return res;
	}
};

class Children : public Person {
    public:
    Children () {}
    Children (string name, int age, string add, vector<Book> vb) : Person (name, age, add, vb) {}
    long moneyPay () {
        return 5000 * getVB ().size ();
    }
    void display () {
        cout << "Children!" << endl;
        Person::display();
    }
};
class Adult : public Person {
    public:
    Adult () {}
    Adult (string name, int age, string add, vector<Book> vb) : Person (name, age, add, vb) {}
    long moneyPay () {
        return 10000 * getVB ().size ();
    }
    void display () {
        cout << "Adult!" << endl;
        Person::display ();
    }
};