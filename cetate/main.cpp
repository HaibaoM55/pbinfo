#include <fstream>
using namespace std;
ifstream fin("cetate.in");
ofstream fout("cetate.out");
int n,K,W,dq[404],pr,ul,nr, k, c, m;
long long sp[404],smax,s[404][404], a[404][404];
#define DIM 10000
char buff[DIM];
int poz=0;
void citire_rapida(int &numar)
{
     numar = 0;
     char semn='+';
     while (buff[poz] < '0' || buff[poz] > '9')
     {
          semn = buff[poz];
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     if (semn == '-')
          numar = -numar;
}
long long best_sum(long long v[], int n, int &j1, int &j2){
    int W = k;
    int K = 1;
    long long s;
    sp[0]=0;
    for(int i=1;i<=K;i++){
        sp[i]=sp[i-1]+v[i];
    }
    ///sp[dq[pr]] este cea mai mica suma anterioara
    ///pentru primele K pozitii valoarea lui q va fi 0
    dq[1]=0;///retinem pozitia 0 in deque
    pr=1;
    ul=1;
    smax=sp[K];///avem primul candidat
    int smaxi = 1;
    int smaxj = 1;
    ///incepem prima etapa
    for(int i=K+1;i<=W;i++){
        sp[i]=sp[i-1]+v[i];
        s=sp[i-K];
        while(pr<=ul && s<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        s=sp[i]-sp[dq[pr]];
        if(s>smax){
            smax=s;
            smaxi = dq[pr]+1;
            smaxj = i;
        }
    }
    ///continuam cu etapa a doua
    for(int i=W+1;i<=n;i++){
        ///cin>>a;
        sp[i]=sp[i-1]+v[i];
        s=sp[i-K];
        while(pr<=ul && s<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        ///eliminam dq[pr] daca este expirat
        while(i-W>dq[pr]){
            pr++;
        }
        s=sp[i]-sp[dq[pr]];
        if(s>smax){
            smax=s;
            smaxi = dq[pr]+1;
            smaxj = i;
        }
    }
    j1 = smaxi;
    j2 = smaxj;
    return smax;
}
int main()
{
    fin >> c;
    fin >> n >> m >> k;
    long long vmax = 400LL*400LL*(-1000000000);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            s[i][j] = a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    if(c == 1){
        int vmaxi, vmaxj;
        int l = k;
        for(int i = 1; i <= n-l+1; i++){
            for(int j = 1; j <= m-l+1; j++){
                int is=i,js=j;
                int ij=i+l-1,jj=j+l-1;
                long long sma = s[ij][jj] - s[is-1][jj] - s[ij][js-1] + s[is-1][js-1];
                if(sma > vmax){
                    vmax = sma;
                    vmaxi = i;
                    vmaxj = j;
                }
            }
        }
        fout << vmax << '\n';
        fout << vmaxi << ' ' << vmaxj << ' ' << vmaxi+l-1 << ' ' << vmaxj+l-1;
    }else{
        int x1, y1, x2, y2;
        for(int i1 = 1; i1 <= n; i1++){
            long long v[404] = {0};
            for(int i2 = i1; i2 <= n && i2 <= i1+k-1; i2++){
                for(int j = 1; j <= m; j++){
                    v[j] += a[i2][j];
                }
                int vmaxi, vmaxj;
                long long sma = best_sum(v, m, vmaxi, vmaxj);
                if(sma > vmax){
                    vmax = sma;
                    x1 = i1;
                    x2 = i2;
                    y1 = vmaxi;
                    y2 = vmaxj;
                }else if(sma == vmax){
                    if(i1 == x1 && vmaxi == y1 && i2 == x2 && vmaxj < y2){
                        x1 = i1;
                        x2 = i2;
                        y1 = vmaxi;
                        y2 = vmaxj;
                    }
                    if(i1 == x1 && vmaxi == y1 && i2 < x2){
                        x1 = i1;
                        x2 = i2;
                        y1 = vmaxi;
                        y2 = vmaxj;
                    }
                    if(i1 == x1 && vmaxi < y1){
                        x1 = i1;
                        x2 = i2;
                        y1 = vmaxi;
                        y2 = vmaxj;
                    }
                    if(i1 < x1){
                        x1 = i1;
                        x2 = i2;
                        y1 = vmaxi;
                        y2 = vmaxj;
                    }
                }
            }
        }
        fout << vmax << '\n';
        fout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
    return 0;
}
