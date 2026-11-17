#include <fstream>
using namespace std;
ifstream fin("moscraciun4.in");
ofstream fout("moscraciun4.out");
int n, m;
int a[104][104];
int dirx[6] = {0, 0, -1, 1};
int diry[7] = {1,-1,  0, 0};
int tircolmariocristian = 0, haideticatalin = 0;
void fill(int i, int j){
    if(a[i][j] == 3){
        tircolmariocristian++;
    }else if(a[i][j] == 4){
        haideticatalin++;
    }
    a[i][j] = 0;
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m){
            if(a[i1][j1] != 0){
                fill(i1, j1);
            }
        }
    }
}
int main(){
    fin >> n >> m;
    int i2, j2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 2){
               i2 = i;
               j2 = j;
            }
        }
    }
    fill(i2, j2);
    fout << tircolmariocristian << ' ' << haideticatalin;
    return 0;
}
