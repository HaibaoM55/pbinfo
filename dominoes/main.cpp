#include <fstream>
using namespace std;
ifstream fin("dominoes.in");
ofstream fout("dominoes.out");
int n, k;
int x, y, x1, y1;
bool a[3][100004];
bool viz[3][100004];
int q;
struct poz{
    int i, j;
}coada[200004];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,1,-1};
bool verif(){
    for(int j = 1; j <= n; j++){
        if(!viz[2][j] && !a[2][j]){
            if(j < n && !a[2][j+1] && !viz[2][j+1]){
                viz[2][j] = true;
                viz[2][j+1] = true;
            }else if(!a[1][j] && !viz[1][j]){
                viz[1][j] = true;
                viz[2][j] = true;
            }
        }
    }
    for(int j = 1; j <= n; j++){
        if(!viz[1][j] && !a[1][j]){
            if(j < n && !a[1][j+1] && !viz[1][j+1]){
                viz[1][j] = true;
                viz[1][j+1] = true;
            }else if(!a[2][j] && !viz[2][j]){
                viz[1][j] = true;
                viz[2][j] = true;
            }
        }
    }
    bool ok = true;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            if(!viz[i][j] && !a[i][j]){
                ok = false;
            }
            viz[i][j] = false;
        }
    }
    if(ok){
        return true;
    }else{
        for(int j = n; j >= 1; j--){
            if(!viz[2][j] && !a[2][j]){
                if(j < n && !a[2][j+1] && !viz[2][j+1]){
                    viz[2][j] = true;
                    viz[2][j+1] = true;
                }else if(!a[1][j] && !viz[1][j]){
                    viz[1][j] = true;
                    viz[2][j] = true;
                }
            }
        }
        for(int j = 1; j <= n; j++){
            if(!viz[1][j] && !a[1][j]){
                if(j < n && !a[1][j+1] && !viz[1][j+1]){
                    viz[1][j] = true;
                    viz[1][j+1] = true;
                }else if(!a[2][j] && !viz[2][j]){
                    viz[1][j] = true;
                    viz[2][j] = true;
                }
            }
        }
        bool ok1 = true;
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= n; j++){
                if(!viz[i][j] && !a[i][j]){
                    ok1 = false;
                }
                viz[i][j] = false;
            }
        }
        return ok1;
    }
}
int main(){
    fin >> n >> k;
    for(int i = 1; i <= k; i++){
        fin >> x >> y;
        a[x][y] = true;
    }
    fin >> q;
    for(int z1z = 1; z1z <= q; z1z++){
        fin >> x >> y >> x1 >> y1;
        a[x][y] = true;
        a[x1][y1] = true;
        fout << verif() << '\n';
        a[x][y] = false;
        a[x1][y1] = false;
    }
    return 0;
}
