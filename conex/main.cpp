#include <fstream>
#include <vector>
using namespace std;
ifstream fin("conex.in");
ofstream fout("conex.out");
int n;
int x, y;
vector<int> v[104];
bool viz[104];
void bt(int i){
    viz[i] = true;
    int l = v[i].size();
    for(int j = 0; j < l; j++){
        if(!viz[v[i][j]]){
            viz[v[i][j]] = true;
            bt(v[i][j]);
        }
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bt(1);
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            fout << "NU";
            return 0;
        }
    }
    fout << "DA";
    return 0;
}
