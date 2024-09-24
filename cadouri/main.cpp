#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("cadouri.in");
ofstream fout("cadouri.out");
struct cadouri{
    char x[21];
    int nr = 0;
}c[502];
int n;
int nrc = 0;
char v[256];
bool compara(cadouri a, cadouri b){
    if(a.nr > b.nr){
        return true;
    }
    if(a.nr == b.nr){
        if(strcmp(a.x, b.x) < 0){
            return true;
        }
    }
    return false;
}
int main()
{
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; i++){
        fin.get(v, 256);
        fin.get();
        int l = strlen(v);
        for(int j = 0; j <= l-1; j++){
            if('0' <= v[j] && v[j] <= '9'){
                int x = v[j]-'0';
                j++;
                while(j <= l-1 && '0' <= v[j] && v[j] <= '9'){
                    x = x*10+(v[j]-'0');
                    j++;
                }
                while(j <= l-1 && !('a' <= v[j] && v[j] <= 'z')){
                    j++;
                }
                char k[21];
                int lk = 0;
                while(j <= l-1 && 'a' <= v[j] && v[j] <= 'z'){
                    k[lk] = v[j];
                    lk++;
                    j++;
                }
                k[lk] = 0;
                bool ok = false;
                for(int r = 1; r <= nrc; r++){
                    if(strcmp(k, c[r].x) == 0){
                        ok = true;
                        c[r].nr += x;
                        break;
                    }
                }
                if(ok == false){
                    nrc++;
                    c[nrc].nr = x;
                    strcpy(c[nrc].x, k);
                }
            }
        }
    }
    sort(c+1, c+nrc+1, compara);
    fout << nrc <<'\n';
    for(int i = 1; i <= nrc; i++){
        fout << c[i].x << ' ' << c[i].nr <<'\n';
    }
    return 0;
}
