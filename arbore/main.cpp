#include <fstream>
#include <vector>
using namespace std;
ifstream fin("arbore.in");
ofstream fout("arbore.out");
int n, k;
vector<int> v[104];
int t[104];
bool viz[104];
void bt(int i){
    int l = v[i].size();
    for(int j = 0; j < l; j++){
        if(!viz[v[i][j]]){
            viz[v[i][j]] = true;
            t[v[i][j]] = i;
            bt(v[i][j]);
        }
    }
}
int main(){
    fin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[k] = true;
    bt(k);
    for(int i = 1; i <= n; i++){
        fout << t[i] << ' ';
    }
    return 0;
}
