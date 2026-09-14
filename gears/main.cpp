#include <fstream>
#include <vector>
using namespace std;
ifstream fin("gears.in");
ofstream fout("gears.out");
int n, m, x, y;
bool b[104], viz[104];
vector<int> v[104];
void visit(int k){
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            b[v[k][i]] = !b[k];
            visit(v[k][i]);
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i < n; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[m] = true;
    b[m] = true;
    visit(m);
    for(int i = 1; i <= n; i++){
        if(b[i]) fout << 'D';
        else fout << 'S';
    }
    return 0;
}
