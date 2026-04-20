#include <fstream>
using namespace std;
ifstream fin("crossword.in");
ofstream fout("crossword.out");
int n, m, w;
char a[1004][1004];
bool vizsus[1004][1004], vizdreapta[1004][1004];
int sus[1004][1004], dreapta[1004][1004];
struct cuvant{
    char s[1004];
    int l;
}c[204], f[204][1004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    fin >> w;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vizsus[i][j]){
                for(int k = i; k <= n; k++){
                    if(a[k][j] == '-'){
                        sus[i][j]++;
                        vizsus[k][j] = true;
                    }else{
                        break;
                    }
                }
            }
            if(!vizdreapta[i][j]){
                for(int k = j; k <= m; k++){
                    if(a[i][k] == '-'){
                        dreapta[i][j]++;
                        vizdreapta[i][k] = true;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    int z = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(sus[i][j] > 1){
                z++;
                fout << "JOS " << i << ' ' << j << '\n';
            }
            if(dreapta[i][j] > 1){
                z++;
                fout << "DREAPTA " << i << ' ' << j << '\n';
            }
        }
    }
    char x;
    int nr = 1;
    while(fin >> x){
        if(x == 0){
            break;
        }
        if(x == ';'){
            nr++;
        }else{
            c[nr].s[c[nr].l] = x;
            c[nr].l++;
        }
    }
    nr--;
    for(int i = 1; i <= nr; i++){
        fout << c[nr].l << ':' << c[nr].s << '\n';
    }
    return 0;
}
