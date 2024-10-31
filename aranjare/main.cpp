#include <iostream>
#define MOD 100019
using namespace std;
long long f,f1;
long long p1,q;
int n, p;
int main()
{
    cin >> n >> p;
    if(n % p == 0)
    {
        q = n / p;
        f = 1;
        for(int i = 1 ; i <= q; i++){
            f = f*i;
            f = f % MOD;
        }
        p1 = 1;
        for(int i = 1 ; i <= p; i++){
            p1 = p1*f;
            p1 = p1 % MOD;
        }
    }
    else if((n+1) % p == 0){
        q = n / p  ;
        f = 1;
        for(int i = 1 ; i <= q ; i++){
            f = f*i;
            f = f % MOD;
        }
        f1 = f*(q+1);
        f1 = f1 % MOD;
        p1 = 1;
        for(int i = 1 ; i < p; i++){
            p1 = (p1 * f1) % MOD;
        }
        p1 = (p1 * f) % MOD;
    }
    else{
        p1 = 0;
    }
    cout << p1;
    return 0;
}
