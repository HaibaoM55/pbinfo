#include <fstream>
#include <bitset>
using namespace std;
#define int long long
ifstream fin("succes.in");
ofstream fout("succes.out");
int n, m, k;
int a[104], b[104];
bitset<104> s[200004];
bitset<104> pre[200004];
int cnt[104];
int calcA(bitset<104> f){
    int sa = 0;
    for(int i = 1; i <= m; i++) if(f[i]) sa += a[i];
    return sa;
}
int calcB(bitset<104> f){
    int sb = 0;
    for(int i = 1; i <= m; i++) if(f[i]) sb += b[i];
    return sb;
}
signed main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        int nr; fin >> nr;
        for(int j = 0; j < nr; j++){
            int x; fin >> x;
            s[i][x] = 1;
        }
    }
    bool allpoz = true;
    for(int i = 1; i <= m; i++){
        if(b[i] < 0){
            allpoz = false;
            break;
        }
    }
    int vmax = -4e18;
    if(allpoz){
        int i = 1;
        bitset<104> f;
        int sumB = 0, sumA = 0;
        for(int j = 1; j <= n; j++){
            for(int x = 1; x <= m; x++){
                if(s[j][x]){
                    cnt[x]++;
                    if(cnt[x] == 1){
                        sumB += b[x];
                        sumA += a[x];
                    }
                }
            }
            while(sumB > k){
                for(int x = 1; x <= m; x++){
                    if(s[i][x]){
                        cnt[x]--;
                        if(cnt[x] == 0){
                            sumB -= b[x];
                            sumA -= a[x];
                        }
                    }
                }
                i++;
            }
            if(sumB <= k){
                vmax = max(vmax, sumA);
            }
        }
    }else{
        for(int i = 1; i <= n; i++){
            bitset<104> f;
            for(int j = i; j <= n; j++){
                f |= s[j];
                if(calcB(f) <= k)
                    vmax = max(vmax, calcA(f));
            }
        }
    }

    fout << vmax;
    return 0;
}
