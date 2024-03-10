#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
double a,b,c,x0,x1,x2,x3,delta;
cin>>a>>b>>c;
delta = b*b - 4*a*c;
x0= - c/b;
x1= - b/(2*a);
x2= (-b + sqrt(delta))/(2*a);
x3= (-b - sqrt(delta))/(2*a);
if(a==0 && b==0 && c==0){
    cout<<-1;
}
else if(a==0 && b==0 && c!=0){
    cout<<0;
}
else if(a==0 && b!=0){
    cout<<1<<endl;
    if(x0==0) {x0=0;}
    cout<<fixed<<setprecision(10)<<x0;
}
else if(a!=0){
    if(delta < 0){
        cout<<0;
    }else if(delta == 0){
        cout<<1<<endl;
        if(x1==0){x1=0;}
        cout<<fixed<<setprecision(10)<<x1;
    }else if(delta > 0){
        cout<<2<<endl;
        if(x2==0) {x2=0;}
        if(x3==0) {x3=0;}
        if(x2>x3){
            cout<<fixed<<setprecision(10)<<x3<<endl;
            cout<<fixed<<setprecision(10)<<x2;
        }else if(x2<x3){
            cout<<fixed<<setprecision(10)<<x2<<endl;
            cout<<fixed<<setprecision(10)<<x3;
        }
    }
}
    return 0;
}