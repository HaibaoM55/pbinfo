#include <fstream>
#include <vector>
using namespace std;
ifstream fin("bipartit2.in");
ofstream fout("bipartit2.out");
int n, m, x, y;
vector<int> v[104];
int tip[104];
bool ok = true;
int opus(int z){
    if(z == 1){
        return 2;
    }
    return 1;
}
void visit(int k){
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(tip[v[k][i]] == 0){
            tip[v[k][i]] = opus(tip[k]);
            visit(v[k][i]);
        }else if(tip[v[k][i]] == tip[k]){
            ok = false;
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    tip[1] = 1;
    visit(1);


    if(ok){
        fout << "DA\n";
        for(int i = 1; i <= n; i++){
            if(tip[i] == 1){
                fout << i << ' ';
            }
        }
        fout << '\n';
        for(int i = 1; i <= n; i++){
            if(tip[i] == 2){
                fout << i << ' ';
            }
        }
    }else{
        fout << "NU";
    }
    return 0;
}
