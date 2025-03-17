#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("spirala.in");
ofstream fout("spirala.out");
int n,k;
int di[5]={1,0,-1,0};
int dj[5]={0,-1,0,1};
struct poz{
    int i,j;
} p[1000005];
bool b[1001][1001][10],a[1001][1001][10];
vector<int> t;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            fin>>x;
            do
            {
                int cif=x%10;
                a[i][j][cif]=1;
                x=x/10;
            }while(x);
        }
    }
    int x=n/2+1,y=n/2+1,d=-1,pas=0,l=0;
    while(1)
    {
        if(pas%2==0) l++;
        pas++;
        d++;
        d%=4;
        k++;
        p[k]={x,y};
        int i=x,j=y;
        for(int t=1;t<l;t++)
        {
            i+=di[d];
            j+=dj[d];
            k++;
            p[k]={i,j};
        }
        x+=di[d]*l;
        y+=dj[d]*l;
        if(x==n+1 && y==n) break;
    }
    for(int c=1;c<=9;c++){
        b[n/2+1][n/2+1][c]=1;
        for(int t=2;t<=k;t++){
            int i=p[t].i;
            int j=p[t].j;
            int k=p[t-1].i;
            int l=p[t-1].j;
            if((i+j)%c==0){
                if(b[k][l][c]==0){
                    b[i][j][c]=1;
                }else{
                    b[i][j][c]=0;
                }
            }else{
                if(b[k][l][c]==1){
                    b[i][j][c]=1;
                }else{
                    b[i][j][c]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int digits=0,p=1;
            for(int c=0;c<=9;c++){
                if(a[i][j][c]==b[i][j][c]){
                    digits=digits*10+c;
                }
            }
            t.emplace_back(digits);
        }
    }
    sort(t.begin(),t.end());
    l = t.size();
    int nr = 2000000000;
    for(int i=0;i<l; i++){
        if(t[i]==t[i+1]){
            int j=i;
            while(t[j]==t[j+1] && j< l){
                j++;
            }
            nr=min(nr,max(n*n-j+i-1,0));
            i=j;
        }
    }
    fout<<nr;
    return 0;
}
