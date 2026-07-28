#include <iostream>
using namespace std;
int n;
typedef int NrMare[100001];
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
    rasp[0] = 1;
    rasp[1] = 1;
    cin >> n;
    int r = n*(n-1);
    r = r/2;
    for(int i = 1; i <= r; i++){
        ProdusMic(rasp, 3);
    }
    for(int i = rasp[0]; i >= 1; i--){
        cout << rasp[i];
    }
    return 0;
}
