#include <iostream>
using namespace std;
int n, nr = 0;
int a[22][22];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool ok = true;
            if(i != 1){
                if(a[i-1][j] >= a[i][j]){
                    ok = false;
                }
            }
            if(i != n){
                if(a[i+1][j] >= a[i][j]){
                    ok = false;
                }
            }
            if(j != 1){
                if(a[i][j-1] >= a[i][j]){
                    ok = false;
                }
            }
            if(j != n){
                if(a[i][j+1] >= a[i][j]){
                    ok = false;
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
