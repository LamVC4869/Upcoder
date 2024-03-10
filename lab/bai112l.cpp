#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isArmstrong (int n) {
    int sum = 0, count = 0, res = n;
    while (n != 0){
       n /= 10;
       count++;
    }
    n = res;
    while (n != 0){
        int temp = n % 10;
        sum += pow (temp, count);
        n /= 10;
    }
    return sum == res;
}

int main() {
    int A, B;
    cin >> A >> B;
    vector<int> ASN;
    for (int i = A; i <= B; ++i) {
       if (isArmstrong (i)) ASN.push_back (i);
    }
    if (ASN.empty()) {
        cout << -1;
    } else {
        for (int armstrongNumber : ASN) {
            cout << armstrongNumber << " ";
        }
    }
    return 0;
}

// #include <iostream>
// #include <cmath>

// using namespace std;

// int isArmstrong (int n) {
//     int sum = 0, count = 0, res = n;
//     while (n != 0){
//        n /= 10;
//        count++;
//     }
//     n = res;
//     while (n != 0){
//         int temp = n % 10;
//         sum += pow (temp, count);
//         n /= 10;
//     }
//     return sum == res;
// }

// void Find (int a, int b){
//     int count = 0;
//     if (a > b){
//         for (int i = b; i <= a; i++){
//             if (isArmstrong (i)){
//                 count++;
//                 cout << i << " ";
//                 }
//             } 
//         } else {
//             for (int i = a; i <= b; i++){
//                 if (isArmstrong (i)){
//                     count++;
//                     cout << i << " ";
//                 }
//             }
//         }

//         if (count == 0){
//             cout << -1;
//         }
//     }

// int main(){
//     unsigned int a, b; cin >> a >> b;
//     Find(a, b);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int dp[12][12];
// int get(int x){
//     int ans = 0;
//     int t = x;
//     int cnt = 0;
//     while(t){
//         ++cnt,t /= 10;
//     }
//     while(x){
//         ans += dp[x % 10][cnt];
//         x /= 10;
//     }
//     return ans;
// }
// int main(){
//     for(int i = 0;i < 10;i++){
//         dp[i][0] = 1;
//         for(int j = 1;j <= 8;j++){
//             dp[i][j] = dp[i][j - 1] * i;
//         }
//     }
//     int a,b;
//     cin >> a >> b;
//     vector<int> ans;
//     for(int i = a;i <= b;i++){
//         if (i == get(i)){
//             ans.push_back(i);
//         }
//     }
//     if (ans.empty()){
//         cout << "-1";
//         return 0;
//     }
//     for(int i = 0;i < ans.size();i++){
//         cout << ans[i] << ' ';
//     }
// }
