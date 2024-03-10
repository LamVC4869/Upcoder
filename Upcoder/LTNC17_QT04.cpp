#include <iostream>
#include <fstream>
#include <cmath>
#define ull unsigned long long

using namespace std;

bool scp (ull n) {
    return int (sqrt (n)) == sqrt (n);
}
bool isFibo (ull n) {
    return scp (5*n*n - 4) || scp (5*n*n + 4);
}

int main () {
    ifstream ifs("DAYSO.INP");
    ofstream ofs("DAYSO.OUT");
    ull digit, max = 0, k = 0;
    while (ifs >> digit) {
        if (isFibo (digit)) {
            ofs << digit << ' ';
            if (digit > max) max = digit;
        }
        k++;
        if (k > 30) break;
    }
    ifs.close ();
    ofs << endl << max << ' ';
    for (int i = 1; i <= 10000; i++) {
        ull f = (pow ((1 + sqrt(5))/2, i) - pow ((1 - sqrt (5))/2, i)) / sqrt(5);
        if (f == max) {
            ofs << i;
            break;
        }
    }
    ofs.close ();
    return 0;
}

// #include <iostream>
// #include "fstream"
// #include "vector"
// using namespace std;

// int main(){
//     vector<int> v;
//     int n=1; long a[100000];
//     long long f[100000]; long x;long h=0, d; long p[10000],l=0;
//     ifstream ifile("DAYSO.INP");
//     while(ifile>>x){
//         a[n++]=x;
//     }
//     ifile.close();
//     for(long i=1;i<=30;i++){
        
//         if(i==1 || i==2) f[i]=1;
//         else
//         f[i]=f[i-2]+f[i-1];
//     }

//     for(long i=1;i<=n;i++)
//     for(long j=2;j<=30;j++)
//     if(a[i]==f[j]){
     
//         p[l++]=a[i];
//         if(a[i]>h){
//         h=a[i];
//         d=j;}
//     }

//     ofstream ofile("DAYSO.OUT");
//    for(int i=0;i<l;i++)
//     ofile<<p[i]<<" ";
//     ofile<<endl;
//     ofile<<h<<" ";  ofile<<d;
    
     
//     ofile.close();
//     return 0;
// }