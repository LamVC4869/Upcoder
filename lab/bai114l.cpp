#include <iostream>

using namespace std;

void Nhap (string label, int &n) {
	cout << label;
	cin >> n;
}

void Nhap_mang (int* &a, int size) {
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
}

void Them_Phan_Tu (int* &a, int &size, int pos, int value) {
	int *b = new int [size + 1];
	for (int i = 0; i < pos; i++) {
		b[i] = a[i];
	}
	b[pos] = value;
	for (int i = pos + 1; i <= size; i++) {
		b[i] = a[i - 1];
	}
	delete []a;
	a = b;
	size++;
}

void Thay_the (int* &a, int vi_tri, int value) {
	a[vi_tri] = value;
}

int main () {
	int n;
	Nhap("n = ", n);
	int *a = new int [100];
	cout << "Chu y mang duoc bat dau tu so 0" << endl;
	cout << "Nhap Mang: ";
	Nhap_mang (a, n);
	cout << "Mang ban dau: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	int digit;
	Nhap ("Gia tri can them : ", digit);
	int vi_tri;
	cout << "Them phan tu " << digit << " vao vi tri so: ";
	cin >> vi_tri;
	Them_Phan_Tu (a, n, vi_tri, digit);
	cout << "Mang sau khi duoc them phan tu: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	int pos_for_replace, value_of_digit_for_replace;
	Nhap ("Gia tri dung de thay the: ", value_of_digit_for_replace);
	Nhap ("Vi tri can duoc thay the: ", pos_for_replace);
	Thay_the (a, pos_for_replace, value_of_digit_for_replace);
	cout << "Mang sau khi duoc thay the: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	delete []a;
	return 0;
}