#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int t=x%10;
    cout<<t*10+(x-t)/10;
    return 0;
}