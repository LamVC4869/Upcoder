    #include <iostream>
    #include <cmath>
    #include <vector>
    #define ull unsigned long long

    using namespace std;

    bool isPrime (int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    int UCLN (int a, int b) {
        while (b) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int main () {
        ull digit, max, min;
        vector<ull> v;
        while (cin >> digit) v.push_back (digit);
        ull length = v.size ();
        max = min = v[0];
        for (int i = 0; i < length; i++) {
            if (v[i] > max) max = v[i];
            else if (v[i] < min) min = v[i];
        }
        ull max2 = min;
        ull min2 = max;
        for (int i = 0; i < length; i++) {
            if (v[i] < max && v[i] > max2) max2 = v[i];
            else if (v[i] < min2 && v[i] != min) min2 = v[i];
        }
        if (max2 == min) {
            cout << -1 << endl;
        } else {
            for (int i = length - 1; i > -1; i--) {
                if (v[i] == max2) {
                    cout << i;
                    break;
                }
            }
            cout << endl;
        }
        if (min2 == max) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < length; i++) if (v[i] == min2) cout << i << " ";
            cout << endl;
        }
        ull max_ucln = UCLN (v[0], v[1]);
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (UCLN (v[i], v[j]) > max_ucln) max_ucln = UCLN (v[i], v[j]);
            }
        }
        cout << max_ucln << endl;
        ull min_prime = max * 2;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                ull sum = 0;
                sum = v[i] + v[j];
                if (isPrime (sum) && sum < min_prime) min_prime = sum; 
            }
        }
        min_prime == max * 2 ? cout << -1 : cout << min_prime;
        return 0;
    }