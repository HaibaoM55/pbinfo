#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin("mod.in");
ofstream fout("mod.out");
int n, q;
int v[200004];
map<int, vector<int>> f;
int main(){
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        f[v[i]].push_back(i);
    }
    for(int i = 1; i <= q; i++){
        int tip;
        fin >> tip;
        if(tip == 1){
            int x, k;
            fin >> x >> k;
            for(auto y: f){
                int l = y.second.size();
                for(int j = 0; j < l && k > 0; j++){
                    k--;
                    f[y.first%k].push_back(y.second);
                }
                if(k == 0){
                    break;
                }
            }
            fout << '\n';
        }
    }
    return 0;
}
