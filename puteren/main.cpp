#include <iostream>
using namespace std;
typedef int NrMare[1000004];
NrMare p;
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
int x, n;
int main(){
    cin >> x >> n;
    p[0] = 1;
    p[1] = 1;
    for(int i = 1; i <= n; i++){
        ProdusMic(p, x);
    }
    for(int i = p[0]; i >= 1; i--){
        cout << p[i];
    }
    return 0;
}
