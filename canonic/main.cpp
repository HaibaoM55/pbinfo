#include <fstream>
#include <algorithm>
using namespace std;
#define BLOC 1000
#pragma GCC optimize("O1")
ifstream fin("canonic.in");
ofstream fout("canonic.out");
int c, n;
long long v[500004];
long long gcd[BLOC+5];
int R[500004];
int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        int nr = 1;
        long long g = v[1];
        int vmax = 1;
        for(int i = 2; i <= n; i++){
            if(v[i] % g == 0){
                g = __gcd(g, v[i]);
                nr++;
            }else{
                nr = 1;
                g = v[i];
            }
            if(nr > vmax){
                vmax = nr;
            }
        }
        fout << vmax;
    }else{
        long long rasp = 0;
        int nr = 1;
        int blocmax = 1;
        for(int i = 1; i <= n; i++){
            gcd[nr] = __gcd(gcd[nr], v[i]);
            if(i % BLOC == 0 && i != n){
                nr++;
                blocmax = nr;
            }
        }
        for(int i = n; i >= 1; i--){
            if(i < n && v[i] == v[i+1]){
                R[i] = R[i+1] + 1;
                rasp += R[i];
                continue;
            }
            int sz = 0;
            int binc = 2e9;
            int bi = (i-1)/BLOC + 1;
            int capat = min(n, bi*BLOC);
            bool ok = false;
            for(int j = i; j <= capat; j++){
                if(v[j] % v[i] == 0){
                    sz++;
                }else{
                    ok = true;
                    break;
                }
            }
            if(!ok){
                binc = bi+1;
                for(; binc <= blocmax; binc++){
                    if(gcd[binc] % v[i] == 0){
                        int st = (binc-1)*BLOC + 1;
                        int dr = min(n, binc*BLOC);
                        sz += dr-st+1;
                    }else{
                        break;
                    }
                }
                if(binc <= blocmax){
                    int start = (binc-1)*BLOC + 1;
                    for(int j = start; j <= n; j++){
                        if(v[j] % v[i] == 0){
                            sz++;
                        }else{
                            break;
                        }
                    }
                }
            }
            R[i] = sz;
            rasp += sz;
        }
        fout << rasp;
    }
    return 0;
}
