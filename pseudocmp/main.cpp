#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("pseudocmp.in");
ofstream fout("pseudocmp.out");
int c, n;
struct numar{
    int nr, scif=0;
}v[100004];
int s[60][100004];
bool compara(numar a, numar b){
    if(a.nr > b.nr){
        return false;
    }
    return true;
}
int main(){
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].nr;
        int x = v[i].nr;
        do{
            v[i].scif = v[i].scif+x%10;
            x = x / 10;
        }while(x > 0);
    }
    if(c == 1){
        sort(v+1, v+n+1, compara);
        for(int i = 1; i <= n-1; i++){
            if(v[i].scif > v[i+1].scif){
                fout << v[i].nr << ' ' << v[i+1].nr << '\n';
                return 0;
            }
        }
        fout << -1;
    }else{
        sort(v+1, v+n+1, compara);
        for(int j = 0; j <= 54; j++){
            s[j][0] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 54; j++){
                s[j][i] = s[j][i-1];
            }
            s[v[i].scif][i]++;
        }
        long long sma = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].scif; j++){
                sma = sma+s[j][n]-s[j][i];
            }
        }
        fout << sma;
    }
    return 0;
}
