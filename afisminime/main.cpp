#include <fstream>
#include <math.h>
using namespace std;
ifstream  fin("afisminime.in");
ofstream fout("afisminime.out");
int n, m, x, y;
int a[20][100002],d[100002];
int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    fin >> n >> m;
    d[0]=0;
    d[1]=0;
    d[2]=1;
    for(int i=3,e=1,p=4;i<=n;i++){
        if(i<p)d[i]=e;
        else{
            ///p==i
            e++;
            p=p*2;
            d[i]=e;
        }
    }

    for(int i=1;i<=n;i++){
        fin>>a[0][i];
    }
    for(int i=1,p=1;p*2<=n;p=p*2,i++){
        for(int j=1;j+2*p-1<=n;j++){
            a[i][j]=min(a[i-1][j],a[i-1][j+p]);
        }
    }
    for(int i=1;i<=m;i++){
        fin>>x>>y;
        if(x>y)swap(x,y);
        int dif=y-x+1;
        int e=d[dif];
        int p=(1<<e);
        int vmin=min(a[e][x],a[e][y-p+1]);
        fout<<vmin<<"\n";
    }
    return 0;
}
