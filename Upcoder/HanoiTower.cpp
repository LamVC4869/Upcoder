#include <iostream>

void Move (int n, char a, char b, char c) {
	if (n == 1) {
		std::cout << n << " " << a << " " << c << '\n';
	}
	else {
		Move (n - 1, a, c, b);
		std::cout << n << " " << a << " " << c << '\n';
		Move (n - 1, b, a, c);
	}
}

int main(){
	int n; 
	std::cin >> n;
	Move (n, 'A','B','C');
}