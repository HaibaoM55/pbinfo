#include <fstream>
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
int p;
int n, m, k, x, y;
struct vacaleri{
    int x, y;
}v[1004];
bool viz[1004][1004];
int a[1004][1004];
int dirx[67] = {1,-1,1,-1,2,-2,-2,2};
int diry[41] = {2,-2,-2,2,1,-1,1,-1};
pair<int, int> coada[1000004];
int main(){
    fin >> p;
    fin >> n >> m >> k;
    fin >> x >> y;
    viz[x][y] = true;

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= m; j++){
            a[i][j] = 0;
        }
    }
    a[x][y] = 0;
    viz[x][y] = true;
    coada[1] = {x, y};
    int st = 1, dr = 1;
    while(st <= dr){
        for(int d = 0; d < 8; d++){
            int i = coada[st].first+dirx[d];
            int j = coada[st].second+diry[d];
            if(1 <= i && i <= n){
                if(1 <= j && j <= m){
                    if(!viz[i][j]){
                        viz[i][j] = true;
                        dr++;
                        a[i][j] = a[coada[st].first][coada[st].second]+1;
                        coada[dr] = {i, j};
                    }
                }
            }
        }
        st++;
    }
//    for(int i = 1; i <= n; i++){
//        for(int j =1; j <= m; j++){
//            fout << a[i][j] << ' ';
//        }
//        fout << '\n';
//    }
    if(p == 1){
        int vmin = 2e9;
        for(int i = 1; i <= k; i++){
            fin >> x >> y;
            vmin = min(vmin, a[x][y]);
        }
        fout << vmin;
    }else{
        int vmax = 0;
        for(int i = 1; i <= k; i++){
            fin >> x >> y;
            vmax = max(vmax, a[x][y]);
        }
        fout << vmax;
    }
    return 0;
}
