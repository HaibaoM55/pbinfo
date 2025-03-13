#include <fstream>
using namespace std;
ifstream fin("betasah.in");
ofstream fout("betasah.out");
int n,d,k;
char b[1001][1001];
struct debug{
    int x, y;
}dbg[1001][1001];
struct dama{
    int x, y;
}v[104];
int main()
{
    fin >> n >> d >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            b[i][j] = '0';
        }
    }
    for(int i = 1; i <= d; i++){
        fin >> v[i].x >> v[i].y;
        b[v[i].x][v[i].y] = 'D';
    }
    for(int i = 1; i <= k; i++){
        int x, y;
        fin >> x >> y;
        b[x][y] = 'G';
    }
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        int nr = 0;
        for(int j = 1; j <= i; j++){
            if(b[i][j] == 'D' || b[i][j] == '0'){
                nr++;
            }
        }
        vmax = max(vmax, nr);
    }
    fout << vmax << '\n';
    for(int i = 1; i <= d; i++){
        int i1 = v[i].x, j1 = v[i].y;
        //orizontal
        for(int j = j1-1; j >= 1; j--){
            if(b[i1][j] == 'G'){
                break;
            }
            if(b[i1][j] == '0'){
                b[i1][j] = 'X';
            }
        }
        for(int j = j1+1; j <= i1; j++){
            if(b[i1][j] == 'G'){
                break;
            }
            if(b[i1][j] == '0'){
                b[i1][j] = 'X';
            }
        }
        //vertical
        for(int j = i1; j >= 1; j--){
            if(b[j][j1] == '0'){
                b[j][j1] = 'X';
            }
            if(b[j][j1] == 'G'){
                break;
            }
        }
        for(int j = i1+1; j <= n; j++){
            if(b[j][j1] == '0'){
                b[j][j1] = 'X';
            }
            if(b[j][j1] == 'G'){
                break;
            }
        }
        //in diagonala
        for(int j = 1; j <= n; j++){
            int i2 = i1+j;
            int j2 = j1+j;
            if(i2 > n){
                break;
            }
            if(j2 > i2){
                break;
            }
            if(b[i2][j2] == 'G'){
                break;
            }
            if(1 <= i2 && i2 <= n && 1 <= j2 <= i2){
                if(b[i2][j2] == '0'){
                    b[i2][j2] = 'X';
                }
            }
        }
        for(int j = 1; j <= n; j++){
            int i2 = i1+j;
            int j2 = j1-j;
            if(i2 > n){
                break;
            }
            if(j2 < 1){
                break;
            }
            if(b[i2][j2] == 'G'){
                break;
            }
            if(1 <= i2 && i2 <= n && 1 <= j2 <= i2){
                if(b[i2][j2] == '0'){
                    b[i2][j2] = 'X';
                }
            }
        }
        for(int j = 1; j <= n; j++){
            int i2 = i1-j;
            int j2 = j1-j;
            if(i2 < 1){
                break;
            }
            if(j2 < 1){
                break;
            }
            if(b[i2][j2] == 'G'){
                break;
            }
            if(1 <= i2 && i2 <= n && 1 <= j2 <= i2){
                if(b[i2][j2] == '0'){
                    b[i2][j2] = 'X';
                }
            }
        }
        for(int j = 1; j <= n; j++){
            int i2 = i1-j;
            int j2 = j1+j;
            if(i2 < 1){
                break;
            }
            if(j2 > n){
                break;
            }
            if(b[i2][j2] == 'G'){
                break;
            }
            if(1 <= i2 && i2 <= n && 1 <= j2 <= i2){
                if(b[i2][j2] == '0'){
                    b[i2][j2] = 'X';
                }
            }
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(b[i][j] == 'X'){
                nr++;
            }
        }
    }
    fout << nr;
    return 0;
}
