#include <iostream>
using namespace std;
int n, m;
int a[104][104];
int dirx[5] = {0,0,1,-1};
int diry[5] = {1,-1,0,0};
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j=  1; j <= m; j++){
            int s = 0;
            for(int x = 0; x < 4; x++){
                int i1 = i+dirx[x];
                int j1 = j+diry[x];
                if(1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m){
                    s += a[i1][j1];
                }
            }
            if(a[i][j] > s){
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
