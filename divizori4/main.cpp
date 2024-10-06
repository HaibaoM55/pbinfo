#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;
ifstream fin("divizori4.in");
ofstream fout("divizori4.out");
int c, n;
int v[100004];
bitset <1000005> viz;
int prm[1000005];
int nrp = 0;
int div(int nr)
{
    int pr=1;
    int j=0,a=0;
    while(nr%2==0){
        nr/=2;
        a++;
    }
    pr*=(a+1);
    for(j=1;j<=nrp && (long long) prm[j]*prm[j]<=nr;j++)
    {
        if(nr%prm[j]!=0){
            continue;
        }else{
            a = 0;
            while(nr % prm[j] == 0)
            {
                nr = nr / prm[j];
                a++;
            }
            pr*=(a+1);
        }
    }
    if(nr > 1){
        pr*=2;
    }
    return pr;
}
int main()
{
    fin >> n >> c;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int p;
    fin >> p;
    int nrv = 0;
    for(int j = 1; j*j <= v[p]; j++){
        if(v[p] % j == 0){
            nrv++;
            if(j*j < v[p]){
                nrv++;
            }
        }
    }
    if(c == 1){
        fout << nrv;
    }else{
        for(int i=2;i<1000005;++i)
        {
            if(viz[i]==0)
            {
                nrp++;
                prm[nrp] = i;
                for(int j=i+i;j<1000005;j+=i){
                    viz[j]=1;
                }
            }
        }
        sort(v+1, v+n+1);
        for(int i = n; i >= 1; i--){
            if(div(v[i]) == nrv){
                fout << v[i] << " ";
            }
        }
    }
    return 0;
}
