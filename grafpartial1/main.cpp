#include <fstream>
using namespace std;
ifstream fin("graf_partial_1.in");
ofstream fout("graf_partial_1.out");
int n, x, y;
int nr = 0;
int grad[104];
bool a[104][104];
int vmax = 0, vmin = 2e9;
int vmaxi, vmini;
int main(){
    fin >> n;
    while(fin >> x >> y){
        a[x][y] = true;
        a[y][x] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]){
                grad[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(grad[i] > vmax){
            vmax = grad[i];
        }
        if(grad[i] < vmin){
            vmin = grad[i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] && ((grad[i] == vmax && grad[j] == vmin) || (grad[j] == vmax && grad[i] == vmin))){
                nr++;
                a[i][j] = false;
            }
        }
    }
    fout << nr/2 << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
