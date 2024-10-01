#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("divimax.in");
ofstream fout("divimax.out");
int c, n;
int v[3040];
int vmax = 0, prm = 0;
bool ciur[3506];
int prim[505];
struct ch{
    char c[15];
}s[3040];
bool compara(ch a, ch b){
    char c[31];
    char d[31];
    strcpy(c, a.c);
    strcat(c, b.c);
    strcpy(d, b.c);
    strcat(d, a.c);
    return strcmp(c, d) > 0;
}
int main()
{
    for(int i = 2; i <= 3500; i++){
        if(ciur[i] == false){
            prm++;
            prim[prm] = i;
            for(int j = i; j <= 3500/i; j++){
                ciur[j*i]=true;
            }
        }
    }
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        int maxim = 2;
        for(int j = 1; j <= prm && prim[j] <= v[i]; j++){
            while(v[i]%prim[j] == 0){
                maxim = prim[j];
                v[i] = v[i]/prim[j];
            }
        }
        if(v[i] > 1){
            maxim = v[i];
        }
        if(maxim > vmax){
            vmax = maxim;
        }
        int z = 0;
        char sm[8];
        do{
            sm[z] = (maxim % 10)+'0';
            z++;
            maxim = maxim / 10;
        }while(maxim > 0);
        sm[z] = 0;
        int zm = 0;
        for(int j = z-1; j >= 0; j--){
            s[i].c[zm] = sm[j];
            zm++;
        }
        s[i].c[zm] = 0;
    }
    if(c == 1){
        fout << vmax;
    }else{
        sort(s+1, s+n+1, compara);
        for(int i = 1; i <= n; i++){
            fout << s[i].c;
        }
    }
    return 0;
}
