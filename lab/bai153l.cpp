#include <iostream>

using namespace std;

class Rectangle {
    private:
    int length;
    int width;
    public:
    void setLength (int length) {
        this->length = length;
    }
    void setWidth (int width) {
        this->width = width;
    }
    int getLength () {
        return length;
    }
    int getWidth () {
        return width;
    }
    friend istream& operator >> (istream &is, Rectangle &hcn) {
        is >> hcn.length >> hcn.width;
        return is;
    }
    int Perimeter () {
        return (length + width) * 2;
    }
};

class Square : public Rectangle {
    public:
    friend istream& operator >> (istream &is, Square &sq) {
        int length;
        is >> length;
        sq.setLength (length);
        sq.setWidth (length);
        return is;
    }
};

int main () {
    char Type;
    while (cin >> Type) {
        if (Type == 'a') {
            Square sq;
            cin >> sq;
            cout << sq.Perimeter () << endl;
        } else if (Type == 'b') {
            Rectangle hcn;
            cin >> hcn;
            cout << hcn.Perimeter () << endl;
        }
    }
    return 0;
}