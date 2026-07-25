#include <fstream>
using namespace std;
ifstream fin("gradek.in");
ofstream fout("gradek.out");
int n, k, x, y;
int f[104];
bool b[104][104];
int main(){
    fin >> n >> k;
    while(fin >> x >> y){
        if(!b[min(x, y)][max(x, y)]){
            b[min(x, y)][max(x, y)] = true;
            f[x]++;
            f[y]++;
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == f[k]){
            nr++;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(f[i] == f[k]){
        	fout << i << ' ';
        }
    }
    return 0;
}
