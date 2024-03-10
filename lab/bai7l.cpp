#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int r=0;
while(n>0){
    int s= n%10;
    r+=s;
    n/=10;
    if(r==1){
        break;
        if(r>10){
    r=r%10 + (r-r%10)/10;
}
if(r>10){
    r=r%10 + (r-r%10)/10;
}
    }
}

cout<<r;
    return 0;
}