#include <iostream>
using namespace std;
int n;
int v[1004];
bool ciur[31629];
int nrp, prm[31628];
typedef int NrMare[1000004];

int bubu(int x){
    int p = 1;
    for(int i = 1; i <= nrp && prm[i] <= x; i++){
        if(x % prm[i] == 0){
            p = p*prm[i];
            while(x % prm[i] == 0){
                x = x/prm[i];
            }
        }
    }
    p = p*x;
    return p;
}
NrMare rasp;
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
int main(){
    cin >> n;
    for(int i = 2; i <= 31624; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 31624/i; j++){
                ciur[i*j] = true;
            }
        }
    }
    rasp[0] = 1;
    rasp[1] = 1;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        ProdusMic(rasp, bubu(v[i]));
    }
    for(int i = rasp[0]; i >= 1; i--){
        cout << rasp[i];
    }
    return 0;
}
