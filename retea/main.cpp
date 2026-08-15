#include <fstream>
#include <vector>
using namespace std;
ifstream fin("retea.in");
ofstream fout("retea.out");
int n, m;
pair<int, int> p[10004];
bool v[104][104], viz[104];
vector<int> cc[104];
bool leg[104][104], legi[104][104];
void visit(int k, int j){
    viz[k] = true;
    cc[j].push_back(k);
    for(int i = 1; i <= n; i++){
        if(v[k][i] && !viz[i]){
            viz[i] = true;
            visit(i, j);
        }
    }
}
int nrcomp(){
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            rasp++;
            visit(i, rasp);
        }
    }
    return rasp;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> p[i].first >> p[i].second;
        v[p[i].first][p[i].second] = true;
        v[p[i].second][p[i].first] = true;
    }
    int nr = nrcomp();
    for(int z = 1; z <= nr; z++){
        int l = cc[z].size();
        for(int j = 0; j < l; j++){
            for(int k = 0; k < l; k++){
                legi[cc[i][j]][cc[j][i]] = true;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        v[p[i].first][p[i].second] = false;
        v[p[i].second][p[i].first] = false;
        nr = nrcomp();
        int nr = nrcomp();
        for(int z = 1; z <= nr; z++){
            int l = cc[z].size();
            for(int j = 0; j < l; j++){
                for(int k = 0; k < l; k++){
                    leg[cc[i][j]][cc[j][i]] = true;
                }
            }
        }
        for(int j = 1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                if(j == )
            }
        }
        v[p[i].first][p[i].second] = true;
        v[p[i].second][p[i].first] = true;
    }
    return 0;
}
