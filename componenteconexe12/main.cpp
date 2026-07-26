#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("componenteconexe12.in");
ofstream fout("componenteconexe12.out");
int n, m, x, y;
bool v[104][104];
bool viz[104];
int p = 0, pog;
vector<int> ccog[104], cc[104];
void visit(int k){
    cc[p].push_back(k);
    viz[k] = true;
    for(int i = 1; i <= n; i++){
        if(!viz[i] && v[i][k]){
            viz[i] = true;
            visit(i);
        }
    }
}
void init(){
    p = 0;
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            p++;
            visit(i);
            sort(cc[p].begin(), cc[p].end());
        }
    }
    for(int i = 1; i <= p; i++){
        ccog[i] = cc[i];
    }
    pog = p;
}
bool faramodif(){
    p = 0;
    for(int i = 1; i <= n; i++){
        viz[i] = false;
        cc[i].clear();
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            p++;
            visit(i);
            sort(cc[p].begin(), cc[p].end());
        }
    }
    if(p != pog){
        return false;
    }
    for(int i = 1; i <= pog; i++){
        if(cc[i] != ccog[i]){
            return false;
        }
    }
    return true;
}
pair<int, int> rasp[10004];
int main(){
    fin >> n >> m;
    while(fin >> x >> y){
        v[x][y] = true;
        v[y][x] = true;
    }
    init();
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!v[i][j] && i != j){
                v[i][j] = true;
                v[j][i] = true;
                if(faramodif()){
                    nr++;
                    rasp[nr] = {i, j};
                }else{
                    v[i][j] = false;
                    v[j][i] = false;
                }
            }
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= nr; i++){
        fout << rasp[i].first << ' ' << rasp[i].second << '\n';
    }
    return 0;
}
