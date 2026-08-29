#include <fstream>
#include <vector>
using namespace std;
ifstream fin("bipartit.in");
ofstream fout("bipartit.out");
int n, m;
int x, y;
vector<int> v[104];
bool b[104][104];
bool bb[104];
int a[104], vb[104];
bool viz[104];
void visit(int k){
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        if(!b[x][y]){
            v[x].push_back(y);
            b[x][y] = true;
            v[y].push_back(x);
            b[y][x] = true;
        }
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> a[i];
        bb[a[i]] = true;
    }
    bool ok = true;
    for(int i = 1; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            if(b[a[i]][a[j]]){
                ok = false;
                break;
            }
        }
    }
    m = 0;
    for(int i = 1; i <= n; i++){
        if(!bb[i]){
            m++;
            vb[m] = i;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            if(b[vb[i]][vb[j]]){
                ok = false;
                break;
            }
        }
    }
    visit(1);
    for(int i = 1; i <= n;  i++){
        if(!viz[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        fout << "DA";
    }else{
        fout << "NU";
    }
    return 0;
}
