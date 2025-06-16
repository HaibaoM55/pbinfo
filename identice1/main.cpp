#include <iostream>

using namespace std;

int a[104],b[104],n,m,x,i,j,ok,k,g,nr=0,nr1;

int main()
{   cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a[i];
    }
    for(k=1;k<=n-1;k++){
        ok=1;

        for(i=1;i<=m;i++){
            cin>>b[i];
        }
        for(i=1;i<=m;i++){
            if(a[i]!=b[i]){

                ok=0;

            }
        }
        if(ok==1){
           nr++;

        }
        for(i=1;i<=m;i++){
            a[i]=b[i];
        }
    }
    cout<<nr;
}
