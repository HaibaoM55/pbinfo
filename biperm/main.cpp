#include <fstream>
#include <vector>
#include <bitset>
using namespace std;
ifstream fin("biperm.in");
ofstream fout("biperm.out");
int n, nr = 0;
int a[10004], b[10004];
int oa[10004];
int fa[10004], fb[10004];
bool viz[10004];
vector<int> v[10004];
bool bol[10004][10004];
bitset<10004> exs[10004],exs2[10004];
pair<int, int> rasp[10004];
void visit(int k, int prev){
    if(prev != -1){
        bol[prev][k] = true;
    }
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i], k);
        }
    }
}
bool avoid[10004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        oa[i] = a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
        if(exs[min(a[i], b[i])][max(a[i], b[i])] == true){
            exs2[min(a[i], b[i])][max(a[i], b[i])] = true;
        }
        exs[min(a[i], b[i])][max(a[i], b[i])] = true;
        if(a[i] == b[i]){
            avoid[a[i]] = true;
        }
        v[b[i]].push_back(a[i]);
        v[a[i]].push_back(b[i]);
    }
    long long p = 1;
    for(int i = 1; i <= n; i++){
        if(avoid[i]){
            viz[i] = true;
            continue;
        }
        if(!viz[i]){
            visit(i, -1);
            p = p*2;
        }
    }
    for(int i = 1; i <= n; i++){
        if(exs2[min(a[i], b[i])][max(a[i], b[i])]){
            rasp[i] = {a[i], b[i]};
            exs[min(a[i], b[i])][max(a[i], b[i])] = false;
            bol[a[i]][b[i]] = false;
            bol[b[i]][a[i]] = true;
            continue;
        }
        if(bol[a[i]][b[i]]){
            rasp[i] = {a[i], b[i]};
        }else if(!bol[a[i]][b[i]]){
            rasp[i] = {b[i], a[i]};
        }
    }
    for(int i = 1; i <= n; i++){
        fa[i] = 0;
        fb[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        a[i] = rasp[i].first;
        b[i] = rasp[i].second;
        fa[a[i]]++;
        fb[b[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(fa[a[i]] == 2 && fb[b[i]] == 2){
            swap(a[i], b[i]);
            fa[a[i]]--;
            fb[a[i]]++;
            fa[b[i]]++;
            fb[b[i]]--;
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(oa[i] != a[i]){
            nr++;
        }
    }
    fout << p << ' ' << nr << '\n';
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' ';
    }
    fout << '\n';
    for(int i = 1; i <= n; i++){
        fout << b[i] << ' ';
    }
    return 0;
}
