#include <iostream>
using namespace std;
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,-1,1};
char a[1005][1005];
int n, m;
void fill(int i, int j){
    int nr = 0;
    for(int d = 0; d < 4; d++){
        int i1 = i + dirx[d];
        int j1 = j + diry[d];
        if(a[i1][j1] == '.'){
            nr++;
        }
    }
    if(nr == 1){
        if(a[i-1][j] == '.'){
            a[i-1][j] = '^';
            a[i][j] = 'v';
            i--;
        }else if(a[i][j-1] == '.'){
            a[i][j-1] = '<';
            a[i][j] = '>';
            j--;
        }else if(a[i+1][j] == '.'){
            a[i][j] = '^';
            a[i+1][j] = 'v';
            i++;
        }else{
            a[i][j] = '<';
            a[i][j+1] = '>';
            j++;
        }
        for(int d = 0; d < 4; d++){
            int i1 = i + dirx[d];
            int j1 = j + diry[d];
            if(a[i1][j1] == '.'){
                fill(i1, j1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '.'){
                fill(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '.') {
                cout << "altadata";
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
