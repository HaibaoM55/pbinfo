#include <fstream>
#include <algorithm>
#include <set>
#define int long long
using namespace std;
ifstream fin("nuke.in");
ofstream fout("nuke.out");
int n, m, nrEv;
int rezultat[100004];
struct punct{
    int x, y;
}soldat[200004];
struct cerc{
    int cx, cy, r;
}bomba[100004];
struct eveniment{
    int x, tip, idx;
}ev[900004];
bool cmpEv(eveniment a, eveniment b){
    if(a.x < b.x) return true;
    if(a.x > b.x) return false;
    if(a.tip < b.tip) return true;
    return false;
}
signed main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> soldat[i].x >> soldat[i].y;
        nrEv++;
        ev[nrEv] = {soldat[i].x, 2, i};
    }
    for(int i = 1; i <= m; i++){
        fin >> bomba[i].cx >> bomba[i].cy >> bomba[i].r;
        nrEv++;
        ev[nrEv] = {bomba[i].cx - bomba[i].r, 1, i};
        nrEv++;
        ev[nrEv] = {bomba[i].cx + bomba[i].r, 3, i};
    }
    sort(ev + 1, ev + nrEv + 1, cmpEv);
    set<pair<int,int>> activ;
    for(int i = 1; i <= nrEv; i++){
        int idx = ev[i].idx;
        if(ev[i].tip == 1){
            activ.insert({bomba[idx].cy, idx});
        }else if(ev[i].tip == 3){
            activ.erase({bomba[idx].cy, idx});
        }else{
            auto it = activ.lower_bound({soldat[idx].y, 0});
            auto it2 = it;
            while(it2 != activ.end()){
                int b = it2->second;
                int dy = soldat[idx].y - bomba[b].cy;
                if(dy * dy > bomba[b].r * bomba[b].r) break;
                int dx = soldat[idx].x - bomba[b].cx;
                if(dx*dx + dy*dy <= bomba[b].r * bomba[b].r){
                    rezultat[b]++;
                    break;
                }
                it2++;
            }
            if(it != activ.begin()){
                it2 = it;
                it2--;
                while(true){
                    int b = it2->second;
                    int dy = soldat[idx].y - bomba[b].cy;
                    if(dy * dy > bomba[b].r * bomba[b].r) break;
                    int dx = soldat[idx].x - bomba[b].cx;
                    if(dx*dx + dy*dy <= bomba[b].r * bomba[b].r){
                        rezultat[b]++;
                        break;
                    }
                    if(it2 == activ.begin()) break;
                    it2--;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++){
        fout << rezultat[i] << '\n';
    }
    return 0;
}
