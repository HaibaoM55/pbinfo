#include <fstream>
#include <random>
#include <map>
#include <set>
using namespace std;
ifstream fin("clasament.in");
ofstream fout("clasament.out");
#define int long long
#define MOD 1000000009
mt19937 rnd(23784878);
int n, m;
int putere[250005][2];
int scor[50005];
int a[200005], b[200005];
int slot_curent[50005];
map<pair<int,int>, int> pozitie_cheie;
int nr_sloturi;
struct Hash{
    int len, v[2];
};
Hash clearh = {0, {0, 0}};
Hash concat(Hash x, Hash y){
    Hash rez;
    rez.len = x.len+y.len;
    rez.v[0] = (x.v[0]+y.v[0]*putere[x.len][0])%MOD;
    rez.v[1] = (x.v[1]+y.v[1]*putere[x.len][1])%MOD;
    return rez;
}
bool compara(Hash x, Hash y){
    if(x.len != y.len){
        return x.len < y.len;
    }
    if(x.v[0] != y.v[0]){
        return x.v[0] < y.v[0];
    }
    return x.v[1] < y.v[1];
}
struct CmpHash{
    bool operator()(Hash x, Hash y) const{
        return compara(x, y);
    }
};
Hash aint[1000005];
void upd(int nod, int st, int dr, int poz, Hash val){
    if(st == dr){
        aint[nod] = val;
        return;
    }
    int mij = (st+dr)/2;
    if(poz <= mij){
        upd(nod*2, st, mij, poz, val);
    }else{
        upd(nod*2+1, mij+1, dr, poz, val);
    }
    aint[nod] = concat(aint[nod*2], aint[nod*2+1]);
}
Hash fr(int id){
    return {1, {id, id}};
}
void muta_concurent(int id, int slot_nou){
    upd(1, 1, nr_sloturi, slot_curent[id], clearh);
    upd(1, 1, nr_sloturi, slot_nou, fr(id));
    slot_curent[id] = slot_nou;
}
map<Hash, int, CmpHash> f;
signed main(){
    putere[0][0] = putere[0][1] = 1;
    putere[1][0] = 4+rnd()%MOD;
    putere[1][1] = 4+rnd()%MOD;
    for(int i = 2; i <= 250004; i++){
        putere[i][0] = (putere[i-1][0] * putere[1][0]) % MOD;
        putere[i][1] = (putere[i-1][1] * putere[1][1]) % MOD;
    }
    fin >> n >> m;
    set<pair<int,int>> chei;
    for(int i = 1; i <= n; i++){
        fin >> scor[i];
        chei.insert({-scor[i], 0});
    }
    for(int i = 1; i <= m; i++){
        fin >> a[i] >> b[i];
        chei.insert({-b[i], i});
    }
    nr_sloturi = 0;
    for(auto& cheie : chei){
        nr_sloturi++;
        pozitie_cheie[cheie] = nr_sloturi;
    }
    for(int i = 1; i <= n; i++){
        slot_curent[i] = pozitie_cheie[{-scor[i], 0}];
        upd(1, 1, nr_sloturi, slot_curent[i], fr(i));
    }
    f[aint[1]]++;
    for(int i = 1; i <= m; i++){
        int concurent = a[i];
        int scor_nou = b[i];
        int slot_nou = pozitie_cheie[{-scor_nou, i}];
        muta_concurent(concurent, slot_nou);
        scor[concurent] = scor_nou;
        fout << f[aint[1]] << '\n';
        f[aint[1]]++;
    }
    return 0;
}
