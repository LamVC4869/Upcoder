#include <iostream>

using namespace std;

int main(){
float n, s, e, sum, p;
cin >> n >> s >> e;
sum = 0;
p = e - s;
if(n <= 0 || s < 8 || e > 24 || s >= e){
    sum = -1;
}
if(s >= 8 && s <= 24 && e >= 8 && e <= 24){
   if(p < 3){
    if(e > 17 && s < 17){
        sum = (17 - s)*n*0.9 + (e - 17)*n;
    }else if(s >= 17){
        sum = p*n;
    }else if(e <= 17){
        sum = p*n*0.9;
    }
   }
   if(p >= 3){
    if(e > 17 && s < 17){
        if(17 - s >= 3){
            sum = (3*n + (17 - s - 3)*n*0.7)*0.9 + (e - 17)*n*0.7;
        }else if(17 - s < 3){
          sum = (17 - s)*n*0.9 + (3 - 17 + s)*n + (e - 17 - (3 - 17 - s))*n*0.7;
           }
        }else if(s >= 17){
            sum = 3*n + (p - 3)*n*0.7;
        }else if(e <= 17){
            sum = (3*n + (p - 3)*n*0.7)*0.9;
        }
    }
   }
   cout << sum;
    return 0;
}