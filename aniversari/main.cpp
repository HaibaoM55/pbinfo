#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct persoana{
    int an,luna,zi,poz;
}v[1002];
int maiTanar(persoana x, persoana y){
    if(x.an>y.an)return 1;
    if(x.an==y.an && x.luna>y.luna)return 1;
    if(x.an==y.an && x.luna==y.luna && x.zi>y.zi)return 1;
    if(x.an==y.an && x.luna==y.luna && x.zi==y.zi && x.poz<y.poz)return 1;
    return 0;
}
int maiBatran(persoana x, persoana y){
    if(x.an<y.an)return 1;
    if(x.an==y.an && x.luna<y.luna)return 1;
    if(x.an==y.an && x.luna==y.luna && x.zi<y.zi)return 1;
    if(x.an==y.an && x.luna==y.luna && x.zi==y.zi && x.poz<y.poz)return 1;
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].an>>v[i].luna>>v[i].zi;
        v[i].poz=i;
    }
    sort(v+1,v+n+1,maiTanar);
    cout<<v[1].poz<<" ";
    sort(v+1,v+n+1,maiBatran);
    cout<<v[1].poz;
    return 0;
}
