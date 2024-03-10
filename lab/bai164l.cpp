#include <iostream>

using namespace std;

int positive[1000010], negative[1000010];
bool ktPositive[1000010], ktNegative[1000010];
int n, arr[1000010];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) negative[-arr[i]]++;
        else positive[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && !ktNegative[-arr[i]]) {
            cout << negative[-arr[i]] << ' ';
            ktNegative[-arr[i]] = true;
        }
        if (arr[i] >= 0 && !ktPositive[arr[i]]) {
            cout << positive[arr[i]] << ' ';
            ktPositive[arr[i]] = true;
        }
    }
    return 0;
}
