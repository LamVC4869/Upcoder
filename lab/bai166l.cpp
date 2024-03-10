/*
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
void xuli(int k,int nam)
{
    if(k == 0)
    {
         int a = (nam/100 - 1)*100 + 81;
         cout<<"09/09/"<<a;
    }
    else
    {
        int t = 0;
        if(k == 10)
        {
            k = 1;
            t = 100;
        }
        nam = nam - nam%100 + k * k + t;
        cout<<'0'<<k<<"/0"<<k<<'/'<<nam;
    }
    cout<<'\n';
}
bool check(int k,int thang, int ngay, int nam)
{
    if( k * k > nam%100)
        return false;
    if (k*k == nam%100)
    {
        if(thang < k)
            return false;
        if(thang == k)
        {
            return k < ngay;
        }
    }
    return true;
}
int main(){
	
	cin>>s;
	int nam = 0,ngay = 0,thang =0;
	for(int i = s.size()-4; i<s.size();++i)
	{
	    nam = nam*10 + s[i] - 48;
	}
	for(int i = 0 ; i < 2;++i)
	{
	    ngay = ngay*10 + s[i] - 48;
	    thang = thang*10 + s[i+3]-48;
	}
    int k = sqrt(nam%100);
    if(k*k == nam%100 && ngay == thang && ngay == k)
    {
        xuli(k-1,nam);
        xuli(k+1,nam);
    }
    else
    {
        if(check(k,thang,ngay,nam))
        {
            xuli(k,nam);
            xuli(k+1,nam);
        }
        else
        {
            xuli(k-1,nam);
            xuli(k,nam);
        }
    }
	return 0;
}
*/

#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;

struct Ngay {
    int ngay, thang, nam;
    friend istream& operator >> (istream &is, Ngay &n) {
        char c;
        is >> n.ngay >> c >> n.thang >> c >> n.nam;
        return is;
    }
    friend ostream& operator << (ostream &os, Ngay n) {
        if (n.ngay < 10) os << 0;
        os << n.ngay << '/';
        if (n.thang < 10) os << 0;
        os << n.thang << '/' << n.nam;
        return os << endl;
    }
};

void Solve (int k, Ngay d) {
    Ngay result;
    if (k == 0) {
        result.ngay = result.thang = 9;
        result.nam = (d.nam/100 - 1)*100 + 81;
    } else {
        int m = 0;
        if (k == 10) {
            k = 1, m = 100;
        }
        result.ngay = result.thang = k;
        result.nam = d.nam - d.nam % 100 + k*k + m;
    }
    cout << result;
}

bool kt (int k, Ngay n) {
    if (k*k > n.nam % 100) return false;
    else if (k*k == n.nam % 100) {
        if (n.thang < k) return false;
        else if (n.thang == k) return k < n.ngay;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Ngay tmp; cin >> tmp;
    int k = sqrt (tmp.nam % 100);
    if (k*k == tmp.nam % 100 && tmp.ngay == tmp.thang && tmp.ngay == k) {
        Solve (k - 1, tmp);
        Solve (k + 1, tmp);
    } else {
        if (kt (k, tmp)) {
            Solve (k, tmp);
            Solve (k + 1, tmp);
        } else {
            Solve (k - 1, tmp);
            Solve (k, tmp);
        }
    }
    return 0;
}