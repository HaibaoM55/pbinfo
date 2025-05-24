#include <iostream>
using namespace std;
int v[1005],k,n,i,j,nr=0,nr1=0,b,a[1005],z,a1,ok,secv1,secv,ok1;
int main(){
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>v[i];
    }
    z=n/k;
    ok1=0;
    for(i=1;i<=k;i++){
        a1=z;
        nr=0;
        do{
            nr++;
            nr1++;
            a[nr]=v[nr1];
            a1--;
        }while(a1>0);
        nr=1;
        secv1=i;
        secv=i;
        for(j=i*z+1;j<=n;j=j+z){
            secv++;
            if(a[nr]==v[j]){
                ok=1;
                for(b=j;b<=j+z-1;b++){
                    if(v[b]!=a[nr]){
                        ok=0;

                        break;
                    }
                    nr++;
                }
                if(ok==1){
                    ok1=1;
                    cout<<secv1<<" "<<secv<<" ";
                }
            }
        }
        if(ok==1){
            break;
        }
    }

    return 0;
}
