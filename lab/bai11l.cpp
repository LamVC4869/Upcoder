#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
double x;
int n;
cin>>x;
cin>>n;
if(pow(x, n)<1000)
cout<<fixed<<setprecision(3)<<pow(x, n);
if(pow(x, n)>=1000)
cout<<(pow(x, n))<<"...";
    return 0;
}