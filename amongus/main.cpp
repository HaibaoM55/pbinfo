#include <fstream>
using namespace std;
ifstream cin("amongus.in");
ofstream cout("amongus.out");
int cer, n, m;
int a[104][104];
int rasp = 0;
int dirx[9] = {1,-1, 1, 1, 0, 0,-1,-1};
int diry[9] = {0, 0, 1,-1, 1,-1, 1,-1};
void fill(int i, int j){
    if(cer == 3 && a[i][j] == 2){
        rasp++;
    }
    a[i][j] = 3;
    for(int d = 0; d < 8; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(a[i1][j1] == 0 || a[i1][j1] == 2){
                    fill(i1, j1);
                }
            }
        }
    }
}
int main(){
    cin >> cer;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(cer == 1 && a[i][j] == 0){
                rasp++;
            }
        }
    }
    if(a[1][1] == 1){
        cout << "misiune esuata";
        return 0;
    }
    fill(1, 1);
    if(cer == 1 || cer == 3){
        cout << rasp;
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
