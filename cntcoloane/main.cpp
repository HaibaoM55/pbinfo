#include <iostream>
using namespace std;
int n, m;
int a[102][102];
bool f[1000004];
int main()
{
    cin >> n >> m;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(f[a[i][j]]){
                ok = false;
                break;
            }else{
                f[a[i][j]] = true;
            }
        }
        for(int i = 1; i <= n; i++){
            f[a[i][j]] = false;
        }
        if(ok){
            nr++;
        }
    }
    cout << nr;
    return 0;
}
