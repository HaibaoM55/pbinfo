#include <fstream>
#include <algorithm>
using namespace std;
ifstream  fin("aemi.in");
ofstream fout("aemi.out");
int n,Q,v[100003],vmin[400];

int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>v[i];
    }
    int lb=400;
    int m=1+(n-1)/lb;
    ///[1+(k-1)*lb ; k*lb] este a k-a bucata de lungime lb; 1<=k<=m
    ///pentru fiecare bucata k precalculam minimul vmin[k]
    for(int k=1;k<=m;k++){
        vmin[k]=2000000000;
        int a=1+(k-1)*lb;
        int b=min(n,k*lb);
        for(int i=a;i<=b;i++){
            if(v[i]<vmin[k]){
                vmin[k]=v[i];
            }
        }
    }
    fin>>Q;
    for(int q=1;q<=Q;q++){
        int t,x,y;
        fin>>t>>x>>y;
        if(t==2){
            v[x]=y;
            int k=1+(x-1)/lb;
            ///recalculam minimul din bucata a k-a
            vmin[k]=2000000000;
            int a=1+(k-1)*lb;
            int b=min(n,k*lb);
            for(int i=a;i<=b;i++){
                if(v[i]<vmin[k]){
                    vmin[k]=v[i];
                }
            }
        }
        else{
            int tmin=2000000000;
            int kx=1+(x-1)/lb;
            int ky=1+(y-1)/lb;
            if(kx==ky){
                for(int i=x;i<=y;i++){
                    if(v[i]<tmin){
                        tmin=v[i];
                    }
                }
            }
            else{
                int b=min(n,kx*lb);
                for(int i=x;i<=b;i++){
                    if(v[i]<tmin){
                        tmin=v[i];
                    }
                }
                int a=1+(ky-1)*lb;
                for(int i=a;i<=y;i++){
                    if(v[i]<tmin){
                        tmin=v[i];
                    }
                }
                for(int i=kx+1;i<=ky-1;i++){
                    if(vmin[i]<tmin){
                        tmin=vmin[i];
                    }
                }
            }
            fout<<tmin<<"\n";
        }
    }
    fin.close(); fout.close();
    return 0;
}
