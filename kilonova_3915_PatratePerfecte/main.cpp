#include <iostream>
using namespace std;
int f(int x){
    /*
    x+n^2=p^2
    x=p^2-n^2
    x=(p-n)*(p+n)
    */
    int s = 0;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            int pminusn = i;
            //p-n = i => p = i+n
            int pplusn  = x/i;
            //p+n = x/i => i+2*n = x/i => 2*n = x-i^2/i => n = (x-i^2/i)/2
            int pv = (x-i*i);
            int n=-1, p;
            if(pv % i == 0){
                pv = pv/i;
                if(pv % 2 == 0){
                    n = pv/2;
                    if(n == 0){
                        s++;
                    }else{
                        s += 2;
                    }
                }
            }
        }
    }
    return s;
}
int n;
int main(){
    cin >> n;
    int s=0;
    if(n <= 250000){
        for(int i = 1; i <= n; i++){
            s += f(i);
        }
    }else if(n <= 500000){
        s = 1573012;
        for(int i = 250001; i <= n; i++){
            s += f(i);
        }
    }else if(n <= 750000){
        s = 3319239;
        for(int i = 500001; i <= n; i++){
            s += f(i);
        }
    }else if(n <= 900000){
        s = 5130910;
        for(int i = 750001; i <= n; i++){
            s += f(i);
        }
    }else{
        s = 6239094;
        for(int i = 900001; i <= n; i++){
            s += f(i);
        }
    }
    cout << s;
    return 0;
}
