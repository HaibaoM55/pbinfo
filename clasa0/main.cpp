#include <iostream>
#define MOD 1000000007
using namespace std;
int q,a,b,c,prime[200002],np,ex[200002];
char ciur[1000002];
int g(int x, int p){
    int s=0;
    do{
        x=x/p;
        s=s+x;
    }while(x>=p);
    return s;
}

int powlog(int A, int B){
    long long P=1,X=A;
    while(B){
        if(B%2==1){
            P=P*X%MOD;
        }
        X=X*X%MOD;
        B=B/2;
    }
    return P;
}

int main(){
    ciur[0]=1;
    ciur[1]=1;
    np=0;
    for(int i=2;i<=1000000;i++){
        if(ciur[i]==0){
            prime[++np]=i;
            for(int j=i;j<=1000000/i;j++){
                ciur[j*i]=1;
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a>>b>>c;
        if(a==1){
            cout<<1<<"\n";
        }
        else{
            long long r=1;
            for(int j=1;j<=np && prime[j]<=b;j++){
                int ex=g(b,prime[j])-g(c,prime[j])-g(b-c,prime[j]);
                for(int l=1;l<=ex;l++){
                    r=r*prime[j]%(MOD-1);
                }
            }
            int z=powlog(a,r);
            cout<<z<<"\n";
        }
    }
    return 0;
}
