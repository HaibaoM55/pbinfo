#include <iostream>
using namespace std;
typedef long long NrMare[1000007];
NrMare rasp;
void ProdusMic(NrMare x, long long n){
  long long i,t=0;
  for(i=1;i<=x[0];i++,t/=10){
    t+=x[i]*n;
    x[i]=t%10;
  }
  for(;t;t/=10)
    x[++x[0]]=t%10;
}
long long sumcif = 0;
char x;
int main(){
    while(cin >> x){
        if(!('0' <= x && x <= '9')){
            break;
        }
        sumcif += (x-'0');
        rasp[0]++;
        rasp[rasp[0]] = 1;
    }
    ProdusMic(rasp, sumcif);
    for(int i = rasp[0]; i >= 1; i--){
        cout << rasp[i];
    }
    return 0;
}
