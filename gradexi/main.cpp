#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("gradexi.in");
ofstream fout("gradexi.out");
int n, m, x, y;
struct varf{
    int i;
    int grad;
}v[104];
bool compara(varf a, varf b){
    if(a.grad < b.grad){
        return true;
    }else if(a.grad == b.grad){
        if(a.i < b.i){
            return true;
        }
    }
    return false;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
     	v[i].i = i;
        v[i].grad = 0;
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].grad++;
        v[y].grad++;
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
        fout << v[i].i << ' ';
    }
    return 0;
}
