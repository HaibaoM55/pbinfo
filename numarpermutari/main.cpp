#include <iostream>
using namespace std;
int n;
typedef int NrMare[10004];
NrMare nr;
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
    nr[0] = 1;
    nr[1] = 1;
    for(int i = 1; i <= n; i++){
        ProdusMic(nr, i);
    }
    for(int i = nr[0]; i >= 1; i--){
        cout << nr[i];
    }
    return 0;
}
