#include<iostream>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
string t="Yes";
if(a>0 && b>0 && a<2 && b<2){
    t="No";
}
if(a==b){
    t="No";
}
if(a>=2 && b>=2 && a!=b){
    for(int i=1;i<a && i<b;i++){
        if(a%i==0 && b%i==0 && i!=1){
            t="No";
        }
    }
}
cout<<t;
    return 0;
}