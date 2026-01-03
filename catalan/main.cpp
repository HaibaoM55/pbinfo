#include <iostream>
using namespace std;
typedef int NrMare[1000004];
NrMare v;
int n;
int e[2004];
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
    for(int k = 2; k <= n; k++){
        int x = n+k;
        for(int j = 2; j*j <= x; j++){
            while(x % j == 0){
                e[j]++;
                x = x/j;
            }
        }
        if(x > 1){
            e[x]++;
        }
        x = k;
        for(int j = 2; j*j <= x; j++){
            while(x % j == 0){
                e[j]--;
                x = x/j;
            }
        }
        if(x > 1){
            e[x]--;
        }
    }
    v[0] = 1;
    v[1] = 1;
    for(int i = 2; i <= 2*n; i++){
        while(e[i]){
            ProdusMic(v, i);
            e[i]--;
        }
    }
    for(int i = v[0]; i >= 1; i--){
        cout << v[i];
    }
    return 0;
}
