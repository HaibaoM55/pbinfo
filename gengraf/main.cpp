#include <fstream>
using namespace std;
ifstream fin("gengraf.in");
ofstream fout("gengraf.out");
int n;
int b[7][7];
pair<int,int> v[16];
int main(){
    fin >> n;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            nr++;
            v[nr] = {i, j};
        }
    }
    int M = 1 << nr;
    fout << M << '\n';
    for(int mask = 0; mask < M; mask++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                b[i][j] = 0;
            }
        }
        for(int k = 1; k <= nr; k++){
            if(mask & (1 << (k-1))){
                b[v[k].first][v[k].second] = 1;
                b[v[k].second][v[k].first] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                fout << b[i][j] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';
    }
    return 0;
}
