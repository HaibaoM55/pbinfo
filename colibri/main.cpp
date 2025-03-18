#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("colibri.in");
ofstream fout("colibri.out");
bool f[100003];
int n, a;
double b,c;
bool ok;
double Max;
struct nr{
    double n;
    int i;
}v[100003];
bool compara(nr a,nr b){
    return a.n < b.n;
}
int main()
{
    int poz=0, z=-1, p=0;
    fin>>n;
    if (n==1)
    {
        fout<<1;
        return 0;
    }
    int ex1 = 0;
    for(int i=1; i<=n; i++){
        fin>>a>>b>>c;
        if(b==0){
            z=i;
        }else if(a % 2 == 0){
            if (b>=c){
                f[i]=1;
                ok=1;
            }else{
                if ((float)b/c>Max){
                    Max=b/c;
                    poz=i;
                }
            }
            ex1=1;
        }
        else{
            p++;
            v[p].n=(-1.0)*(b/c);
            v[p].i=i;
        }
    }
    sort(v+1,v+p+1,compara);
    for (int i=1;i<p;i+=2){
        if (v[i].n*v[i+1].n>=1){
            ok=true;
            f[v[i].i]=1;
            f[v[i+1].i]=1;
        }
        else{
            break;
        }
    }
    if(ok){
        for (int i=1; i<=n; i++){
            fout<<f[i];
        }
        return 0;
    }else if(z!=-1 && ex1==0){
        if(v[1].n*v[2].n>0){
            f[v[1].i]=1;
            f[v[2].i]=1;
        }
        else{
            f[z]=1;
        }
        for(int i=1; i<=n; i++){
            fout<<f[i];
        }
        return 0;
    }else{
        if (v[1].n*v[2].n>Max){
            f[v[1].i]=1;
            f[v[2].i]=1;
        }
        else{
            f[poz]=1;
        }
        for(int i=1; i<=n; i++){
            fout<<f[i];
        }
        return 0;
    }
}
