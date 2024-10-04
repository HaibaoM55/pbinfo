#include <iostream>
using namespace std;
int n, m;
bool a[1004][1004];
bool b[1004][1004];
int vx[5]={0,  0, 0, -1, 1};
int vy[5]={0, -1, 1,  0, 0};
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    bool ok = true;
    int nr = 0;
    while(ok){
        ok = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                b[i][j] = a[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j]){
                    int nrv = 0;
                    for(int x = 1; x <= 4; x++){
                        int i1 = i+vx[x];
                        int j1 = j+vy[x];
                        if(1 <= i1 && i1 <= n){
                            if(1 <= j1 && j1 <= m){
                                if(b[i1][j1] == 0){
                                    nrv++;
                                }
                            }
                        }
                    }
                    if(nrv >= 2){
                        a[i][j] = 0;
                        ok = true;
                    }
                }
            }
        }
        if(ok){
            nr++;
        }
    }
    bool doarapa = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                doarapa = false;
                break;
            }
        }
    }
    if(doarapa){
        cout << nr;
    }else{
        cout << -1;
    }
    return 0;
}
