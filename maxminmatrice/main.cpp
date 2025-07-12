#include <fstream>
using namespace std;
ifstream fin("maxminmatrice.in");
ofstream fout("maxminmatrice.out");
int n, m, x;
int vmin[1004];
int vmax = 0;
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> vmin[i];
        for(int j = 2; j <= m; j++){
            fin >> x;
            vmin[i] = min(vmin[i], x);
        }
        vmax = max(vmax, vmin[i]);
    }
    fout << vmax;
    return 0;
}
