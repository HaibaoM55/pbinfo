#include <iostream>
using namespace std;
int n, m;
int nrmax = 0;
char a[1004][1004];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int nr;
            if(a[i][j] != a[i][j-1]){
                nr = 0;
                for(int x = 0; x <= m-j; x++){
                    if(a[i][j] != a[i][j+x]) break;
                    nr++;
                }
                nrmax = max(nrmax, nr);
            }
            if(a[i][j] != a[i-1][j]){
                nr = 0;
                for(int x = 0; x <= n-i; x++){
                    if(a[i][j] != a[i+x][j]) break;
                    nr++;
                }
                nrmax = max(nrmax, nr);
            }
            if(a[i][j] != a[i-1][j-1]){
                nr = 0;
                for(int x = 0; x <= n-i && x <= m-j; x++){
                    if(a[i][j] != a[i+x][j+x]) break;
                    nr++;
                }
                nrmax = max(nrmax, nr);
            }

            if(a[i][j] != a[i+1][j-1]){
                nr = 0;
                for(int x = 0; x < i && x <= m-j; x++){
                    if(a[i][j] != a[i-x][j+x]) break;
                    nr++;
                }
                nrmax = max(nrmax, nr);
            }
        }
    }
    cout << nrmax;
    return 0;
}
