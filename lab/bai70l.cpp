// bai ltcb - t5
// tham khao mot tu lam hehe
// copy cua nguoi khac huhu
#include<iostream>
#include<cmath>

using namespace std;

bool soNT(int n)
{
    if(n<2)
        return false;
    int temp=sqrt(n);
    for(int i=2;i<=temp;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    bool check=false;
    int arr[10000];
    int sl=0;
    for(int i=a;i<=b;i++)
    {
        if(soNT(i))
        {
            arr[sl++]=i;
            check=true;
        }
    }
    
    for(int i=0;i<sl;i++)
    {
        if(i==sl-1)
        {
            cout<<arr[i];
        }
        else
        {
            cout<<arr[i]<<' ';
        }
    }
    
    if(!check)
        cout<<-1;
        
    return 0;
}