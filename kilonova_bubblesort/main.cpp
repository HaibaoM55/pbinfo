#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("bubblesort.in");
ofstream fout("bubblesort.out");
#define int long long
int n, m;
typedef int NrMare[1000];
char s[1000];
bool f[304];
NrMare x;
NrMare x1, x2;
NrMare dif;
int y1[304], y2[304];
void ProdusMic(NrMare x, int n)
{
  int i,t=0;
  for(i=1;i<=x[0];i++,t/=10)
  {
    t+=x[i]*n;
    x[i]=t%10;
  }
  for(;t;t/=10)
    x[++x[0]]=t%10;
}
void Scadere(NrMare x, NrMare y)
{
  int i,j;
  for (i = 1; i <= x[0]; i++)
  {
    int yi = (i <= y[0]) ? y[i] : 0;
    if(x[i] >= yi)
      x[i] -= yi;
    else
    {
      j=i+1;
      while(x[j]==0)
        x[j++]=9;
      x[j]--;
      x[i]=10+x[i]-yi;
    }
  }
  for (; x[0] > 1 && !x[x[0]]; x[0]--);
}
void AtribMare(NrMare Dest, NrMare Sursa)
{
  int i;
  for(i=0;i<=Sursa[0];i++)
    Dest[i]=Sursa[i];
}
int Divide(NrMare x, int n)
{
  int i,r=0;
  for(i=x[0];i>0;i--)
  {
    r=10*r+x[i];
    x[i]=r/n;
    r%=n;
  }
  for(;x[x[0]]==0 && x[0]>1;)
    x[0]--;
  return r;
}
int Compara(NrMare x, NrMare y)
{
  while(x[0]>1 && x[x[0]]==0)
    x[0]--;
  while(y[0]>1 && y[y[0]]==0)
    y[0]--;
  if(x[0]!=y[0])
    return (x[0]<y[0]?-1:1);
  int i=x[0];
  while(x[i]==y[i] && i>0)
    i--;
  if(i==0)
    return 0;
  if(x[i]<y[i])
    return -1;
  return 1;
}
signed main(){
    fin >> n >> m >> s;
    int l = strlen(s);
    x[0] = l;
    for(int i = 0; i < l; i++){
        x[x[0]-i] = s[i]-'0';
    }
    x1[0] = 1;
    x1[1] = 1;
    x2[0] = 1;
    x2[1] = 1;
    for(int i = 1; i <= n; i++){
        if(i <= n-m+1){
            y1[i] = m;
        }else{
            y1[i] = y1[i-1]-1;
        }
        ProdusMic(x1, y1[i]);

        if(i <= n-m+2){
            y2[i] = m-1;
        }else{
            y2[i] = y2[i-1]-1;
        }
        ProdusMic(x2, y2[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!f[j]){
                NrMare tmp1, tmp2;
                AtribMare(tmp1, x1);
                AtribMare(tmp2, x2);
                if(y1[j]) Divide(tmp1, y1[j]);
                if(y2[j]) Divide(tmp2, y2[j]);
                AtribMare(dif, tmp1);
                Scadere(dif, tmp2);
                if(Compara(dif, x) != -1){
                    fout << j << ' ';
                    f[j] = true;
                    AtribMare(x1, tmp1);
                    AtribMare(x2, tmp2);
                    break;
                }else{
                    Scadere(x, dif);
                    y1[j]--;
                    y2[j]--;
                    AtribMare(x1, tmp1);
                    AtribMare(x2, tmp2);
                    if(y1[j]){
                        ProdusMic(x1, y1[j]);
                    }else{
                        x1[0]=1; x1[1]=0;
                    }
                    if(y2[j]){
                        ProdusMic(x2, y2[j]);
                    }else{
                        x2[0]=1; x2[1]=0;
                    }
                }
            }
        }
    }

    return 0;
}
