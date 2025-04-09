#include <fstream>
using namespace std;
ifstream fin("competitie.in");
ofstream fout("competitie.out");
int n, q;
bool maibun[1004][1004];
int z[1004];
int main(){
    fin >> n >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        fin >> x >> y;
        z[y]++;
        maibun[y][x] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(z[j] == 0){
                z[j] = -1;
                fout << j << ' ';
                for(int j1 = 1; j1 <= n; j1++){
                    if(maibun[j1][j]){
                        maibun[j1][j] = false;
                        z[j1]--;
                    }
                }
                break;
            }
        }
    }
    return 0;
}
