#include <fstream>
using namespace std;
ifstream fin("pacman_xi.in");
ofstream fout("pacman_xi.out");
int n, m;
long long r[41][41];
int main(){
    fin >> n >> m;
    r[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            r[i][j] += r[i-1][j-1]+r[i][j-1];
        }
    }
    fout << r[n][m];
    return 0;
}
