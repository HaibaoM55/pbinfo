#include <fstream>
using namespace std;
ifstream fin("croco1.in");
ofstream fout("croco1.out");
int n, m;
int a[104][104];
int dirx[6] = {1,-1,1,-1};
int diry[6] = {1,-1,-1,1};
int leefill(int i, int j, int v[104][104]){
    if(v[i][j] == 0){
        v[i][j] = 3; // crocodil
        int nr = 1;
        for(int p = 0; p < 4; p++){
            int i1 = i+dirx[p];
            int j1 = j+diry[p];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    nr += leefill(i1, j1, v);
                }
            }
        }
        return nr;
    }else{
        return 0;
    }
}
int main(){
    fin >> n >> m;
    int nra = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 1){
                nra++;
            }
        }
    }
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0){
                int x = leefill(i,j, a);
                if(x > vmax){
                    vmax = x;
                }
            }
        }
    }
    fout << vmax << ' ' << n*m-vmax-nra;
    return 0;
}
