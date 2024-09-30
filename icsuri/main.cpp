#include <iostream>
using namespace std;
int n, m;
bool a[1001][1001];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = true;
        for(int p1 = x-1; p1 >= x-z && p1 > 0; p1--){
            int p2 = y-x+p1;
            if(0 < p2 && p2 <= n){
                a[p1][p2]=true;
            }else{
                break;
            }
        }
        for(int p1 = x-1; p1 >= x-z && p1 > 0; p1--){
            int p2 = x+y-p1;
            if(0 < p2 && p2 <= n){
                a[p1][p2]=true;
            }else{
                break;
            }
        }
        for(int p1 = x+1; p1 <= x+z && p1 <= n; p1++){
            int p2 = x+y-p1;
            if(0 < p2 && p2 <= n){
                a[p1][p2]=true;
            }else{
                break;
            }
        }
        for(int p1 = x+1; p1 <= x+z && p1 <= n; p1++){
            int p2 = y-x+p1;
            if(0 < p2 && p2 <= n){
                a[p1][p2]=true;
            }else{
                break;
            }
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == false){
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
