#include <fstream>
using namespace std;
ifstream fin("siruri.in");
ofstream fout("siruri.out");
int n, k;
int a[104][104];
int v[100004];
int f[3];
int dirx[6] = {1,-1,0,0};
int diry[7] = {0,0,-1,1};
struct poz{
    int i, j;
}rasp[100004];
bool mergef(int i, int j, int kk){
    if(kk == k+1){
        return true;
    }
    if(i < 1 || i > n || j < 1 || j > n){
        return false;
    }
    if(a[i][j] != v[kk]){
        return false;
    }
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(mergef(i1, j1, kk+1)){
            rasp[kk].i = i;
            rasp[kk].j = j;
            return true;
        }
    }
    return false;
}
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    for(int i = 1; i <= k; i++){
        fin >> v[i];
        f[v[i]]++;
    }
    fout << f[0] << ' ' << f[1];
    return 0;
    int st = 1, dr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mergef(i, j, 1)){
                for(int z = 1; z <= k; z++){
                    fout << rasp[z].i << ' '<< rasp[z].j << '\n';
                }
                return 0;
            }else if(f[0] == f[1]){
                bool doaregale = false;
                if(a[i][j] == 0 && a[i][j+1] == 1){
                    if(a[i+1][j] == 1 && a[i+1][j+1] == 0){
                        doaregale = true;
                    }
                }
                if(a[i][j] == 1&& a[i][j+1] == 0){
                    if(a[i+1][j] == 0 && a[i+1][j+1] == 1){
                        doaregale = true;
                    }
                }
                if(doaregale){
                    for(int tung = 1; tung <= f[0]; tung++){
                        fout << i << ' ' << j << '\n' << i << ' ' << j+1<< '\n';
                    }
                    return 0;
                }
            }else if(f[0] == f[1]+1){
                bool doaregale = false;
                if(a[i][j] == 0 && a[i][j+1] == 1){
                    if(a[i+1][j] == 1 && a[i+1][j+1] == 0){
                        doaregale = true;
                    }
                }
                if(a[i][j] == 1&& a[i][j+1] == 0){
                    if(a[i+1][j] == 0 && a[i+1][j+1] == 1){
                        doaregale = true;
                    }
                }
                if(doaregale){
                    for(int tung = 1; tung <= f[1]; tung++){
                        if(a[i][j] == 0){
                            fout << i << ' ' << j << '\n' << i << ' ' << j+1<< '\n';
                        }else{
                            fout << i << ' ' << j+1 << '\n' << i << ' ' << j << '\n';
                        }
                    }
                    if(a[i][j] == 0){
                        fout << i << ' ' << j << '\n';
                    }else{
                        fout << i << ' ' << j+1 << '\n';
                    }
                    return 0;
                }
            }else if(f[0] == f[1]-1){
                bool doaregale = false;
                if(a[i][j] == 0 && a[i][j+1] == 1){
                    if(a[i+1][j] == 1 && a[i+1][j+1] == 0){
                        doaregale = true;
                    }
                }
                if(a[i][j] == 1&& a[i][j+1] == 0){
                    if(a[i+1][j] == 0 && a[i+1][j+1] == 1){
                        doaregale = true;
                    }
                }
                if(doaregale){
                    for(int tung = 1; tung <= f[0]; tung++){
                        if(a[i][j] == 1){
                            fout << i << ' ' << j << '\n' << i << ' ' << j+1<< '\n';
                        }else{
                            fout << i << ' ' << j+1 << '\n' << i << ' ' << j << '\n';
                        }
                    }
                    if(a[i][j] == 1){
                        fout << i << ' ' << j << '\n';
                    }else{
                        fout << i << ' ' << j+1 << '\n';
                    }
                    return 0;
                }
            }
        }
    }
    fout << -1;
    return 0;
}
