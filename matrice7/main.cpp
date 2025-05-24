#include <fstream>
using namespace std;
ifstream fin("matrice7.in");
ofstream fout("matrice7.out");
int n, m;
int a[104][104];
int vmax = 0;
int c[104];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(i == 1){
                c[j] = a[i][j];
            }else{
                c[j] = min(a[i][j], c[j]);
            }
            vmax= max(vmax, a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == vmax){
                a[i][j] = c[j];
            }
            fout << a[i][j]<<' ';
        }
        fout << '\n';
    }
    return 0;
}
