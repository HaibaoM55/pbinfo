#include <fstream>
#include <algorithm>
using namespace std;
ifstream  fin("op.in");
ofstream fout("op.out");
int t, n;
unsigned long long y;
unsigned long long nr=0;
struct numar{
    int n;
    unsigned long long l;
}v[100004];
int f[100004];
bool compara(numar a, numar b){
    if(a.n < b.n){
        return true;
    }
    return false;
}
unsigned long long cer1(unsigned long long y){
    unsigned long long nr = 0;
    for(int i = 1; i <= n; i++){
        int p1 = 1;
        int p2 = n;
        int p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            unsigned long long b = v[i].n*v[mij].l+v[mij].n;
            if(b <= y){
                p1 = mij+1;
            	p=mij;
            }else{
                p2 = mij-1;
            }
        }
        nr += p;
    }
    return nr;
}
unsigned long long cer2(unsigned long long y){
    unsigned long long nr = 0;
    for(int i = 1; i <= n; i++){
        int p1 = 1;
        int p2 = n;
        int p = 0;
        while(p1 <= p2){
            int mij = p1+(p2-p1)/2;
            unsigned long long b = v[i].n*v[mij].l+v[mij].n;
            if(b < y){
                p1 = mij+1;
            	p=mij;
            }else{
                p2 = mij-1;
            }
        }
        nr += p;
    }
    return nr;
}
unsigned long long cer22(unsigned long long y){
    unsigned long long c=v[n].n*v[n].l+v[n].n;
    unsigned long long d=c;
    for(int i = 1; i <= n; i++){
        int p1 = 1;
        int p2 = n;
        int p=0;
        while(p1 <= p2){
            int mij = p1+(p2-p1)/2;
            unsigned long long b = v[i].n*v[mij].l+v[mij].n;
            if(b >= y){
                p1 = mij+1;
                p=mij;
                d=b;
            }else{
                p2 = mij-1;
            }
        }
        if(p!=0 && d<c)c=d;
    }
    return c;
}
int main()
{
    fin >> t;
    fin >> n >> y;
    for(int i = 1; i <= n; i++){
        fin >> v[i].n;
        int x = v[i].n;
        v[i].l = 1;
        do{
            v[i].l = v[i].l*10;
            x = x/10;
        }while(x > 0);
    }
    sort(v+1, v+n+1, compara);
    if(t == 1){
        unsigned long long z = cer1(y);
        fout << z;
    }else{
        unsigned long long z1=v[1].n*v[1].l+v[1].n;
        unsigned long long z2=v[n].n*v[n].l+v[n].n;
        unsigned long long mij,z=z2;
        while(z1<=z2){
            mij=z1+(z2-z1)/2;
            unsigned long long a=cer2(mij);///a=numarul valorilor < mij
            if(a>=y){
                z=mij;///z, daca ar aparea in matrice ar sta pe pozitie >= y
                z2=mij-1;
            }
            else{
                z1=mij+1;
            }
        }
        if(z == z2){
            fout << z;
        }else{
            fout << z-1;
        }
    }
    return 0;
}
