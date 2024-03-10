#include<iostream>
using namespace std;
int main(){
float a,b,c;
cin>>a>>b>>c;
if((a+b)>c&&(a+c)>b&&(b+c)>a){
    if(a==b&&a==c&&b==c){
        cout<<"equilateral triangle";
    }else if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)){
        cout<<"right triangle";
    }else if((a==b&&a!=c)||(b==c&&b!=a)||(a==c&&a!=b)){
        cout<<"isosceles triangle";
    }else{
        cout<<"regular triangle";
    }
}else{
    cout<<"no triangle";
}
    return 0;
}