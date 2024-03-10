#include<iostream>
using namespace std;
int main(){
int x,y;
cin>>x;
y=x/20;
if(x<20){
  cout<<1;
}else if(x>=20){
  cout<<(double)y +1;
}
  return 0;
}