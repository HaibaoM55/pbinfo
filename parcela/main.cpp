#include <fstream>
using namespace std;
ifstream fin("parcela.in");
ofstream fout("parcela.out");
int n, m;
int a[104][104];
bool viz[104][104];
int nr = 0;
int arie;
int amax, amaxi;
void fill(int i, int j){
    if(1 <= i && i <= n){
        if(1 <= j && j <= m){
            if(a[i][j] == 1 && !viz[i][j]){
                viz[i][j] = true;
                arie++;
                fill(i+1, j);
                fill(i-1, j);
                fill(i, j+1);
                fill(i, j-1);
            }
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!viz[i][j] && a[i][j] == 1){
                arie = 0;
                fill(i, j);
                nr++;
                if(arie > amax){
                    amax = arie;
                    amaxi = nr;
                }
            }
        }
    }
    fout << nr << ' ' << amax << ' ' << amaxi;
    return 0;
}
