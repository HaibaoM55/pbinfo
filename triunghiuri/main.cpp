#include <iostream>
#include <algorithm>
using namespace std;
int nr=0,v[105],n,m,x;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(v[i]+v[j]>v[k]){
                    nr++;
                }else{
                    break;
                }
            }
        }
    }
    cout<<nr;
}
