#include<iostream>
#include<math.h>
using namespace std;
int main(){
    float x,y;
    cin>>x>>y;
    float t=x/(y*y);
    cout<<round(t*100)/100;
    return 0;
}