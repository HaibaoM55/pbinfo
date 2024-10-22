#include <iostream>
using namespace std;
long long n, k;
long long r1=0, r2=0;
long long nr = 0;
long long scif = 0;
long long scif2 = 0;
int main()
{
    cin >> n >> k;
    if(k == 1){
        cout << n%72;
        return 0;
    }
    long long x = n;
    do{
        scif += x%10;
        x = x/10;
    }while(x > 0);
    scif = scif*k;
    r1 = scif%9;
    if(1 <= n && n <= 9){
        if(k == 2){
            scif2 = 11*n;
        }else{
            scif2 = 111*n;
        }
    }else if(10 <= n && n <= 99){
        scif2 = (n%10)*100+n;
    }else{
        scif2 = n%1000;
    }
    r2 = scif2%8;
    nr = 9*r2-8*r1;
    if(nr < 0){
        nr = 9*r2-8*r1+72;
    }
    cout << nr;
    return 0;
}
