#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
ifstream fin("afacere.in");
ofstream fout("afacere.out");
const int MOD = 1'000'000'007;
#define int long long
int bin_exp(int b, int e) {
  int result = 1;

  while (e) {
    if (e & 1) {
      result = (long long)result * b % MOD;
    }
    b = (long long)b * b % MOD;
    e >>= 1;
  }

  return result;
}
int n, l, nr;
char c[24][104];
vector<int> grupe[104];
int suma[104][24];
int unifica(int mask) {
    char u[104];
    bool first = true;
    for(int i = 1; i <= n; i++) {
        if(!(mask & (1 << (i - 1)))){
            continue;
        }
        if(first){
            strcpy(u, c[i]);
            first = false;
        }else{
            for(int j = 0; j < l; j++){
                if(u[j] == '?'){
                    u[j] = c[i][j];
                }else if(c[i][j] != '?' && u[j] != c[i][j]){
                    return -1;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < l; i++) {
        if(u[i] == '?'){
            cnt++;
        }
    }
    return cnt;
}
signed main(){
    fin >> n >> l >> nr;
    for(int i = 1; i <= n; i++){
        fin >> c[i];
    }
    int maxmask = (1 << n);
    for(int mask = 1; mask < maxmask; mask++) {
        int semne = unifica(mask);
        if(semne == -1){
            continue;
        }
        int biti = __builtin_popcount(mask);
        grupe[semne].push_back(biti);
    }
    for(int s = 0; s < l; s++){
        for(auto p : grupe[s]){
            suma[s][p]++;
        }
    }
    for(int q = 1; q <= nr; q++){
        int v;
        fin >> v;
        int rasp = 0;
        for(int s = 0; s < l; s++){
            int putere = bin_exp(26+v, s);
            for(int biti = 1; biti <= n; biti++){
                if(suma[s][biti] == 0){
                    continue;
                }
                int cnt = (putere*suma[s][biti])%MOD;
                if(biti % 2 == 1){
                    rasp = (rasp+cnt)%MOD;
                }else{
                    rasp = (rasp-cnt+MOD)%MOD;
                }
            }
        }
        fout << rasp << '\n';
    }
    return 0;
}
