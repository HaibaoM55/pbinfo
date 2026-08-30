#include <fstream>
using namespace std;
ifstream fin("countsub.in");
ofstream fout("countsub.out");
int n, x, y, z, k;
pair<int, int> v[1004];
int r[1004];
bool esteFiu[1004];
int calc(int nod){
    if(nod == 0) return 0;
    r[nod] = calc(v[nod].first) + calc(v[nod].second) + 1;
    return r[nod];
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> y >> z;
        v[i] = {y, z};
        if(y != 0){
            esteFiu[y] = true;
        }
        if(z != 0){
            esteFiu[z] = true;
        }
    }

    int radacina = 1;
    for(int i = 1; i <= n; i++){
        if(!esteFiu[i]){
            radacina = i;
        }
    }
    calc(radacina);
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> x;
        fout << r[x] << '\n';
    }
    return 0;
}
