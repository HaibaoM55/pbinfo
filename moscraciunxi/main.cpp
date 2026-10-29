#include <iostream>
using namespace std;
int n, m;
bool capcana[14][14],viz[14][14];
int vmax = 0, rasp = 0;
int dirx[6] = {1,1,-1,-1};
int diry[7] = {1,-1,1,-1};
void bt(int i, int j, int nrp){
    if(i == n && j == n){
        rasp++;
        vmax = max(vmax, nrp);
        return;
    }
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n && 1 <= j1 && j1 <= n){
            if(!viz[i1][j1] && !capcana[i1][j1]){
                viz[i1][j1] = true;
                bt(i1, j1, nrp+1);
                viz[i1][j1] = false;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> capcana[i][j];
        }
    }
    viz[1][1] = true;
    bt(1, 1, 1);
    if(!rasp){
        cout << "Dorel :((";
        return 0;
    }
    cout << rasp << '\n';
    cout << vmax;
	return 0;
}
