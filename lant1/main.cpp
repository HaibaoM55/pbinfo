#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("lant1.in");
ofstream fout("lant1.out");
int n,p,q,r;
int x, y;
vector<int> v[104], rasp;
bool viz[104];
pair<int, int> coada[104];
void drum(int a, int b){
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    int st = 1, dr = 1;
    coada[1] = {a, -1};
    viz[a] = true;
    while(st <= dr){
        if(coada[st].first == b){
            break;
        }
        int l = v[coada[st].first].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[coada[st].first][i]]){
                viz[v[coada[st].first][i]] = true;
                dr++;
                coada[dr] = {v[coada[st].first][i], st};
            }
        }
        st++;
    }
    int r = st;
    rasp.clear();
    while(r != -1){
        rasp.push_back(coada[r].first);
        r = coada[r].second;
    }
    reverse(rasp.begin(), rasp.end());
}
int main(){
    fin >> n >> p >> q >> r;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int raspl = 0;
    drum(p, r);
    raspl += rasp.size();
    drum(r, q);
    raspl += rasp.size()-1;
    fout << raspl << '\n';
    drum(p, r);
    int l = rasp.size();
    for(int i = 0; i < l; i++){
        fout << rasp[i] << ' ';
    }
    drum(r, q);
    l = rasp.size();
    for(int i = 1; i < l; i++){
        fout << rasp[i] << ' ';
    }
    return 0;
}
