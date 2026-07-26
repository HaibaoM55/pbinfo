#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("ordgrext.in");
ofstream fout("ordgrext.out");
int n, m, x, y;
struct varf{
    int i,ext=0;
}v[104];
bool compara(varf a, varf b){
    if(a.ext < b.ext){
        return true;
    }else if(a.ext == b.ext && a.i < b.i){
        return true;
    }
    return false;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        v[i].i = i;
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].ext++;
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
        fout << v[i].i << ' ';
    }
    return 0;
}
