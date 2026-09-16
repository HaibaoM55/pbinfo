#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ghiocel.in");
ofstream fout("ghiocel.out");
int n, m, g, x, y;
vector<int> v[104];
bool viz[104];
int b[104];
void visit(int pp){
    int k = pp;
    viz[k] = true;
    pair<int, int> coada[104];
    int st = 1, dr = 1;
    coada[1] = {k, 0};
    int final1 = 2e9;
    while(st <= dr){
        if(coada[st].second == final1) break;
        k = coada[st].first;
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = {v[k][i], coada[st].second+1};
                if(b[v[k][i]] == 1){
                    b[v[k][i]] = 2;
                    final1 = coada[dr].second;
                }
            }
        }
        st++;
    }
}
int main(){
    fin >> n >> m >> g;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        b[x] = 1;
    }
    visit(g);
    for(int i = 1; i <= n; i++){
        if(b[i] == 2){
            fout << i << ' ';
        }
    }
    return 0;
}
