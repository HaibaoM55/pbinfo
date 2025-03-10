#include <fstream>
#define NMaX 1002
using namespace std;
ifstream  fin("parking.in");
ofstream fout("parking.out");
int c,n,m,k,q,nr,a[1004][1004];
struct s{
    int x,y;
} d[1000004], v[4004];
bool iese(int poz){
    if(v[poz].x==0)
    {
        for(int i=1; i<=n; i++)
        {
            if(a[i][v[poz].y])
            {
                if(a[i][v[poz].y]==2)
                {
                    a[i][v[poz].y]=-2;
                    nr++;
                    d[nr].x=i;
                    d[nr].y=v[poz].y;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        v[poz].x=1;
    }

    if(v[poz].x==n+1)
    {
        for(int i=n; i>=1; i--)
        {
            if(a[i][v[poz].y])
            {
                if(a[i][v[poz].y]==2)
                {
                    nr++;
                    d[nr].x=i;
                    d[nr].y=v[poz].y;
                    a[i][v[poz].y]=-2;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        v[poz].x=1;
    }

    if(v[poz].y==0)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[v[poz].x][j])
            {
                if(a[v[poz].x][j]==1)
                {
                    nr++;
                    d[nr].x=v[poz].x;
                    d[nr].y=j;
                    a[v[poz].x][j]=-1;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        v[poz].y=1;
    }

    if(v[poz].y==m+1)
    {
        for(int j=m; j>=1; j--)
        {
            if(a[v[poz].x][j])
            {
                if(a[v[poz].x][j]==1)
                {
                    nr++;
                    d[nr].x=v[poz].x;
                    d[nr].y=j;
                    a[v[poz].x][j]=-1;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        v[poz].y=1;
    }

    return 0;
}

int main()
{
    int x,y,p;
    fin>>c>>n>>m>>k>>q;
    for(int i=1; i<=k; i++)
    {
        fin>>v[i].x>>v[i].y;
    }
    for(int i=1; i<=q; i++)
    {
        fin>>x>>y>>p;
        a[x][y]=p+1;
    }
    if(c==1)
    {
        int r=0;
        for(int i=1; i<=k; i++)
        {
            if(iese(i))
            {
                r++;
            }
        }
        fout<< r << "\n";
    }
    if(c==2)
    {
        int nrm=0,nrs=0;
        for(int z = 1; z <= q; z++){
            nr=0;
            for(int i=1; i<=k; i++)
            {
                if(iese(i))
                {
                    nrm++;
                }
            }
            if(!nr)
            {
                break;
            }
            for(int i=1; i<=nr; i++)
            {
                a[d[i].x][d[i].y]=0;
            }
            nrs++;
        }
        fout<< nrm<< " " << nrs<< "\n";
    }
    return 0;
}
