#include <fstream>
#include <algorithm>
using namespace std;
#define SQ 720
ifstream fin("canonic.in");
ofstream fout("canonic.out");
int c, n;
long long v[500004];
int stiva[500004];
long long bsq[SQ];
int dr = 0;
int z = 1;
int main(){
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] % SQ == 0){
            z++;
            bsq[z] = v[i];
        }
        bsq[z] = __gcd(v[i], bsq[z]);
    }
    if(c == 1){
        int nr1 = 1;
        long long g = v[1];
        int vmax = 1;
        for(int i = 2; i <= n; i++){
            if(v[i] % g == 0){
                g = __gcd(g, v[i]);
                nr1++;
            }else{
                nr1 = 1;
                g = v[i];
            }
            if(nr1 > vmax){
                vmax = nr1;
            }
        }
        fout << vmax;
    }else{
        /*
        long long rasp = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(v[j] % v[i] != 0){
                    break;
                }
                rasp++;
            }
        }
        fout << rasp;
        */
        long long rasp = 0;
        v[n+1] = 1000000LL*1000000LL;
        for(int i = 1; i <= n; i++){
            long long g = v[i];
            int lst = 1;
            int fin1 = i/SQ+1;
            bool ok = true;
            for(int j = i; j/SQ != fin1; j++){
                g = __gcd(g, v[j]);
                if(g != v[j]){
                    ok = false;
                    break;
                }else{
                    rasp++;
                }
            }
            if(ok){
                int tr = 0;
                for(int b = i/SQ+1; b <= z; b++){
                    g = __gcd(g, bsq[b]);
                    if(v[i] % g == 0){
                        rasp += SQ;
                    }else{
                        tr = (b-1)*SQ+1;
                        break;
                    }
                }
                for(int j = tr; j <= n; j++){
                    if(v[j] % v[i] == 0){
                        rasp++;
                    }
                }
            }
        }
        fout << rasp;
    }
    return 0;
}
