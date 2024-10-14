#include <fstream>
using namespace std;
ifstream  fin("countprime.in");
ofstream fout("countprime.out");
int prime[6550],np,k,i,j;
long long st,dr,l,p,a,b;

int main(){
    char ciur[50010]={0};
    prime[1]=2; prime[2]=3; np=2;
    for(i=5;i<=65536;i=i+2){
      int ok=1;
      for(j=1;prime[j]*prime[j]<=i;j++){
        if(i%prime[j]==0){
          ok=0;break;
        }
      }
      if(ok){
          np++; prime[np]=i;
      }
    }
    fin>>st>>dr;
    k=0;
    if(st<2){st=2;}
    for(p=st;p<=dr;p=p+50000){
      a=p;b=a+50000-1;
      for(j=1;j<=np && prime[j]<=b;j++){
        for(l=((long long)(a+prime[j]-1)/prime[j])*prime[j];l<=b && l<=dr;l=l+prime[j]){
          if(l==prime[j])ciur[l-a]=1;
          else ciur[l-a]=2;
        }
      }
      for(l=a;l<=b && l<=dr;l++){
        if(ciur[l-a]<2){
          k++;
        }
          ciur[l-a]=0;
      }
    }
    fout<<k;
    return 0;
}

