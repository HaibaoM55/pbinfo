#include <fstream>
using namespace std;
ifstream fin("sort.in");
ofstream fout("sort.out");
int n;
int nr = 0;
int v[1004], x[1004];
int f[4];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        f[v[i]]++;
    }
    for(int i = 1; i <= f[1]; i++){
        if(v[i] == 2){
            v[i] = 1;
            for(int j = 1; j <= f[2]; j++){
                if(v[f[1]+j] == 1){
                    v[f[1]+j] = 2;
                    break;
                }
            }
            nr++;
        }else if(v[i] == 3){
            v[i] = 1;
            for(int j = 1; j <= f[3]; j++){
                if(v[f[1]+f[2]+j] == 1){
                    v[f[1]+f[2]+j] = 3;
                    break;
                }
            }
            nr++;
        }
    }
    for(int i = 1; i <= f[2]; i++){
        if(v[f[1]+i] != 2){
            v[f[1]+i] = 1;
            for(int j = 1; j <= f[3]; j++){
                if(v[f[1]+f[2]+j] == 2){
                    v[f[1]+f[2]+j] = 3;
                    break;
                }
            }
            nr++;
        }
    }
    fout << nr;
    return 0;
}
