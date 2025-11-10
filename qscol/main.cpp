#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("qscol.in");
ofstream fout("qscol.out");
int n;
int a[804][804];
int f[804];
bool compara(int c1, int c2) {
    for (int x = 1; x <= n; x++) {
        if (a[x][c1] < a[x][c2]) return true;
        if (a[x][c1] > a[x][c2]) return false;
    }
    return false;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    sort(f+1, f+n+1, compara);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][f[j]] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
