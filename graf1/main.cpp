#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("graf1.in");
ofstream fout("graf1.out");
int n, m, a, b, x, y;
vector<int> v[7504];
pair<int, int> coada[7504], coada2[7504];
int pasi[7504];
bool rasp[7504];
bool viz[7504], viz2[7504], ok[7504];
int main(){
    fin >> n >> m >> a >> b;
    for(int i = 1; i <= m; i ++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int st = 1;
    int dr = 1;
    coada2[1] = {b, 0};
    viz2[b] = true;
    while(st <= dr){
        int k = coada2[st].first;
        pasi[k] = coada2[st].second;
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz2[v[k][i]]){
                viz2[v[k][i]] = true;
                dr++;
                coada2[dr] = {v[k][i], coada2[st].second+1};
            }
        }
        st++;
    }
    coada[1] = {a, 0};
    st = 1;
    dr = 1;
    rasp[a] = true;
    viz[a] = true;
    rasp[b] = true;
    while(st <= dr){
        if(st > 1 && coada[st-1].second != coada[st].second && coada[st].second != coada[st+1].second){
            rasp[coada[st].first] = true;
        }
        if(coada[st].first == b){
            break;
        }
        int k = coada[st].first;
        int l = v[k].size();
        //fout << k << ' ' << coada[st].second <<'\n';
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]] && pasi[v[k][i]]+coada[st].second+1 == pasi[a]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = {v[k][i], coada[st].second+1};
            }
        }
        st++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(rasp[i]){
            nr++;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(rasp[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
