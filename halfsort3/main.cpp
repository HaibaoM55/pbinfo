#include <fstream>
#include <algorithm>
using namespace std;
#define int signed long long
ifstream cin("halfsort3.in");
ofstream cout("halfsort3.out");
int n, x;
int v[1004];
int par[1004], imp[1004];
int nrp=0, nri=0;
bool compara(int x, int y){
    return x > y;
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] % 2 == 0){
            nrp++;
            par[nrp] = v[i];
        }else{
            nri++;
            imp[nri] = v[i];
        }
    }
    sort(par+1, par+nrp+1);
    sort(imp+1, imp+nri+1, compara);
    nrp = 0;
    nri = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] % 2 == 0){
            nrp++;
            cout << par[nrp] << ' ';
        }else{
            nri++;
            cout << imp[nri] << ' ';
        }
    }
    return 0;
}
