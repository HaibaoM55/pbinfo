#include <fstream>
using namespace std;
ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");
int n, m;
int a[104][104];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
