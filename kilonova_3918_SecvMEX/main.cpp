#include <iostream>
#include <unordered_map>
using namespace std;
long long n, k, w;
long long v[1000004];
unordered_map<long long, long long> f;
unordered_map<long long, long long> gol;
long long nrap(long long kl){
    if(kl == 0){
        return 1LL * n * (n + 1) / 2;
    }
    long long j = 0;
    long long mex = 0;
    long long s = 0;
    f = gol;
    for(int i = 1; i <= n; i++){
        if(i > 1){
            f[v[i-1]]--;
            if(f[v[i-1]] == 0){
                mex = min(mex, v[i-1]);
            }
        }
        while(mex < kl && j <= n){
            j++;
            f[v[j]]++;
            while(f[mex] > 0){
                mex++;
            }
        }
        if(mex >= kl){
            s += (long long)n-j+1;
        }
    }
    return s;
}
int main(){
    cin >> n >> k >> w;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << 1LL*nrap(k)-1LL*nrap(w+1);
    return 0;
}
