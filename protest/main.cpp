#include <fstream>
#include <vector>
using namespace std;
ifstream fin("protest.in");
ofstream fout("protest.out");
int n, m, x, y;
vector<int> v[50004];
bool b[50004], viz[50004];
int nr = -1;
void visit(int k){
    int l = v[k].size();
    nr++;
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]] && !b[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        b[x] = true;
    }
    while(fin >> x >> y){
        v[x].push_back(y);
    }
    visit(1);
    fout << nr;
    return 0;
}
