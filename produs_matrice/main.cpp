#include <fstream>
using namespace std;
ifstream fin("produs_matrice.in");
ofstream fout("produs_matrice.out");
int n, m, p, q;
long long a[104][104], b[104][104], pr[104][104];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    fin >> p;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= p; j++){
            fin >> b[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= p; j++){
            pr[i][j] = 0;
            for(int z = 1; z <= m; z++){
                pr[i][j] += a[i][z]*b[z][j];
            }
            fout << pr[i][j] << ' ';
        }
        fout << '\n';
    }
}
