#define mod 1000000007
#include <iostream>
using namespace std;
int t, n;
int sol[500004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sol[0] = 1;
    /*
    y = x+a[1]*x+a[2]*x+a[3]*x+...+a[o]*x
    y = x*(1+a[1]+a[2]+...+a[o])
    y/x = 1+a[1]+a[2]+...+a[o]
    */
    for(int i = 1; i <= 500000; i++){
        for(int x = 1; x <= 500000/i; x++){
            sol[x*i] += sol[i-1];
            sol[x*i] = sol[x*i] % mod;
        }
    }
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        cout << sol[n] << '\n';
    }
    return 0;
}
