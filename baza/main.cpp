#include <fstream>
#include <string>
using namespace std;
ifstream fin("baza.in");
ofstream fout("baza.out");
string s;
typedef int NrMare[104];
void AtribMare(NrMare Dest, NrMare Sursa){
  int i;
  for(i=0;i<=Sursa[0];i++)
    Dest[i]=Sursa[i];
}
void ProdusMic(NrMare x, int n){
  int i,t=0;
  for(i=1;i<=x[0];i++,t/=10)
  {
    t+=x[i]*n;
    x[i]=t%10;
  }
  for(;t;t/=10)
    x[++x[0]]=t%10;
}
void Adunare(NrMare x,NrMare y)
// x = x + y
{
  int i,t=0;
  if(x[0]<y[0])
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10)
  {
    t=x[i]+y[i]+t;
    x[i]=t%10;
    // echivalent x[i]=(t+=x[i]+y[i])%10
  }
  if(t)
    x[++x[0]]=t;
}
NrMare p, x, sma;
int main(){
    fin >> s;
    int l = s.size();
    p[0] = 1;
    p[1] = 1;
    for(int i = l-1; i >= 0; i--){
        AtribMare(x, p);
        ProdusMic(x, s[i]-'a');
        if(s[i] == 'a'){
            x[0] = 0;
        }
        Adunare(sma, x);
        ProdusMic(p, 26);
    }
    for(int i = sma[0]; i >= 1; i--){
        fout << sma[i];
    }
    return 0;
}
