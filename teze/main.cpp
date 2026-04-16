#include <fstream>
using namespace std;
#define MOD 1000000007LL
ifstream fin("teze.in");
ofstream fout("teze.out");

typedef __int128 lll;
typedef long long ll;

ll n,m,p,k,q;
ll d[1004];

signed main(){
    fin >> n >> m >> p >> k;
    ll tcurent_in;
    fin >> tcurent_in >> q;
    for(int i = 0; i < q; i++) fin >> d[i];

    lll tcurent = tcurent_in;
    lll t1 = tcurent;
    lll timpcol = (m%MOD)*(p%MOD)%MOD;
    lll timpnucol = (n%MOD)*(m%MOD)%MOD*((p%MOD+k%MOD+t1%MOD)%MOD)%MOD;
    lll sumdif = 0;
    lll ttrecut = tcurent;

    for(ll i = 1; i <= n; i++){
        if(i > 1) tcurent = ttrecut + d[(i-1)%q];
        timpcol = (timpcol + (m%MOD)*((k%MOD+tcurent%MOD)%MOD))%MOD;
        sumdif += (tcurent - t1);
        ttrecut = tcurent;
    }

    lll lim = (lll)(n-1)*p;
    if(sumdif <= lim)
        fout << (ll)timpcol;
    else
        fout << (ll)timpnucol;

    return 0;
}
