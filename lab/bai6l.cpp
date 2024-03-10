#include<iostream>
using namespace std;
int main(){
int n,min,b;
cin>>n>>min>>b;
if(n==0){
if(b<min){
    cout<<-10;
}else if(b>=min){
    cout<<b*0.04;
}
}else{
if(b<min){
    cout<<-25;
}else if(b>=min){
    if(b-min>=5000){
    cout<<b*0.03;
    }else{
   cout<<b*0.05;
    }
}
}
    return 0;
}