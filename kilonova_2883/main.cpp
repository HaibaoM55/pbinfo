#include <iostream>
using namespace std;
int n, m;
char a[1004][1004];
pair<int, int> coada[1000004];
int pasi[1004][1004];
bool viz[1004][1004];
int dirx[12] = {-2,-1,-1,-1,0,0,0,0,1,1,1,2};
int diry[12] = {0,-1,0,1,-2,-1,1,2,-1,0,1,0};
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int st = 1, dr = 1;
    coada[1] = {1, 1};
    while(st <= dr){
        int i = coada[st].first;
        int j = coada[st].second;
        for(int d = 0; d < 12; d++){
            int i1 = i+dirx[d];
            int j1 = j+diry[d];
            if(1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m){
                if(!viz[i1][j1] && a[i1][j1] == '.'){
                    viz[i1][j1] = true;
                    pasi[i1][j1] = pasi[i][j]+1;
                    dr++;
                    coada[dr] = {i1, j1};
                }
            }
        }
        st++;
    }
    cout << pasi[n][m];
	return 0;
}
