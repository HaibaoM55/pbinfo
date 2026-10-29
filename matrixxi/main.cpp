#include <iostream>
using namespace std;
int n, m;
int a[10][10];
int nr = 0, rasp = 0;
int dirx[6] = {0,0,1,-1};
int diry[7] = {1,-1,0,0};
void bt(int i, int j){
    if(nr == 0){
        rasp++;
        return;
    }
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m){
            if(a[i1][j1]){
                a[i1][j1]--;
                nr--;
                bt(i1, j1);
                a[i1][j1]++;
                nr++;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            nr += a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    a[x][y]--;
    nr--;
    bt(x, y);
    if(rasp){
        cout << rasp;
	}else{
        cout << "Mr. Anderson wins!";
	}
	return 0;
}
