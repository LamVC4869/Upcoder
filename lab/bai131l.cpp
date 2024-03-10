#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int a[1001], n = 0;
    while (cin >> a[n]) n++;
    vector<int> v;
    int max = a[0], cnt_max = 0;
    bool duyet[1001] = {};
    for (int i = 0; i < n; i++) {
        if (a[i] >= max) max = a[i];
        if (!duyet[i]) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) duyet[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == max) cnt_max++;
        if (duyet[i]) {
            v.push_back (a[i]);
            for (int j = i + 1; j < n; j++) if (a[i] == a[j]) duyet[j] = false;
        }
    }
    sort (v.begin (), v.end ());
    for (int x : v) cout << x << ' ';
    if (cnt_max == 1) cout << max << ' ';
    for (auto it = v.rbegin (); it != v.rend (); it++) cout << *it << ' ';
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int a[1010],d[1000010],n,m,dm;
// vector<int> res;

// void solve()
// {
//     for (int i=1;i<=n;i++)
//         if (d[a[i]]>1) res.push_back(a[i]);
//     n=res.size();
//     for (int i=0;i<n;i++)
//     {
//         if (d[res[i]]%2!=0) d[res[i]]--;
//         for (int j=1;j<d[res[i]]/2;j++)
//             res.push_back(res[i]);
//     }
//     sort(res.begin(),res.end());
//     for (int i=0;i<res.size();i++)
//         cout<<res[i]<<" ";
//     if (dm%2!=0) cout<<m<<" ";
//     for (int i=res.size()-1;i>=0;i--)
//         cout<<res[i]<<" ";
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int x;
//     while (cin>>x) 
//     {
//         if (d[x]==0) a[++n]=x;
//         d[x]++;
//         if (x>m) m=x;
//     }
//     dm=d[m];
//     solve();
//     return 0;
// }