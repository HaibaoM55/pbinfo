#include <fstream>
#include <vector>
using namespace std;
ifstream fin("lantminim.in");
ofstream fout("lantminim.out");
int n, p, q;
int x, y;
vector<int> v[104];
bool viz[104];
int rasp[104];
pair<int, int> coada[104];
void rezolva(){
    int st = 1, dr = 1;
    coada[1] = {p, -1};
    while(st <= dr){
        if(coada[st].first == q){
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
    int pasi = 0;
    p = st;
    while(p != -1){
        pasi++;
        rasp[pasi] = coada[p].first;
        p = coada[p].second;
    }
    fout << pasi << '\n';
    for(int i = pasi; i >= 1; i--){
        fout << rasp[i] << ' ';
    }
}
int main(){
    fin >> n >> p >> q;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rezolva();
    return 0;
}
