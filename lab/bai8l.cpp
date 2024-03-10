#include<iostream>
using namespace std;
int main(){
int h, m, s;
cin>>h>>m>>s;
if(h>=0 && m>=0 && s>=0 && h<=23 && m<=59 && s<=59){
    cout<<"YES"<<endl;
if(h>=0 && h<23){
    if(m>=0 && m<59){
        if(s>=0 && s<59){
            s=s+1;
            m=m;
            h=h;
        }else if(s==59){
            s=0;
            m=m+1;
            h=h;
        }
    }
}
if(m==59){
if(s>=0 && s<59){
    s=s+1;
    m=59;
    h=h;
}else if(s==59){
    s=0;
    m=0;
    h=h+1;
}
}
if(h==23){
    if(m>=0 && m<59){
        if(s>=0 && s<59){
            s=s+1;
            m=m;
            h=23;
        }else if(s==59){
            s=0;
            m=m+1;
            h=23;
        }
    }
    if(m==59){
        if(s>=0 && s<59){
            s=s+1;
            m=59;
            h=23;
        }else if(s==59){
            s=0;
            m=0;
            h=0;
        }
    }
}
if(h==24) {h=0;}
if(m==60) {m=0;}
if(s==60) {s=0;}
cout<<h<<":"<<m<<":"<<s;
}else{
    cout<<"NO";
}
    return 0;
}