#include <fstream>
using namespace std;
ifstream fin("ksum2.in");
ofstream fout("ksum2.out");
int n,K,W,sp[100002],dq[100002],a,pr,ul,nr,smax;
int main(){
    fin>>n>>K>>W;
    sp[0]=0;
    for(int i=1;i<=K;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
    }
    ///sp[dq[pr]] este cea mai mica suma anterioara
    ///pentru primele K pozitii valoarea lui q va fi 0
    dq[1]=0;///retinem pozitia 0 in deque
    pr=1;
    ul=1;
    smax=sp[K];///avem primul candidat
    ///incepem prima etapa
    for(int i=K+1;i<=W;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
        while(pr<=ul && sp[i-K]<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        if(sp[i]-sp[dq[pr]]>smax){
            smax=sp[i]-sp[dq[pr]];
        }
    }
    ///continuam cu etapa a doua
    for(int i=W+1;i<=n;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
        while(pr<=ul && sp[i-K]<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        ///eliminam dq[pr] daca este expirat
        while(i-W>dq[pr]){
            pr++;
        }
        if(sp[i]-sp[dq[pr]]>smax){
            smax=sp[i]-sp[dq[pr]];
        }
    }
    fout<<smax;
    return 0;
}
/*
#include <fstream>
using namespace std;
ifstream  fin("ksum2.in");
ofstream fout("ksum2.out");
int n,K,W,a,sp[100002],hmin[100002],nh,smax;
void urcare(int p){
    while(p>=2 && sp[hmin[p]]<sp[hmin[p/2]]){
        swap(hmin[p],hmin[p/2]);
        p=p/2;
    }
}
void coborare(int p){
    while(p*2<=nh){
        int r=p*2;
        if(r+1<=nh && sp[hmin[r+1]]<sp[hmin[r]]){
            r=r+1;
        }
        if(sp[hmin[r]]<sp[hmin[p]]){
            swap(hmin[p],hmin[r]);
            p=r;
        }
        else{
            break;
        }
    }
}
int main(){
    fin>>n>>K>>W;
    sp[0]=0;
    for(int i=1;i<=K;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
    }
    smax=sp[K];
    hmin[1]=0; nh=1;
    ///incepem prima etapa
    for(int i=K+1;i<=W;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
        hmin[++nh]=i-K;
        urcare(nh);

        if(sp[i]-sp[hmin[1]]>smax){
            smax=sp[i]-sp[hmin[1]];
        }
    }
    ///continuam cu etapa a doua
    for(int i=W+1;i<=n;i++){
        fin>>a;
        sp[i]=sp[i-1]+a;
        while(nh>0 && hmin[1]<i-W){
            hmin[1]=hmin[nh--];
            coborare(1);
        }
        hmin[++nh]=i-K;
        urcare(nh);
        if(sp[i]-sp[hmin[1]]>smax){
            smax=sp[i]-sp[hmin[1]];
        }
    }
    fout<<smax;
    return 0;
}
*/
