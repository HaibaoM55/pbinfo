#include <fstream>
using namespace std;
ifstream fin("gradepq.in");
ofstream fout("gradepq.out");
int n, x, y;
int p, q;
int f[104];
bool b[104][104];
int main(){
    fin >> n >> p >> q;
    while(fin >> x >> y){
        if(!b[min(x, y)][max(x, y)]){
            b[min(x, y)][max(x, y)] = true;
            f[x]++;
            f[y]++;
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(p <= f[i] && f[i] <= q){
            nr++;
        }
    }
    if(nr == 0){
    	fout << "nu exista";
    	return 0;
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(p <= f[i] && f[i] <= q){
            fout << i << ' ';
        }
    }
    return 0;
}
