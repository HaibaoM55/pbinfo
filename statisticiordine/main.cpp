#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("statisticiordine.in");
ofstream fout("statisticiordine.out");
int n, k;
unsigned int v[4000004];
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    fout << v[k];
    v[0] = -1;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] != v[i-1]){
            nr++;
        }
    }
    return 0;
}
