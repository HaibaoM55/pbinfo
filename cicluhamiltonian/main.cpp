#include <iostream>
using namespace std;
int n;
typedef int NrMare[10010];
void ProdusMic(NrMare x, int n)
//x <- x*n
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
NrMare x;
int main(){
    cin >> n;
    x[0] = 1;
    x[1] = 1;
    for(int i = 3; i < n; i++){
        ProdusMic(x, i);
    }
    for(int i = x[0]; i >= 1; i--){
        cout << x[i];
    }
    return 0;
}
