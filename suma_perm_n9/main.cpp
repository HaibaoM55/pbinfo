#include <iostream>
using namespace std;
long long a,v[1001],i,j,k,z=1,n,s;
int main(){
    cin>>n;
    i=0;
    do{
        i++;
        v[i]=n%10;
        n=n/10;
    }while(n>0);
    for(j=1;j<i;j++){
        z=z*10+1;
    }
    long long benone = 1;
    for(j=1;j<=i;j++){
        s=s+v[j];
    }
    for(j = 1; j<i; j++){
        benone = benone*j;
    }
    cout<<s*z*benone;
    return 0;
}
