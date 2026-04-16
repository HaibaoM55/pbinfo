#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int x, n;
int v[12];
signed main(){
    cin >> x;
    do{
        n++;
        v[n] = x%10;
        x = x/10;
    }while(x > 0);
    sort(v+1, v+n+1);
    long long s = 0;
    do{
        int nr = 0;
        for(int i = 1; i <= n; i++){
            nr = nr*10LL+v[i];
        }
        s += nr;
    }while(next_permutation(v+1, v+n+1));
    cout << s;
    return 0;
}
