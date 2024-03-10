#include <iostream>
#include <string>

using namespace std;

int main () {
    string a = "abcdefghi";
    // in ra xâu mới xuất phát từ vị trí số 2 có độ dài là 5 kí tự
    string b = a.substr(2, 5);
    cout << b << endl;
    // in ra vị trí của xâu bcd trong xâu a
    int c = a.find("bcd");
    cout << c << endl;
    // xóa xâu từ vị trí số 2 với 5 kí tự bị xóa đi
    a = "abcdefghi";
    string d = a.erase(2, 5);
    cout << d << endl;
    
    a = "abcdefghi";
    // thay thế 1 kí tự bắt đầu từ vị trí số 0 bằng chuỗi ***
    string s = a.replace(0, 1, "***");
    cout << s << endl;

    string str1, str2;
    getline (cin, str1);
    getline (cin, str2);
    /*
    So sánh 2 chuỗi
    Nếu chuỗi str1 lớn hơn chuỗi str2 thì in ra là 1 còn ngược lại là -1
    Nếu 2 chuỗi bằng nhau thì in ra 0
    */
    cout << str1.compare(str2);

    string s = "abcd";
    // chèn xâu *** vào vị trí số 2 của chuỗi s
    s.insert(2, "***");
    cout << s;


    // toupper dung de viet hoa 
    // tolower dung de viet thanh chu thuong
    return 0;
}