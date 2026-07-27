#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ccmax.in");
ofstream fout("ccmax.out");
int n, x, y;
bool e[104][104];
vector<int> v[104], cc[104];
bool viz[104];
int p = 0;
int vmax = 0, vmaxnr = 0;
void visit(int k){
    int l = v[k].size();
    viz[k] = true;
    cc[p].push_back(k);
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        if(!e[min(x, y)][max(x, y)]){
            e[min(x,y)][max(x,y)] = true;
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            p++;
            visit(i);
            int l = cc[p].size();
            if(l > vmax){
                vmax = l;
                vmaxnr = 1;
            }else if(l == vmax){
                vmaxnr++;
            }
        }
    }
    fout << vmax << ' ' << vmaxnr;
    return 0;
}
