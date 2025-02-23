#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
int n;
int ciur[1000004];
unsigned long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        ciur[i] = i;
    }
    for(int i = 2; i <= n; i++){
        if(ciur[i] == i){
            for(int j = i; j <= n; j += i){
                ciur[j] = ciur[j] / i * (i - 1);
            }
        }
    }
    long long t=0, p;
    for(int c = 1; c <= n; c++){
        /*
        a = x*c
        b = y*c;
        (x, y) = 1
        */
        p = (1LL*c) % mod;
        p = p * p * p;
        p = p % mod;
        for(int x = 2; x*c <= n; x++){
            t = 1LL*x * ciur[x] / 2;
            t--;
            s += (2ULL*p*t*x) % mod;
            s = s % mod;
        }
    }
    cout << s;
    return 0;
}
