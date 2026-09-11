#include <iostream>
using namespace std;
#define MOD 1000000007
int n;
long long p[1000001], c[1000001];
int main(){
    cin >> n;
    c[1] = 1;
    for(int i = 2; i <= n; i++){ 
        c[i] = (c[i]+c[i-1]+p[i-2]+MOD)%MOD;
        p[i] = (p[i-1]+c[i-1])%MOD;
    }
    cout << p[n];
    return 0;
}
