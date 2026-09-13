#include <fstream>
using namespace std;
ifstream fin("suma.in");
ofstream fout("suma.out");
int n, m;
int a[58][58][58];
int vr[58][58][58];
int f[63405];
struct cd{
    int x, y, z;
}coada[63405];
int ft[63405];
bool viz[63405];
int dirx[6] = {1, 1, 1};
int diry[7] = {1, 0, 1}
int main(){
    fin >> n;
    m = 1;
    int i = 1, j = 1;
    for(int z = 1; z <= n; z++){
        fin >> a[m][i][j];
        vr[m][i][j] = z;
        j++;
        if(j == m+1){
            i++;
            j=1;
        }
        if(i == m+1){
            m++;
            i=1;j=1;
        }
    }
    fout << m << ' ';
    int st = 1, dr = 1;
    coada[1] = {1,1,1};
    ft[1] = -1;
    while(st <= dr){
        for(int d = 0; d < 3; d++){
            int i = coada[st].y+dirx[d];
            int j = coada[st].z+diry[d];
            if(!viz[vr[coada[st].x+1][i][j]]){
                viz[vr[coada[st].x+1][i][j]] = true;
                dr++;
                coada[dr] = {coada[st].x+1, i, j};
                f[vr[coada[st].x+1][i][j]] = f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j];
                ft[vr[coada[st].x+1][i][j]] = vr[coada[st].x][coada[st].y][coada[st].z];
            }else{
                if(f[vr[coada[st].x+1][i][j]] > f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j]){
                    f[vr[coada[st].x+1][i][j]] = f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j];
                    ft[vr[coada[st].x+1][i][j]] = vr[coada[st].x][coada[st].y][coada[st].z];
                }
            }
        }
        st++;
    }
    return 0;
}
