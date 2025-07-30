#include <iostream>
using namespace std;
int n;
typedef int NrMare[100004];
NrMare suma;
void adunare(NrMare x,NrMare y){
  int i,t=0;
  if(x[0]<y[0])
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10){
    t=x[i]+y[i]+t;
    x[i]=t%10;
    // echivalent x[i]=(t+=x[i]+y[i])%10
  }
  if(t)
    x[++x[0]]=t;
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
void AtribMic(NrMare x, int n){
  x[0]=0;
  if(n==0)
    x[(x[0]=1)]=0;
  else
    for(;n;n/=10)
      x[++x[0]]=n%10;
}
int main(){
    cin >> n;
    AtribMic(suma, 1);
    for(int i = 1; i <= n/4; i++){
        ProdusMic(suma, 16);
    }
    if(n%4==1){
        ProdusMic(suma, 2);
    }else if(n % 4 == 2){
        ProdusMic(suma, 4);
    }else if(n % 4 == 3){
        ProdusMic(suma, 8);
    }
    long long nrcif = 0;
    for(int i = suma[0]; i >= 1; i--){
        nrcif = nrcif+suma[i];
    }
    cout << nrcif;
    return 0;
}
