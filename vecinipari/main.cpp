#include <iostream>
using namespace std;
int n, m;
int dirx[4] = {0,0,1,-1};
int diry[4] = {1,-1,0,0};
int a[104][104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bool ok = true;
            for(int dir = 0; dir < 4; dir++){
            	int i1 = i+dirx[dir];
                int j1 = j+diry[dir];
                if(1 <= i1 && i1 <= n){
                    if(1 <= j1 && j1 <= m){
                        if(a[i1][j1] % 2 != 0){
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if(ok){
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
