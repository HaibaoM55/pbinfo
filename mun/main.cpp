#include <fstream>
#include <algorithm>
#include <map>
#include <string.h>
#include <string>
using namespace std;
ifstream fin("mun.in");
ofstream fout("mun.out");
int c, n;
int f[10005][30];
int b[10005];
char v[10005][15];
char initial[10005][15];
char gazde[10005][15], oaspeti[10005][15];
int z = 0;
int main()
{
    fin >> c;
    fin >> n;
    int maxim = 0;
    for(int i = 1; i <= n; i++){
        char x[15];
        int f1[30];
        for(int i = 0; i <= 25; i++){
            f1[i]=0;
        }
        fin >> x;
        int l = strlen(x);
        for(int j = 0; j <= l-1; j++){
            f1[x[j]-'A']++;
        }
        bool ok = true;
        for(int j = 1; j <= z; j++){
            bool ok1 = true;
            for(int p = 0; p <= 25; p++){
                if(f[j][p] != f1[p]){
                    ok1 = false;
                    break;
                }
            }
            if(ok1){
                b[j]++;
                maxim = max(maxim, b[j]);
                ok = false;
                break;
            }
        }
        if(ok){
            z++;
            for(int j = 0; j <= 25; j++){
                f[z][j] = f1[j];
                b[z] = 1;
                maxim = max(maxim, b[z]);
            }
        }
    }
    if(c == 1){
        fout << z;
    }else if(c == 2){
        int vmax = 0;
        for(int i = 1; i <= z; i++){
            if(b[i] > vmax){
                vmax =b[i];
            }
        }
        int p = 2*vmax-n;
        fout << p << " " << n-p;
    }else{
        int nro = 0, nrg = 0;
        for(i=1;i<=n;i++){
            bool ok = true;
            for(int j = 1; j <= z; j++){
                bool ok1 = true;
                for(int p = 0; p <= 25; p++){
                    if(f[j][p] != f1[p]){
                        ok1 = false;
                        break;
                    }
                }
                if(ok1){
                    b[j]++;
                    maxim = max(maxim, b[j]);
                    ok = false;
                    break;
                }
            }
            if(frv[v[i]]==maximpush_back(init[i]);
            else oa.push_back(init[i]);
        }
        sort(oaspeti+1,oaspeti+nro+1);
        sort(gazde+1,gazde+nrg+1);
        for(int i=0;i<n-max1;i++){
            if(gaz[0]<oa[0]) cout<<gaz[i]<<" "<<oa[i]<<" ";
            else cout<<oa[i]<<" "<<gaz[i]<<" ";
        }
    }
    return 0;
}
