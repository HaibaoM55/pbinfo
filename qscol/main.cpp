#include <fstream>
using namespace std;
ifstream fin("qscol.in");
ofstream fout("qscol.out");
int n;
int a[804][804];
bool compara(int i, int j){
    for(int x = 1; x <= n; x++){
        if(a[x][i] < a[x][j]){
            return false;
        }else if(a[x][i] > a[x][j]){
            return true;
        }
    }
}
bool b[804];
int f[804];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        b[i] = true;
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    for(int z = 1; z <= n; z++){
        int vmaxi;
        for(int i = 1; i <= n; i++){
            if(b[i]){
                vmaxi = i;
                break;
            }
        }
        for(int i = vmaxi+1; i <= n; i++){
            if(b[i]){
                if(compara(vmaxi, i)){
                    vmaxi = i;
                }
            }
        }
        f[z] = vmaxi;
        b[vmaxi] = false;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][f[j]] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
