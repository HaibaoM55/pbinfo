#include <iostream>
#include <cmath>
using namespace std;
int n,nr;
double dmax,dist;
struct punct{
    int x,y;
}v[102];
int main(){
    cin>>n;
    dmax=0;
    for(int i=1;i<=n;i++){
        cin>>v[i].x>>v[i].y;
        dist=sqrt(v[i].x*v[i].x+v[i].y*v[i].y);
        if(dist>dmax){
            dmax=dist;
            nr=1;
        }
        else{
            if(fabs(dist-dmax)<=0.0000001){
                nr++;
            }
        }
    }
    cout<<dmax<<" "<<nr;
    return 0;
}
