#include <fstream>
using namespace std;
ifstream fin("graf_partial_5.in");
ofstream fout("graf_partial_5.out");
int n, k, x, y;
int f[104];
bool b[104][104];
int main(){
    fin >> n >> k;
    while(fin >> x >> y){
        if(!b[x][y]){
            f[x]++;
            f[y]++;
            b[x][y] = true;
            b[y][x] = true;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(b[i][j] && f[i] >= k && f[j] >= k){
                b[i][j] = false;
            }
            fout << b[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
