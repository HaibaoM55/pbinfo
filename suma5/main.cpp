#include <fstream>
using namespace std;
ifstream fin("suma5.in");
ofstream fout("suma5.out");
unsigned short n, m;
int f[63405];
unsigned short rasp[63405];
struct cd{
    unsigned short x, y, z;
}coada[63405];
unsigned short ft[63405];
bool viz[63405];
unsigned short dirx[6] = {1, 1, 0, 0};
unsigned short diry[7] = {1, 0, 1, 0};
int main(){
    unsigned short a[58][58][58];
    unsigned short vr[58][58][58];
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
    m--;
    fout << m << ' ';
    int st = 1, dr = 1;
    coada[1] = {1,1,1};
    ft[1] = 65534;
    f[1] = a[1][1][1];
    while(st <= dr){
        if(coada[st].x == m) break;
        for(int d = 0; d < 4; d++){
            int i = coada[st].y+dirx[d];
            int j = coada[st].z+diry[d];
            if(!viz[vr[coada[st].x+1][i][j]]){
                viz[vr[coada[st].x+1][i][j]] = true;
                dr++;
                coada[dr] = {coada[st].x+1, i, j};
                f[vr[coada[st].x+1][i][j]] = f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j];
                ft[vr[coada[st].x+1][i][j]] = vr[coada[st].x][coada[st].y][coada[st].z];
            }else{
                if(f[vr[coada[st].x+1][i][j]] >= f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j]){
                    f[vr[coada[st].x+1][i][j]] = f[vr[coada[st].x][coada[st].y][coada[st].z]]+a[coada[st].x+1][i][j];
                    ft[vr[coada[st].x+1][i][j]] = vr[coada[st].x][coada[st].y][coada[st].z];
                }
            }
        }
        st++;
    }
//    fout << '\n';
//    for(int i = 1; i <= m; i++){
//        for(int j = 1; j <= i; j++){
//            for(int k = 1; k <= i; k++){
//                fout << f[vr[i][j][k]] << ' ';
//            }
//            fout << '\n';
//        }
//        fout << endl;
//        fout << endl;
//        fout << endl;
//    }

    int rx=m,ry=m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(f[vr[m][i][j]] == 0) continue;
            if(f[vr[m][rx][ry]] > f[vr[m][i][j]]){
                rx = i;
                ry = j;
            }
        }
    }
    fout << f[vr[m][rx][ry]] << '\n';
    int p = vr[m][rx][ry];
    while(ft[p] != 65534){
        rasp[0]++;
        rasp[rasp[0]] = p;
        p = ft[p];
    }
    rasp[0]++;
    rasp[rasp[0]] = 1;
    for(int i = rasp[0]; i >= 1; i--){
        fout << rasp[i] << ' ';
    }
    return 0;
}
