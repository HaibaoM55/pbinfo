#include <iostream>
using namespace std;
int T, n, c, k;
char s[262144+4];
int f[262144+4], freq[18+4],sidx[262144+4], g[262144+4];
int main(){
    cin >> T;
    while(T--){
        cin >> n >> c >> k;
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
        if(k >= n){
            cout << "1\n";
            continue;
        }
        int full = 1 << c;
        for(int i = 0; i < full; i++) {
            f[i] = 0;
        }
        for(int i = 0; i < c; i++) {
            freq[i] = 0;
        }
        int curMask = 0;
        for(int i = 1; i <= n; i++) {
            sidx[i] = s[i] - 'A';
        }
        if(k <= n){
            for(int i = 1; i <= n; i++){
                int id = sidx[i];
                if(freq[id] == 0){
                    curMask |= (1 << id);
                }
                freq[id]++;
                if(i > k){
                    int rem = sidx[i - k];
                    freq[rem]--;
                    if(freq[rem] == 0){
                        curMask &= ~(1 << rem);
                    }
                }
                if(i >= k){
                    f[curMask] = 1;
                }
            }
        }
        for(int i = 0; i < full; i++){
            g[i] = f[i];
        }
        for(int bit = 0; bit < c; bit++){
            for(int mask = 0; mask < full; mask++){
                if(mask & (1 << bit)){
                    if(g[mask ^ (1 << bit)]){
                        g[mask] = 1;
                    }
                }
            }
        }
        int lastBit = 1 << sidx[n];
        int maxD = -1;
        for(int d = 0; d < full; d++){
            if(d & lastBit){
                continue;
            }
            if(g[d]){
                continue;
            }
            int pop = __builtin_popcount(d);
            if(pop > maxD){
                maxD = pop;
            }
        }
        int rasp = c - maxD;
        cout << rasp << "\n";
    }
    return 0;
}
