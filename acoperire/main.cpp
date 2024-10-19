#include <iostream>
using namespace std;
int n, m, k;
bool a[1003][1003];
int x, y, z;
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> x >> y >> z;
        //NE
        z--;
        a[x][y] = true;
        for(int j = 1; j <= z; j++){
            if(x+j <= n && y+j <= m){
                a[x+j][y+j] = true;
            }else{
                break;
            }
        }
        //NV
        for(int j = 1; j <= z; j++){
            if(x-j >= 1 && y+j <= m){
                a[x-j][y+j] = true;
            }else{
                break;
            }
        }
        //SE
        for(int j = 1; j <= z; j++){
            if(x-j >= 1 && y-j >= 1){
                a[x-j][y-j] = true;
            }else{
                break;
            }
        }
        //SV
        for(int j = 1; j <= z; j++){
            if(x+j <= n && y-j >= 1){
                a[x+j][y-j] = true;
            }else{
                break;
            }
        }
    }
    int s = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == false){
                s++;
            }
        }
    }
    cout << s;
    return 0;
}
