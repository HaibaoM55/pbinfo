#include <fstream>
using namespace std;
ifstream fin("izolate.in");
ofstream fout("izolate.out");
int n, x, y;
bool f[104];
int main(){
    fin >> n;
    while(fin >> x >> y){
        f[x] = true;
        f[y] = true;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(!f[i]){
            nr++;
        }
    }
    fout << nr << ' ';
    for(int i = 1; i <= n; i++){
        if(!f[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
