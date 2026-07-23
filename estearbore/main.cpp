#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream fin("estearbore.in");
ofstream fout("estearbore.out");
int n;
int x, y;
vector<int> v[104];
set<pair<int,int>> muchii;
bool viz[104];
void viziteaza(int k){
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            viziteaza(v[k][i]);
        }
    }
}
int main(){
    fin >> n;
    int nr = 0;
    while(fin >> x >> y){
        int a = min(x, y), b = max(x, y);
        if(muchii.find({a, b}) == muchii.end()){
            muchii.insert({a, b});
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    int l = muchii.size();
    if(l != n-1){
        fout << "NU";
        return 0;
    }
    for(int j = 1; j <= n; j++){
        viziteaza(j);
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(!viz[i]){
                ok = false;
            }
            viz[i] = false;
        }
        if(ok){
            fout << "DA";
            return 0;
        }
    }
    fout << "NU";
    return 0;
}
