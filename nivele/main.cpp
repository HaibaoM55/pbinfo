#include <fstream>
#include <vector>
using namespace std;
ifstream fin("nivele.in");
ofstream fout("nivele.out");
int n, k, x;
int f[104];
vector<int> v[104];
void bt(int p){
    int l = v[p].size();
    for(int i = 0; i < l; i++){
        if(f[v[p][i]] == 0){
            f[v[p][i]] = f[p]+1;
            bt(v[p][i]);
        }
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    f[0] = 0;
    bt(0);
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> x;
        fout << f[x] << '\n';
    }
    return 0;
}
