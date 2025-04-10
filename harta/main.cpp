#include <fstream>
using namespace std;
ifstream fin("harta.in");
ofstream fout("harta.out");
int p;
int n,m,k;
struct poz{
    int i1, j1, i2, j2;
}a[1004];
int mat[1504][1504];
bool linia[1504], coloana[1504];
long long ariemax = 0, incap = 0, ariemaxi=0;
int main(){
    fin >> p;
    fin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        fin >> a[i].i1 >> a[i].j1 >> a[i].i2 >> a[i].j2;
    }
    if(p == 1){
        for(int i = 1; i <= k; i++){
            int i1 = a[i].i1;
            int j1 = a[i].j1;
            int i2 = a[i].i2;
            int j2 = a[i].j2;
            if((i2-i1+1) == (j2-j1+1)){
                long long arie = 1LL*(i2-i1+1)*(j2-j1+1);
                arie = max(arie, 0LL);
                if(arie > ariemax){
                    ariemax = arie;
                    ariemaxi = i;
                }
            }
        }
        int l1 = (a[ariemaxi].i2-a[ariemaxi].i1-1);
        int L1 = (a[ariemaxi].j2-a[ariemaxi].j1-1);
        for(int i = 1; i <= k; i++){
            if(i == ariemaxi){
                continue;
            }
            int l = (a[i].i2-a[i].i1+1);
            int L = (a[i].j2-a[i].j1+1);
            if(l1 >= l && L1 >= L){
                incap++;
            }
        }
        fout << ariemax << ' ' << incap;
    }else{
        for(int i = 1; i <= k; i++){
            for(int j1 = a[i].j1; j1 <= a[i].j2; j1++){
                mat[a[i].i1][j1] = 1;
                mat[a[i].i2][j1] = 1;
            }
            for(int i1 = a[i].i1; i1 <= a[i].i2; i1++){
                mat[i1][a[i].j1] = 1;
                mat[i1][a[i].j2] = 1;
            }
        }
        int nrl = 0;
        for(int i = 1; i <= m; i++){
            bool ok = true;
            for(int j = 1; j <= n; j++){
                if(mat[j][i]==1){
                    ok = false;
                    break;
                }
            }
            if(ok){
                nrl++;
            }else{
                nrl = 0;
            }
            if(nrl > 1){
                coloana[i] = false;
            }else{
                coloana[i] = true;
            }
        }
        nrl=0;
        for(int i = 1; i <= n; i++){
            bool ok = true;
            for(int j = 1; j <= m; j++){
                if(mat[i][j]==1){
                    ok = false;
                    break;
                }
            }
            if(ok){
                nrl++;
            }else{
                nrl = 0;
            }
            if(nrl > 1){
                linia[i] = false;
            }else{
                linia[i] = true;
            }
        }
        for(int i = 1; i <= n; i++){
            if(linia[i]){
                for(int j = 1; j <= m; j++){
                    if(coloana[j]){
                        fout << mat[i][j] << ' ';
                    }
                }
                fout << '\n';
            }
        }
    }
    return 0;
}
