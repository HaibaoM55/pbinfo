#include <fstream>
using namespace std;
ifstream fin("numar3.in");
ofstream fout("numar3.out");
int ni, nd, x;
typedef int NrMare[5010];
int p2, p5;
NrMare v;
NrMare sixseven; // tuff
void afiseaza(NrMare x){
    for(int i = x[0]; i >= 1; i--){
        fout << x[i];
    }
}
void produs(NrMare x, int n){
  int i,t=0;
  for(i=1;i<=x[0];i++,t/=10)
  {
    t+=x[i]*n;
    x[i]=t%10;
  }
  for(;t;t/=10)
    x[++x[0]]=t%10;
}
int impartire(NrMare x, int n){
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
int main(){
    fin >> ni >> nd;
    bool poateincepe = false;
    int z = 0;
    for(int i = 1; i <= ni; i++){
        fin >> x;
        if(x != 0){
            poateincepe = true;
        }
        if(poateincepe){
            z++;
            v[z] = x;
        }
    }
    for(int i = 1; i <= nd; i++){
        fin >> x;
        z++;
        v[z] = x;
    }
    v[0] = z;
    for(int i = 1; i <= z; i++){
        swap(v[i], v[z]);
        z--;
    }
    p2 = nd;
    p5 = nd;
    while(p2 > 0 && v[1] % 2 == 0){
        impartire(v, 2);
        p2--;
    }
    while(p5 > 0 && v[1] % 5 == 0){
        impartire(v, 5);
        p5--;
    }
    sixseven[0] = 1;
    sixseven[1] = 1;
    for(int i = 1; i <= p2; i++){
        produs(sixseven, 2);
    }
    for(int i = 1; i <= p5; i++){
        produs(sixseven, 5);
    }
    fout << v[0] << '\n';
    afiseaza(v);
    fout << '\n';
    fout << sixseven[0] << '\n';
    afiseaza(sixseven);
    return 0;
}
