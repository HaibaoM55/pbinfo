#include <iostream>
using namespace std;
typedef int NrMare[1000004];
int k, n;
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
void Divide(NrMare x, int n){
  int i,r=0;
  for(i=x[0];i>0;i--)
  {
    r=10*r+x[i];
    x[i]=r/n;
    r%=n;
  }
  for(;x[x[0]]==0 && x[0]>1;) 
    x[0]--;
}
int main(){
	cin >> n >> k;
    rasp[0] = 1;
    rasp[1] = 1;
    for(int i = 1; i <= n; i++){
    	ProdusMic(rasp, i);
    }
    for(int i = 1; i <= k; i++){
    	Divide(rasp, i);
    }
	for(int i = 1; i <= n-k; i++){
    	Divide(rasp, i);
    }
    for(int i = rasp[0]; i >= 1; i--){
    	cout << rasp[i];
    }
}
