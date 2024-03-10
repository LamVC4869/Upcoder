#include <iostream>

using namespace std;

void Move (int n, int a, int c, int b) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu cot " << a << " sang cot " << c;
        return;
    }

    Move (n - 1, a, b, c);
    cout << "Di chuyen dia " << n << " tu cot " << a << " sang cot " << c << endl;
    Move (n - 1, b, c, a);
}

int main() {
    int n;
    cin >> n;
    Move (n, 1, 3, 2);
    return 0;
}
