#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("grup.in");
ofstream fout("grup.out");
int c, n;
char x[12];
int g[11][10004];
int gr[1028];
int main()
{
    fin >> n >> c;
    if(c == 1){
        for(int i = 1; i <= n; i++){
            fin >> x;
            int c = x[0]-'0';
            g[c][0]++;
            int b = g[c][0];
            int l = strlen(x);
            int nr = 0;
            for(int j = 0; j < l; j++){
                nr = nr*10+(x[j]-'0');
            }
            g[c][b] = nr;
        }
        long long vmin1 = 10000000000;
        int vmax = 0;
        for(int i = 0; i <= 9; i++){
            long long vmin = 10000000000;
            if(g[i][0] >= vmax){
                for(int j = 1; j <= g[i][0]; j++){
                    if(g[i][j] < vmin){
                        vmin = g[i][j];
                    }
                }
                if(g[i][0] == vmax){
                    vmin1 = min(vmin1, vmin);
                }else{
                    vmin1 = vmin;
                    vmax = g[i][0];
                }
            }
        }
        fout << vmin1;
    }else{
        for(int i = 1; i <= n; i++){
            fin >> x;
            int l = strlen(x);
            bool f[11];
            for(int j = 0; j <= 9; j++){
                f[j] = false;
            }
            for(int j = 0; j < l; j++){
                f[x[j]-'0'] = true;
            }
            int nr = 1;
            int fn = 0;
            for(int j = 0; j <= 9; j++){
                if(f[j]){
                    fn += nr;
                }
                nr = nr*2;
            }
            gr[fn]++;
        }
        int vmax = 0;
        for(int i = 1; i <= 1023; i++){
            if(gr[i] > vmax){
                vmax = gr[i];
            }
        }
        fout << vmax;
    }
    return 0;
}
