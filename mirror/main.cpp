#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("mirror.in");
ofstream fout("mirror.out");
int c;
int n, k, x;
int poz =0;
int a[100004];
bool b[3100004];
int p[34];
int operatie(int x){
    if (x == 0)return x;
    for(int i=1; i<=k; i++){
        int val=0;
        int bitmax=log2(x);
        for(int j=0; j<=bitmax; j++){
            if(((1<<j)&x)==0) val+=(1<<j);
        }
        x=val;
        if(x==0) return x;
    }
    return x;
}
int main()
{
    fin >> c;
    fin >> n >> k;
    if(c == 1){
        for(int i = 1; i <= n; i++){
            fin >> x;
            int z = 0;
            int v[34];
            while(x > 0){
                z++;
                v[z] = x%2;
                x = x/2;
            }
            int p = z;
            for(int j = 1; j <= z/2; j++){
                swap(v[j], v[p]);
                p--;
            }
            for(int j = 1; j <= z; j++){
                poz++;
                b[poz] = v[j];
            }
        }
        int p = 1 << (k-1), nr = 0;
        for(int i = 1; i <= poz; i++){
            nr += b[i]*p;
            p = p/2;
            if(i % k == 0){
                fout << nr << ' ' ;
                nr = 0;
                p = 1 << (k-1);
            }
        }
    }else{
        for(int i = 1; i <= n; i++){
            fin >> a[i];
            a[i] = operatie(a[i]);
        }
        for(int i=0;i<=32;i++){
            p[i]=0;
        }
        int vmax=0, vmaxj;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=32; j++){
                if(((1<<j)&a[i])!=0){
                    p[j]++;
                }else{
                    if(p[j]>vmax){
                        vmax=p[j];
                        p[j]=0;
                        vmaxj=i-1;
                    }
                    p[j]=0;
                }
            }
        }
        fout << vmax << '\n';
        fout << vmaxj-vmax+1 << ' ' << vmaxj;
    }
    return 0;
}
