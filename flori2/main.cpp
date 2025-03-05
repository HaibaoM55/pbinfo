#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("flori2.in");
ofstream fout("flori2.out");
int n, m;
int nrg = 0;
struct grupa{
    int nrf, f[154];
    bool b[104];
    bool exista = true;
}g[154];
bool b[104];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 100; j++){
            b[j] = false;
        }
        for(int j = 1; j <= m; j++){
            int x;
            fin >> x;
            b[x] = true;
        }
        bool ok = false;
        for(int j = 1; j <= nrg; j++){
            for(int p = 0; p <= 100; p++){
                if(b[p] && b[p] == g[j].b[p]){
                    ok = true;
                    break;
                }
            }
            if(ok){
                for(int p = 0; p <= 100; p++){
                    if(b[p]){
                        g[j].b[p] = true;
                    }
                }
                g[j].nrf++;
                g[j].f[g[j].nrf] = i;
                break;
            }
        }
        if(ok == false){
            nrg++;
            for(int p = 0; p <= 100; p++){
                if(b[p]){
                    g[nrg].b[p] = true;
                }
            }
            g[nrg].nrf = 1;
            g[nrg].f[1] = i;
        }
    }
    for(int i = 1; i <= nrg-1; i++){
        if(g[i].exista){
            for(int j = i+1; j <= nrg; j++){
                bool ok = false;
                if(g[j].exista){
                    for(int p =0; p <= 100; p++){
                        if(g[i].b[p] && g[i].b[p] == g[j].b[p]){
                            ok = true;
                            break;
                        }
                    }
                }
                if(ok){
                    g[j].exista = false;
                    for(int p = 0; p <= 100; p++){
                        if(g[j].b[p]){
                            g[i].b[p] = true;
                        }
                    }
                    for(int p = 1; p <= g[j].nrf; p++){
                        g[i].f[g[i].nrf+p] = g[j].f[p];
                    }
                    g[i].nrf += g[j].nrf;
                    sort(g[i].f+1, g[i].f+g[i].nrf);
                }
            }
        }
    }
    for(int i = 1; i <= nrg; i++){
        if(g[i].exista){
            for(int j = 1; j <= g[i].nrf; j++){
                fout << g[i].f[j] << ' ';
            }
            fout << '\n';
        }
    }
    return 0;
}
