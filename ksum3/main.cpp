#include <iostream>
using namespace std;
int n,K,W,dq[1000002],a,pr,ul,nr;
long long sp[1000002],smax,s;
#define DIM 10000
char buff[DIM];
int poz=0;
void citire_rapida(int &numar)
{
     numar = 0;
     char semn='+';
     while (buff[poz] < '0' || buff[poz] > '9')
     {
          semn = buff[poz];
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     if (semn == '-')
          numar = -numar;
}
int main(){
    cin>>n>>K>>W;
    sp[0]=0;
    for(int i=1;i<=K;i++){
        ///cin>>a;
        citire_rapida(a);
        sp[i]=sp[i-1]+a;
    }
    ///sp[dq[pr]] este cea mai mica suma anterioara
    ///pentru primele K pozitii valoarea lui q va fi 0
    dq[1]=0;///retinem pozitia 0 in deque
    pr=1;
    ul=1;
    smax=sp[K];///avem primul candidat
    ///incepem prima etapa
    for(int i=K+1;i<=W;i++){
        ///cin>>a;
        citire_rapida(a);
        sp[i]=sp[i-1]+a;
        s=sp[i-K];
        while(pr<=ul && s<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        s=sp[i]-sp[dq[pr]];
        if(s>smax){
            smax=s;
        }
    }
    ///continuam cu etapa a doua
    for(int i=W+1;i<=n;i++){
        ///cin>>a;
        citire_rapida(a);
        sp[i]=sp[i-1]+a;
        s=sp[i-K];
        while(pr<=ul && s<=sp[dq[ul]]){
            ul--;
        }
        dq[++ul]=i-K;
        ///eliminam dq[pr] daca este expirat
        while(i-W>dq[pr]){
            pr++;
        }
        s=sp[i]-sp[dq[pr]];
        if(s>smax){
            smax=s;
        }
    }
    cout<<smax;
    return 0;
}
