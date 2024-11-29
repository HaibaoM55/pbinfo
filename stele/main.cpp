#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("stele.in");
ofstream fout("stele.out");
int c, n;
int x[30];
typedef int NrMare[1010];
NrMare s;
char k[425];
void Adunare(NrMare x,NrMare y)
{
    int i,t=0;
    if(x[0]<y[0]){
        x[0]=y[0];
    }
    for(i=1;i<=x[0];i++,t/=10){
        t=x[i]+t;
        if(i <= y[0]){
            t = t+y[i];
        }
        x[i]=t%10;
    }
    if(t)
        x[++x[0]]=t;
}
void AtribMic(NrMare x, long long n)
{
  x[0]=0;
  if(n==0)
    x[(x[0]=1)]=0;
  else
    for(;n;n/=10)
      x[++x[0]]=n%10;
}
void ProdusMic(NrMare x, long long n)
{
  long long i,t=0;
  for(i=1;i<=x[0];i++,t/=10)
  {
    t+=x[i]*n;
    x[i]=t%10;
  }
  for(;t;t/=10)
    x[++x[0]]=t%10;
}
int main()
{
    fin >> c;
    x[0] = 1;
    for(int i = 1; i <= 25; i++){
        x[i] =x[i-1]*2;
    }
    if(c == 1){
        fin >> n;
        char p[1001];
        int nr = 0;
        while(n > 0){
            for(int i = 25; i >= 0; i--){
                if(n >= x[i]){
                    nr++;
                    p[nr] = i+'a';
                    n = n-x[i];
                    break;
                }
            }
        }
        for(int i = nr; i >= 1; i--){
            fout << p[i];
        }
    }else{
        fin >> n;
        for(int i = 1; i<= n; i++){
            fin >> k;
            int l = strlen(k);
            for(int j = 0; j < l; j++){
                long long mk = 0;
                while('0' <= k[j] && k[j] <= '9'){
                    mk = mk*10+k[j]-'0';
                    j++;
                }
                if(mk == 0){
                    mk = 1;
                }
                NrMare y;
                AtribMic(y, x[k[j]-'a']);
                ProdusMic(y, mk);
                Adunare(s, y);
            }
        }
        for(int i = s[0]; i >= 1; i--){
            fout << s[i];
        }
    }
    return 0;
}
