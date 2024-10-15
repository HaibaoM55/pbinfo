#include <fstream>
#include <algorithm>
using namespace std;
ifstream  fin("sumo.in");
ofstream fout("sumo.out");
int n,nv;
int p[100002], q[100002], v[200002], sv[200002];
long long f[12] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
long long suma(int x){
    int p10 = 10;
    int nrc = 1;
    long long s = 0;
    while(p10 < x){
        //noi acum vom analiza de la p10/10,..., p10-1;
        s += (f[nrc]-f[nrc-1])*45;
        nrc++;
        p10 = p10*10;
    }
    int p = p10/10;
    int i = 1;
    while(i*p10 < x){
        s += (f[nrc-1]-f[nrc-2])*i;
        i++;
    }
    return s+suma(x-i*p10)+i*(x-i*p10);
}
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p[i] >> q[i];
        ///pastrez pozitiile de care voi avea nevoie
        v[++nv]=p[i]-1;
        v[++nv]=q[i];
    }
    ///sortez crescator
    sort(v,v+1+nv);
    ///pastrez pozitiile distincte
    int k=0;
    for(int i=1;i<=nv;i++){
        if(v[k]<v[i])v[++k]=v[i];
    }
    nv=k;
    ///acum fac o singura parcurgere a cifrelor numerelor si interclasez cu parcurgerea pozitiilor din v[]
    ///pastrand suma curenta calculata pentru pozitia v[i] in sv[i]
    int i=1;
    int j = 1;
    long long s = 0;
    int nrc=0;
    while(i<=nv){
        int pi, qi;
        int stp, stq;
        for(int j = 1; j <= 9; j++){
            dr = 9*j*z+st-1;
            if(st <= p && p <= dr){
                pi = j;
                stp = st;
            }
            if(st <= q && q <= dr){
                qi = j;
                stq = st;
                break;
            }
            st = dr+1;
            z = z*10;
        }
        int x=j,nc=0,cif[12];
        do{
            cif[++nc]=x%10;
            x/=10;
        }while(x);
        while(nc){
            s=s+cif[nc];
            nrc++;
            if(nrc==v[i]){
                sv[i]=s;
                i++;
            }
            nc--;
        }
        j++;
    }
    for(int i=1;i<=n;i++){
        ///caut binar p[i]-1 in v[] si q[i] in v[]
        int p1=0,p2=nv,pmij,pp=0,qq=0;
        while(p1<=p2){
            pmij=(p1+p2)/2;
            if(v[pmij]==p[i]-1){
                pp=pmij;
                break;
            }
            if(v[pmij]<p[i]-1)p1=pmij+1;
            else p2=pmij-1;
        }
        p1=pp;p2=nv;
        while(p1<=p2){
            pmij=(p1+p2)/2;
            if(v[pmij]==q[i]){
                qq=pmij;
                break;
            }
            if(v[pmij]<q[i])p1=pmij+1;
            else p2=pmij-1;
        }
        fout<<sv[qq]-sv[pp]<<"\n";
    }

    return 0;
}
