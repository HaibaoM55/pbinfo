#include <iostream>
using namespace std;
int n, m, x, y;
int v[7][9];
int dirx[10]={-2,-2,-1,-1,1,1,2,2};
int diry[10]={-1,1,-2,2,-2,2,-1,1};
void bt(int i, int j, int nr){
    if(1 <= i && i <= n){
        if(1 <= j && j <= m){
            if(v[i][j] == 0){
                v[i][j] = nr;
                if(nr == n*m){
                    for(int a = 1; a <= n; a++){
                        for(int b = 1; b <= m; b++){
                            cout << v[a][b] << ' ';
                        }
                        cout << '\n';
                    }
                    exit(0);
                }
                for(int d = 0; d < 8; d++){
                    bt(i+dirx[d], j+diry[d], nr+1);
                }
                v[i][j] = 0;
            }
        }
    }
}
int main(){
    cin >> n >> m >> x >> y;
    bt(x, y, 1);
}
