#include <iostream>
using namespace std;
int n, m, c;
int a[104][104];
int nr = 0;
int main()
{
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n-2*c; i++){
        for(int j = 1; j <= m-2*c; j++){
            bool ok = true;
            for(int x = 0; x <= 2*c; x++){
                for(int y = 0; y <= 2*c; y++){
                    if(a[i+x][j+y] > a[i+c][j+c]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                //cout << i << ' '  << j << '\n';
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
