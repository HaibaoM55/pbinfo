#include <fstream>
using namespace std;
ifstream fin("alinieri.in");
ofstream fout("alinieri.out");
int n, p, z;
int v[100004];
int f[100004];
int frecv[184];
int ff[184];
int main(){
    fin >> n >> p >> z;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        v[i] = v[i] % 180;
        frecv[v[i]]++;
    }
    int nr = 0;
    for(int zi = 1; zi <= z; zi++){
        for(int i = 0; i < 180; i++){
            f[i] += i;
            f[i] = f[i]%180;
            ff[f[i]] += frecv[i];
        }
        for(int i = 0; i < 180; i++){
            if(ff[i] >= p){
                nr++;
            }
            ff[i] = 0;
        }
    }
    fout << nr;
    return 0;
}
