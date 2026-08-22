#include <fstream>
using namespace std;
#define B 50
#define int long long
ifstream fin("bemo.in");
ofstream fout("bemo.out");
int n, m;
int a[1504][1504];
struct bloc{
    long long vmin;
    int p, q;
}vmini1[B][B], vmini2[B][B];
void drum(int k, int l){
    fout << a[k][l] << ' ';
}
long long best1 = 1e18, best2 = 1e18;
int p1 = -1, q1 = -1, p2 = -1, q2 = -1;
int aib[2250004];
void adauga(long long val, int p, int q, int x, int y){
    if(p == -1 || (p == x && q == y)){
        return;
    }
    if(val < best1){
        best2 = best1;
        p2 = p1;
        q2 = q1;

        best1 = val;
        p1 = p;
        q1 = q;
    }
    else if(val < best2){
        best2 = val;
        p2 = p;
        q2 = q;
    }
}
void query(int x, int y, int k, int l){
    int bi1 = (x-1)/B;
    int bj1 = (y-1)/B;
    int bi2 = (k-1)/B;
    int bj2 = (l-1)/B;
    for(int bi = bi1; bi <= bi2; bi++){
        for(int bj = bj1; bj <= bj2; bj++){
            int sx = bi * B + 1;
            int sy = bj * B + 1;
            int dx = min(n, sx + B - 1);
            int dy = min(m, sy + B - 1);
            if(x <= sx && dx <= k && y <= sy && dy <= l){
                adauga(vmini1[bi][bj].vmin,vmini1[bi][bj].p,vmini1[bi][bj].q,x,y);
                adauga(vmini2[bi][bj].vmin,vmini2[bi][bj].p,vmini2[bi][bj].q,x,y);
            }
            else{
                for(int i = max(x, sx); i <= min(k, dx); i++){
                    for(int j = max(y, sy); j <= min(l, dy); j++){
                        if(i == x && j == y){
                            continue;
                        }
                        adauga(a[i][j], i, j, x, y);
                    }
                }
            }
        }
    }
}
void deplas(int i, int j, int fi, int fj){
    if(i == fi && j == fj){
        return;
    }
    if(i == fi){
        for(int l = j + 1; l <= fj; l++)
            drum(i, l);
        return;
    }
    if(j == fj){
        for(int k = i + 1; k <= fi; k++)
            drum(k, j);
        return;
    }
    best1 = 1e18;best2 = 1e18;
    p1 = -1;q1 = -1;p2 = -1;q2 = -1;
    query(i, j, fi, fj);
    if(p1 == -1)
        return;
    int p, q;
    if(p1 == fi && q1 == fj){
        p = p2;
        q = q2;
    }else{
        p = p1;
        q = q1;
    }
    if(p == -1){
        return;
    }
    if(p == i){
        for(int l = j + 1; l <= q; l++){
            drum(i, l);
        }
    }
    else if(q == j){
        for(int k = i + 1; k <= p; k++){
            drum(k, j);
        }
    }
    else{
        deplas(i, j, p, q);
    }
    deplas(p, q, fi, fj);
}
int ik1, jk1;
signed main(){
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            vmini1[i][j].vmin = 1e18;
            vmini1[i][j].p = -1;
            vmini1[i][j].q = -1;
            vmini2[i][j] = vmini1[i][j];
        }
    }
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 1){
                ik1 = i;
                jk1 = j;
            }
            int bi = (i - 1) / B;
            int bj = (j - 1) / B;
            if(a[i][j] < vmini1[bi][bj].vmin){
                vmini2[bi][bj] = vmini1[bi][bj];
                vmini1[bi][bj].vmin = a[i][j];
                vmini1[bi][bj].p = i;
                vmini1[bi][bj].q = j;
            }
            else if(a[i][j] < vmini2[bi][bj].vmin){
                vmini2[bi][bj].vmin = a[i][j];
                vmini2[bi][bj].p = i;
                vmini2[bi][bj].q = j;
            }
        }
    }
    fout << a[1][1] << ' ';
    deplas(1, 1, ik1, jk1);
    deplas(ik1, jk1, n, m);
    return 0;
}
