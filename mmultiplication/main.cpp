#include <fstream>
using namespace std;
ifstream fin("mmultiplication.in");
ofstream fout("mmultiplication.out");
int n, m,m1, p, q;
long long a[1004][1004], b[1004][1004], pr[1004][1004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    fin >> m1 >> p;
    if(m1 != m){
        fout << -1;
        return 0;
    }
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
