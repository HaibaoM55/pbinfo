#include<iostream>
using namespace std;
bool a[101][101];
int n, m, x, y;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        a[x][y]=true;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][k] && a[k][j]){
                    a[i][j]=true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
}
