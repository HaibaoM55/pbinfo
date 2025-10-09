#include <fstream>
using namespace std;
ifstream  fin("fibonacci3.in");
ofstream fout("fibonacci3.out");
int n,q,nr,x[27];
long long v[27],r=1;
long long f[104];
void submultimi(int k, long long s){
    int ok=0;
    int p1=1,p2=q,p;
    while(p1<=p2){
        p=(p1+p2)/2;
        if(s==f[p]){
            ok=1;
            break;
        }
        if(s<f[p]){
            p2=p-1;
        }
        else{
            p1=p+1;
        }
    }
    if(ok==1){
        nr++;
    }
    for(int i=x[k-1]+1;i<=n;i++){
        x[k]=i;
        submultimi(k+1,s+v[i]);
    }
}

int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    r=25;
    for(int i=1;i<=17;i++){
        r=r*10;
    }
    f[1] = 0;
    f[2] = 1;
    q=2;
    for(q = 3; f[q-1] + f[q-2] <= r; q++){
        f[q] = f[q-1] + f[q-2];
    }

    nr = 0;
    for(int i = 1; i <= n; i++){
        x[1]=i;
        submultimi(2,v[i]);
    }
    fout << nr;
    return 0;
}
