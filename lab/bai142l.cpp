// #include <bits/stdc++.h> 
// using namespace std;
// int solve() {
//   int odd = 0, even = 0;
//   vector<bool> mount(11);
//   for (int i = 0; i < 11; i++) mount[i] = false;
//   int n, k;
//   cin >> n >> k;  
//   long long multi = 1;
//   vector<int> num(n);
//   for (int i = 0; i < n; i++) cin >> num[i];  
//   for (int i = 0; i < n; i++) {           
//     mount[num[i]] = true ;
//     multi = ( num[ i ] % k ) * ( multi % k ) ;
//     if ( num[i] % 2 == 1 )
//       odd++;
//     else
//       even++;
//   }
//   if (multi % k == 0 ) {
//     cout << 0 << endl;
//     return 0;
//   }
//   if (k == 3 || k == 5 || k == 2) {
//     int plus = 10;
//     for (int i = 1; i <= 10; i++ ) {
//       if (mount[i]) plus = min(plus, k - (i % k));
//     }
//     cout << plus << endl ;
//     return 0;
//   } 
//   else 
//   {
//     if( mount[3] || mount[7] ) { cout << 1 << endl ; return 0 ;}
//     if (even == 1 && odd >= 1) {
//       cout << 1 << endl;
//       return 0;
//     }
//     cout << 2 << endl;
//   }
//   return 0;
// }
 
// int main() {
//   int t;
//   cin >> t;
//   while (t--) solve();
// }

#include <iostream>
#include <vector>

using namespace std;

void Tttt () {
    int n, k, Min = 10; cin >> n >> k;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        if (k - i < Min) Min = k - i;
    }
    if (Min == 0) {
        cout << 0 << endl;
        return;
    }
    int res = v[0];
    for (int i = 1; i < n; i++) {
        if (res % k == 0) {
            cout << 0 << endl;
            return;
        } else res *= v[i];
    }
    
}

int main () {
    int t; cin >> t;
    while (t--) {
        Tttt ();
    }
    return 0;
}