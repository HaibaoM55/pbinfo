#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define MOD 666013
ifstream fin("gasti.in");
ofstream fout("gasti.out");
int n, m, x, y;
int nrc = 0;
vector<int> v[100004], cc[100004];
bool viz[100004];
void visit(int k){
    queue<int> coada;
    coada.push(k);
    viz[k]= true;
    while(!coada.empty()){
        int kk = coada.front();
        coada.pop();
        cc[nrc].push_back(kk);
        int l = v[kk].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[kk][i]]){
                viz[v[kk][i]] = true;
                coada.push(v[kk][i]);
            }
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            nrc++;
            visit(i);
        }
    }
    int vmax = 0, vmaxnr1 = 0, vmaxi;
    for(int i = 1; i <= nrc; i++){
        if(cc[i].size() > vmax){
            vmax = cc[i].size();
            vmaxi = i;
            vmaxnr1=1;
        }else if(cc[i].size() == vmax){
            vmaxnr1++;
        }
    }
    long long rasp = 0;
    if(vmaxnr1 == 1){
        int vmax2 = 0, vmaxnr = 0;
        for(int i = 1; i <= nrc; i++){
            if(i == vmaxi){
                continue;
            }
            if(cc[i].size() > vmax2){
                vmax2 = cc[i].size();
                vmaxnr = 1;
            }else if(cc[i].size() == vmax2){
                vmaxnr++;
            }
        }
        for(int i = 1; i <= vmaxnr; i++){
            rasp += 1LL*vmax*vmax2;
            rasp = rasp%MOD;
        }
    }else{
        rasp = 1LL*vmaxnr1*(vmaxnr1-1)/2;
        rasp = rasp%MOD;
        rasp = (((1LL*vmax*vmax)%MOD)*rasp)%MOD;
    }

    fout << nrc << ' ' << rasp;
    return 0;
}
