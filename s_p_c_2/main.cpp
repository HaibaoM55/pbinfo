#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("s_p_c_2.in");
ofstream fout("s_p_c_2.out");
int nrs, nrp, nrc;
char x[65];
struct sircaractere{
    char c[65];
}s[104], p[104], c[104];
bool compara(sircaractere x, sircaractere y){
    return strcmp(x.c, y.c) < 0;
}
int main(){
    while(fin >> x){
        int l = strlen(x);
        if(x[0]=='S'){
            nrs++;
            for(int j = 2; j <= l; j++){
                s[nrs].c[j-2] = x[j];
            }
        }else if(x[0] == 'P'){
            nrp++;
            for(int j = 2; j <= l; j++){
                p[nrp].c[j-2] = x[j];
            }
        }else{
            nrc++;
            for(int j = 2; j <= l; j++){
                c[nrc].c[j-2] = x[j];
            }
        }
    }
    sort(s+1, s+nrs+1, compara);
    sort(p+1, p+nrp+1, compara);
    sort(c+1, c+nrc+1, compara);
    for(int i = 1; i <= nrs; i++){
        for(int j = 1; j <= nrp; j++){
            for(int k = 1; k <= nrc; k++){
                fout << s[i].c << ' ' << p[j].c << ' ' << c[k].c << '\n';
            }
        }
    }
    return 0;
}
